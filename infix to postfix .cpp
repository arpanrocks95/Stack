#include <stdio.h>
#include <malloc.h>

/*stack program*/
#define MAX 100
class stack{
private:
    int top;
public:
    int  array[MAX];
    stack (){ top = -1 ;}


    int isFull(){
        return top == MAX;
    }
    int peek(){
        return array[top];
    }
    int isEmpty(){
        return top == -1;
    }


    void  push( int data){
        if(isFull()){
            printf("Stack Is Full");
            return;
        }
        top++;
        array[top] = data;

    }

    int pop(){
        if (isEmpty()){
            printf("%s","Stack Is Empty");
        }
        else{
            int temp = array[top];
            array[top] = NULL;
            top--;
            return temp;
        }
    }


};





/* infix to postfix */

int precendece(char ch){
    switch (ch){
        case '+' :
        case '-' : return 1;
        case '*' :
        case '/' : return 2;
        case '^' : return 3;
    }
    return -1;
}

int isOperand(char ch){
    return (ch >= 'a' && ch <= 'z' ) || (ch >= 'A' && ch <= 'Z');
}


int infixToPostfix(char * exp){
    stack s1;
    int i = 0;
    int k = -1;
    for (; exp[i] ; ++i) {
        if (isOperand(exp[i])){
            exp[++k] = exp[i];
        }
        else if(exp[i] == '(' ){
            s1.push(exp[i]);
        }
        else if (exp[i] == ')'){
            while(!s1.isEmpty() && s1.peek() != '('){
                exp[++k] = s1.pop();
            }
            if(!s1.isEmpty() && s1.peek() != '(')
                return -1;
            else{
                s1.pop();
            }
        }
        else{

            while(!s1.isEmpty() && precendece(exp[i]) <= precendece(s1.peek())) {
                exp[++k] = s1.pop();
            }
            s1.push(exp[i]);
        };

    }
    while (!s1.isEmpty()){
        exp[++k] = s1.pop();
    }
    exp[++k] =  '\0';
}

int main(){
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    for (int i = 0; exp[i] != '\0' ; ++i) {
        printf("%c",exp[i]);
    }
    return  0;
}