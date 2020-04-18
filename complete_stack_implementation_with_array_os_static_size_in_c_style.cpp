#include <stdio.h>
#include <malloc.h>

struct stack{
    int top;
    int capacity;
    int * array;
};

struct stack * createStack(int capacity);
void  push(struct stack * MyStack , int data);
int isFull(struct stack * MyStack);
int isEmpty(struct stack * MyStack);
void peek(struct stack * MyStack);
void pop(struct stack * MyStack);
int main()
{
    struct stack * MyStack = createStack(10);
    push(MyStack,10);
    push(MyStack,11);
    push(MyStack,13);
    peek(MyStack);
    pop(MyStack);
    peek(MyStack);
    return 0;
}
struct stack * createStack(int capacity){
    struct stack * MyStack = (struct stack *)malloc(sizeof(struct stack));
    MyStack->top = -1;
    MyStack->capacity = capacity;
    MyStack->array = (int *)malloc(MyStack->capacity * sizeof(int));
}
void  push(struct stack * MyStack , int data){
    if(isFull(MyStack)){
        printf("Stack Is Full");
        return;
    }
    MyStack->top++;
    MyStack->array[MyStack->top] = data;

}

void pop(struct stack * MyStack){
    if (isEmpty(MyStack)){
        printf("%s","Stack Is Empty");
    }
    else{
        MyStack->array[MyStack->top] = NULL;
        MyStack->top--;
    }
}


int isFull(struct stack * MyStack){
    return MyStack->top == MyStack->capacity;
}
void peek(struct stack * MyStack){
    printf("data at top is %d \n", MyStack->array[MyStack->top]);
}
int isEmpty(struct stack * MyStack){
    return MyStack->top == -1;
}