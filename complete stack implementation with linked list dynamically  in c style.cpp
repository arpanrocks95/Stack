#include <stdio.h>
#include <malloc.h>

struct stackNode{
    int data;
    struct stackNode * next;
};
struct stackNode * top = NULL;
void  push(struct stackNode ** top , int data);
void peek(struct stackNode ** top);
void pop(struct stackNode ** top);
int main()
{

    push(&top,10);
    push(&top,11);
    push(&top,13);
    peek(&top);
    pop(&top);
    peek(&top);
    return 0;
}

void  push(struct stackNode ** top , int data){
    struct stackNode * tempNode = (struct stackNode *)malloc(sizeof(struct stackNode));
    tempNode->data = data;
    tempNode->next = *top;
    *top = tempNode;
}

void pop(struct stackNode ** top){
    if (!top){
        printf("%s","Stack Is Empty");
    }
    else{
        struct stackNode * tempNode = *top;
        *top = (*top)->next;
        printf("%d is popped succesfully\n",(tempNode)->data);
        free(tempNode);
    }
}

void peek(struct stackNode ** top){
    printf("data at top is %d \n",(*top)->data);
}
