#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int value){
        this->data=value;
        this->next=NULL;
    }
    ~Node(){
        cout<<"deleting "<<data<<endl;
    }

};
Node * insertHead(int value,Node* &head, Node* &tail){
    if(head==NULL && tail==NULL){
        Node* newnode=new   Node(value);
        head=newnode;
        tail=newnode;

    }
    else{
        Node *newnode=new Node(value);
        newnode->next=head;
        head=newnode;
        }
        
    return head;
};
int main(){
    Node*head=NULL;
    Node *tail=NULL;

    // ll is present 
    // insert at head 
    insertHead(20,head,tail);




    return 0;
}