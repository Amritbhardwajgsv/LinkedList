#include <iostream>
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

    int gettop() {
        if (top == -1) {
            return -1; 
        }
        return arr[top];
    }

    int getsize() {
        return top + 1;
    }

    void print() {
        if (top == -1) {
            cout << "Stack is empty";
        } else {
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

/**
 * Recursive function to find the middle element
 * S: Reference to the stack
 * totalSize: The size of the stack when the search started
 */
int findMiddle(Stacks &S, int totalSize) {
    // Base Case: When the current size of the stack matches the middle position
    // For size 5: (5/2)+1 = 3rd element.
    // For size 4: (4/2)+1 = 3rd element.
    if (S.getsize() == (totalSize / 2) + 1) {
        return S.gettop();
    }

    // 1. Store the top element in the current function call (stack frame)
    int temp = S.gettop();
    
    // 2. Remove the element temporarily
    S.pop();

    // 3. Recursive call to move towards the middle
    int middleValue = findMiddle(S, totalSize);

    // 4. Backtracking: Put the stored element back to restore the stack
    S.push(temp);

    // 5. Return the middle value found at the base case
    return middleValue;
}

int main() {
    // Initialize stack with capacity 10
    Stacks S(10);

    // Pushing elements: 10, 20, 30, 40, 50
    S.push(10);
    S.push(20);
    S.push(30); // This is the middle (3rd element)
    S.push(40);
    S.push(50);

    cout << "Current Stack: ";
    S.print();

    int n = S.getsize();
    if (n > 0) {
        int mid = findMiddle(S, n);
        cout << "The middle element is: " << mid << endl;
    } else {
        cout << "Stack is empty, no middle element." << endl;
    }

    cout << "Stack after finding middle (restored): ";
    S.print();

    return 0;
}