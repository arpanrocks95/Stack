#include <stdio.h>

class queue{
    int *arr ;

public:
    int front = 0;
    int rear = -1;
    int size ;
    /*constructor */
    explicit queue(int size ){
        this->size = size;
        arr = new int[size];
    }
    queue(){
        this->size = 100;
        arr = new int[size];
    }
    void enQueue(int data){
        if (rear < size - 1){
            rear++;
            arr[rear] = data;
        }
        else{
            printf("%s","queue is full");
        }
    }
    int deQueue(){
        if (rear == -1){
            printf("%s","queue is empty");
        }
        else{
            int temp = front;
            front++;
            if (front > rear){
                front =  rear = -1;
            }
            return arr[temp];
        }
    }
    void display(){
        if (rear == -1){
            printf("%s","queue is empty");
        }
        int count =1;
        for (int i = front; i <= rear ; ++i) {
            printf("data in %d container is %d\n",count,arr[i]);
            count++;
        }
    }
};

class stackFromQueue {
    queue q1;
    int top = -1;
public:
    void push(int data){
        q1.enQueue(data);
        top++;
    }
    void pop(){
        queue q2;
        for (int i = 0; i < top; ++i) {
            q2.enQueue(q1.deQueue());
        }
        q1 = q2;
        top--;
    }
    void peek(){
        q1.display();
    }
};

int main(){
    stackFromQueue s1;
    s1.push(10);
    s1.push(11);
    s1.push(12);
    s1.push(13);
    s1.peek();
    s1.pop();
    s1.peek();

    return  0;
}