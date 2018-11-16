#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head;

void Print(){
    Node *temp=head;
    cout<<"List is: ";
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
}

void Insert(int data,int n){
    Node *temp1=new Node;
    temp1->data=data;
    temp1->next= NULL;
    if(n==1){
        temp1->next=head;
        head=temp1;
        return;
    }
    Node *temp2=head;
    for(int i=0;i<n-2;i+=1){
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}

void Delete(int n){
    Node *temp1=head;
    if(n==1){
        head=temp1->next;
        delete(temp1);
        return;
    }
    for(int i=0;i<n-2;i++){
        temp1=temp1->next;
    }
    Node *temp2=temp1->next;
    temp1->next=temp2->next;
    delete(temp2);
};

void Reverse(){
    Node *current,*prev,*next;
    current=head;
    prev=NULL;
    while(current != NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}

int main() {
    head=NULL;
    int length;
    cout<<"How many numbers: ";
    cin>>length;
    for(int i=0;i<length;i+=1){
        int num;
        int position;
        cout<<"Enter the number: ";
        cin>>num;
        cout<<"Enter the position: ";
        cin>>position;
        Insert(num,position);
    }
    Print();

    string y;
    cout<<"Enter 'y' to delete items or 'r' to reverse list: ";
    cin>>y;
    if (y=="y"){
        for(int i=0;i<length;i+=1){
            int position;
            cout<<"Enter position: ";
            cin>>position;
            Delete(position);
            Print();
        }
    }
    else if (y=="r"){
        Reverse();
        Print();
    }
    return 0;




    // Insert(2,1);
    // Insert(3,2);
    // Insert(4,1);
    // Insert(5,2);
    // Print();
    // cout<<"Enter how many numbers? ";
    // int n;
    // cout<<endl;
    // cin>>n;
    // for(int i=0;i<n;i+=1){
    //     int x;
    //     cout<<"Enter the number: ";
    //     cin>>x;
    //     Insert(x);
    //     Print();
    // }
    // return 0;
}

// int main(){
//     cout<<"Hello World";
//     return 0;
// }