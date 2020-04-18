#include <iostream>
using namespace std;
/* here is a program ij which two stacks are implemented in an optimised way for example if we divide an array into two part of each 3 and  3
 * and only push data into stack 1 then it will only store 3  elemts and show overflow of stack ,but here it can store upto size of array if stack 2 is empty*/
class twoStack{
    int *arr;
    int size;
    int top1,top2;

    public:
        twoStack(int n ){
            size = n;
            arr = new int[n];
            top1 = -1;
            top2 = size;
        }
/* methods for stack implementation */
        void push1(int data){
            if(top1 < top2-1){
                top1++;
                arr[top1] = data;
            }
            else{
                cout << "Stack Overflow";
            }
        }


        void push2(int data) {
            if ( top1 + 1 < top2 ) {
                top2--;
                arr[top2] = data;
            }
            else {
                cout << "Stack Overflow";
            }
        }


        int pop1 (){
            if(top1 >= 0 ){
                int x = arr[top1];
                top1--;
                return x;
            }
            else{
                cout<<"Stack Underflow";
            }
            return 0;
        }


        int pop2 (){
            if(top2 < size){
                int x = arr[top2];
                top2++;
                return x;
            }
            else{
                cout<<"Stack Underflow";
            }
            return 0;
        }

};

int main(){
    twoStack st(10);
    st.push1(5);
    st.push2(10);
    cout << st.pop1() <<"\n";
    cout << st.pop2() <<"\n";
    return 0;
}