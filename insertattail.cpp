#include<iostream>
using namespace std;
class Node{
    public:
    int data ;
    Node *next;
    // constructor()
    Node(int value){
        this->data=value;
        this->next=NULL;
    }
 // no need delete key work se ho jaayega 
};
// insert at tail function 
void insertattail(int value, Node* &head , Node* &tail){
    if(head==NULL && tail==NULL ){
        Node *newnode =new Node(value);
        head=newnode;
        tail=newnode;
    }
    else{
Node *newnode=new Node(value);
tail->next=newnode;
tail=newnode;

}

}
void print(Node *head){
    // for this 
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;

    }
    cout<<endl;

}
int main(){
 Node *head=NULL;
 Node *tail=NULL;
  
insertattail(20,head,tail);
print(head);
insertattail(30,head,tail);
print(head);


}