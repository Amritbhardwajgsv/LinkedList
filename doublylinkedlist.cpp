#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int value){
        data=value;
        next=NULL;
        prev=NULL;
    }
};
void insertathead(int value, Node* &head , Node* &tail){
    if(head==NULL && tail==NULL){
        Node *newnode=new Node(value);
        head=newnode;
        tail=newnode;

    }
    else{
        Node *newnode=new Node(value);
        newnode->next=head;
        head->prev=newnode;
        newnode->prev=NULL;
        head=newnode;
    }
};
void print(Node *&head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}


int main(){
    Node *head=NULL;
    Node *tail=NULL;
    insertathead(10,head,tail);
    print(head);

    insertathead(20,head,tail);
    print(head);



}