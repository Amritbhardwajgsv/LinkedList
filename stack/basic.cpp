#include<iostream>
using namespace std;

class Stacks {
public:
    int *arr;
    int top;
    int size;

    Stacks(int capacity) {
        size = capacity;
        arr = new int[size];
        top = -1;
    }

    ~Stacks() {
        delete[] arr;
    }

    void push(int value) {
        if (top == size - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    void gettop() {
        if (top == -1) {
            cout << "Stack is empty\n";
        } else {
            cout << arr[top] << endl;
        }
    }

    void print() {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void getsize(){
        // agar ek element hai to array me to top+1 hi result dega 
        cout<<top+1<<endl;
    }
};

int main() {
    Stacks S(5);

    S.push(5);
    S.push(10);
    S.push(15);

    S.print();   
    S.getsize();
    S.pop();
    S.print();   

    S.gettop();  

    return 0;
}
