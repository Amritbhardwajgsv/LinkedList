#include<iostream>
using namespace std;
class Node{
public:
int data;
Node *prev;
Node *next;
Node(int value){
data=value;
next=this;
prev=this;
}
};
void insertathead(int value,Node* &head ,Node* &tail){
    if(head==NULL && tail==NULL){
        Node *newnode =new Node(value);
        head=newnode;
        tail=newnode;
            newnode->next = newnode;
    newnode->prev = newnode;
    }
    else if (head==tail){
         Node *newnode =new Node(value);
        newnode->next=head;
         head->prev=newnode;
         head->next=newnode;
         newnode->prev=head;
         head=newnode;
    }
    else{
        Node *newnode=new Node(value);
        head->prev=newnode;
        newnode->next=head;
        tail->next=newnode;
        newnode->prev=tail;
        head=newnode;

    }
};
void print(Node* head){
    Node *temp=head;
    // while(temp!=head){
    //     cout<<temp->data<<"->";
    //     temp=temp->next;
    // }
    // this is a classical mistake 
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    while(temp!=head);
    cout<<endl;


};
void insertattail(int value,Node* &head,Node* &tail){
    if(head==NULL && tail==NULL){
        Node* newnode=new Node(value);
        head=newnode;
        tail=newnode;
        newnode->next = newnode;
    newnode->prev = newnode;

    }
    else if (head==tail){
        Node* newnode= new Node(value);
           
        tail->next = newnode;
        newnode->prev = tail;

        newnode->next = tail;
        tail->prev = newnode;

        tail = newnode;
        
    }
    else{
        Node* newnode=new Node(value);
        tail->next=newnode;
        newnode->prev=tail;
        newnode->next=head;
        head->prev=newnode;
        tail=newnode;
    }
};
int lengthoflinkedlist(Node* head){
    int count=0;
    Node *temp=head;
do{temp=temp->next;
    count++;

}
while(temp!=head);
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
void deleteNode(int pos, Node* &head, Node* &tail) {

    if (head == NULL) return;   // empty list

    int len = lengthoflinkedlist(head);
    if (pos < 1 || pos > len) return;

    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;

        head->prev = tail;
        tail->next = head;

        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    if (pos == len) {
        Node* temp = tail;
        tail = tail->prev;

        tail->next = head;
        head->prev = tail;

        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

  
    Node* curr = head;
    for (int i = 1; i < pos; i++) {
        curr = curr->next;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
};
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    cout << "---- Insert at head ----" << endl;
    insertathead(10, head, tail);
    print(head);   // 10

    insertathead(20, head, tail);
    print(head);   // 20->10

    insertathead(30, head, tail);
    print(head);   // 30->20->10

    cout << "\n---- Insert at tail ----" << endl;
    insertattail(40, head, tail);
    print(head);   // 30->20->10->40

    insertattail(50, head, tail);
    print(head);   // 30->20->10->40->50

    cout << "\n---- Insert at position ----" << endl;
    insertatpos(25, 2, head, tail);
    print(head);   // 30->25->20->10->40->50

    insertatpos(5, 1, head, tail);
    print(head);   // 5->30->25->20->10->40->50

    insertatpos(60, lengthoflinkedlist(head) + 1, head, tail);
    print(head);   // 5->30->25->20->10->40->50->60

    cout << "\n---- Delete head ----" << endl;
    deleteNode(1, head, tail);
    print(head);   // 30->25->20->10->40->50->60

    cout << "\n---- Delete tail ----" << endl;
    deleteNode(lengthoflinkedlist(head), head, tail);
    print(head);   // 30->25->20->10->40->50

    cout << "\n---- Delete middle ----" << endl;
    deleteNode(3, head, tail);
    print(head);   // 30->25->10->40->50

    cout << "\n---- Delete all nodes one by one ----" << endl;
    while (head != NULL) {
        deleteNode(1, head, tail);
        if (head)
            print(head);
        else
            cout << "List empty" << endl;
    }

    return 0;
}
