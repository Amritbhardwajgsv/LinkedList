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

};
void printreverse(Node* &tail){
    Node *temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->prev;
    }
    cout<<endl;
};
void insertattail(int value, Node* &head , Node* &tail){
 if(head==NULL && tail==NULL){
        Node *newnode=new Node(value);
        head=newnode;
        tail=newnode;

    }
    else{
          Node *newnode=new Node(value);
          tail->next=newnode;
          newnode->prev=tail;
          newnode->next=NULL;
          tail=newnode;

    }
};
int lengthoflinkedlist(Node* &head){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
       temp=temp->next;
       count++;
    }
    return count;

}
void insertatpos(int value, int pos, Node* &head, Node* &tail) {
    int len = lengthoflinkedlist(head);
    if (pos < 1 || pos > len + 1) {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1) {
        insertathead(value, head, tail);
        return;
    }
    if (pos == len + 1) {
        insertattail(value, head, tail);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    Node* newnode = new Node(value);
    Node* forward = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = forward;
    forward->prev = newnode;
};
void deleteatpos(int pos, Node* &head, Node* &tail) {
    int len = lengthoflinkedlist(head);

    // invalid position
    if (pos < 1 || pos > len) {
        cout << "Invalid deletion" << endl;
        return;
    }

    // empty list
    if (head == NULL) {
        cout << "Nothing to delete" << endl;
        return;
    }

    // single node
    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    // delete head
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    // delete tail
    if (pos == len) {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    
    Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    Node* current = temp->next;
    Node* forward = current->next;

    temp->next = forward;
    forward->prev = temp;

    current->next = NULL;
    current->prev = NULL;
    delete current;
}




int main(){
    Node *head=NULL;
    Node *tail=NULL;
    insertathead(10,head,tail);
    print(head);

    insertathead(20,head,tail);
    print(head);
        insertathead(20,head,tail);
        print(head);
        insertathead(30,head,tail);
        print(head);
        insertathead(40,head,tail);
        print(head);
     printreverse(tail);
     insertattail(44,head,tail);
     print(head);
     insertatpos(56,2,head,tail);
     print(head);
     deleteatpos(2,head,tail);
     print(head);
        
        





}