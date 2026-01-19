#include<iostream>
using namespace std;
class Stacks{
    public:
    int *arr;
    int top1;//  for stack 1 
    int top2;// for stack 2
    int size;
    Stacks(int capacity){
        size=capacity;
       arr=new int[size];
       top1=size;
       top2=-1;
    }

    ~Stacks(){
        delete[] arr;
    }
    void pushstack1(int value){
        if(top1-top2!=1){
             top1--;
            arr[top1]=value;
           
        }
        else{
            cout<<"stack 1 overflowed";
        }
        
    }
    void pushstack2(int value){
        if(top1-top2!=1){
              top2++;
            arr[top2]=value;
          

        }
        else{
            cout<<"stack2 overflowed";
        }
    }
    void printArray() {
        for(int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }


};
int main(){
    // test benches 
    Stacks s(4);
    s.pushstack2(1); // Index 0
    s.pushstack2(2); // Index 1
    s.pushstack1(9); // Index 3
    s.pushstack1(8); // Index 2
    s.printArray();
    
    // s.pushstack1(5); // Should trigger overflow
    

    return 0;
}