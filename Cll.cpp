#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = this;   // circular
    }
};

/* ---------------- INSERT AT HEAD ---------------- */
void insertathead(int value, Node* &head, Node* &tail) {
    if (head == NULL) {
        Node* newnode = new Node(value);
        head = tail = newnode;
    }
    else {
        Node* newnode = new Node(value);
        newnode->next = head;
        tail->next = newnode;
        head = newnode;
    }
}

/* ---------------- INSERT AT TAIL ---------------- */
void insertattail(int value, Node* &head, Node* &tail) {
    if (head == NULL) {
        Node* newnode = new Node(value);
        head = tail = newnode;
    }
    else {
        Node* newnode = new Node(value);
        newnode->next = head;
        tail->next = newnode;
        tail = newnode;
    }
}

/* ---------------- PRINT ---------------- */
void print(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

/* ---------------- LENGTH ---------------- */
int lengthoflinkedlist(Node* head) {
    if (head == NULL) return 0;

    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

/* ---------------- INSERT AT POSITION ---------------- */
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
    newnode->next = temp->next;
    temp->next = newnode;
}

/* ---------------- DELETE NODE ---------------- */
void deleteNode(int pos, Node* &head, Node* &tail) {
    if (head == NULL) return;

    int len = lengthoflinkedlist(head);
    if (pos < 1 || pos > len) return;

    // only one node
    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    // delete head
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        tail->next = head;
        temp->next = NULL;
        delete temp;
        return;
    }

    Node* prev = head;
    for (int i = 1; i < pos - 1; i++) {
        prev = prev->next;
    }

    Node* curr = prev->next;
    prev->next = curr->next;

    if (curr == tail) {
        tail = prev;
    }

    curr->next = NULL;
    delete curr;
}

/* ---------------- MAIN ---------------- */
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    cout << "---- Insert at head ----" << endl;
    insertathead(10, head, tail);
    print(head);

    insertathead(20, head, tail);
    print(head);

    insertathead(30, head, tail);
    print(head);

    cout << "\n---- Insert at tail ----" << endl;
    insertattail(40, head, tail);
    print(head);

    insertattail(50, head, tail);
    print(head);

    cout << "\n---- Insert at position ----" << endl;
    insertatpos(25, 2, head, tail);
    print(head);

    insertatpos(5, 1, head, tail);
    print(head);

    insertatpos(60, lengthoflinkedlist(head) + 1, head, tail);
    print(head);

    cout << "\n---- Delete head ----" << endl;
    deleteNode(1, head, tail);
    print(head);

    cout << "\n---- Delete tail ----" << endl;
    deleteNode(lengthoflinkedlist(head), head, tail);
    print(head);

    cout << "\n---- Delete middle ----" << endl;
    deleteNode(3, head, tail);
    print(head);

    cout << "\n---- Delete all nodes ----" << endl;
    while (head != NULL) {
        deleteNode(1, head, tail);
        if (head)
            print(head);
        else
            cout << "List empty" << endl;
    }

    return 0;
}
