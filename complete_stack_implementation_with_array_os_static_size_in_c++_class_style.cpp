#include <stdio.h>
#include <malloc.h>
#define MAX 100
class stack{
private:
    int top;
public:

    int  array[MAX];
    stack (){ capacity = -1 ;}
    int capacity ;
    void  push( int data){
        if(isFull()){
            printf("Stack Is Full");
            return;
        }
        top++;
        array[top] = data;

    }

    void pop(){
        if (isEmpty()){
            printf("%s","Stack Is Empty");
        }
        else{
            array[top] = NULL;
            top--;
        }
    }


    int isFull(){
        return top == capacity;
    }
    void peek(){
        printf("data at top is %d \n", array[top]);
    }
    int isEmpty(){
        return top == -1;
    }
};

int main()
{
    stack MyStack ;
    MyStack.push(10);
    MyStack.push(11);
    MyStack.push(12);
    MyStack.push(13);
    MyStack.peek();
    MyStack.pop();
    MyStack.peek();
    return 0;
}


