#include <iostream>
#include <string.h>

using namespace std;

//Node structure
struct node{
    int val;
    node *next;
};

//Stack class
class stack{
    struct node *top;
    public:
    stack(){
        top = NULL;
    }
    void push(int val);
    void pop();
    void show();
};

//Push
void stack::push(int val){
    struct node *ptr;
    ptr = new node;
    ptr->val = val;
    ptr->next = NULL;
    if(top != NULL){
        ptr->next = top;
    }
    top = ptr;
}

//Pop
void stack::pop(){
    struct node *ptr;
    if(top == NULL){
        cout<<"The Stack is empty"<<endl;
    }else{
        ptr = top;
        top = top->next;
        cout<<"Poped value: "<<ptr->val<<endl;
        delete ptr;
    }
}

//Show the stack
void stack::show(){
    struct node *cur;
    cout<<"The stack: "<<endl;
    for(cur = top; cur != NULL; cur = cur->next){
        cout<<cur->val<<"-> ";
    }
    cout<<"NULL"<<endl;
}

int main(){
    stack s;
    char op[8];
    int data;
    cout<<"         Stack Implementation"<<endl;
    cout<<"========================================="<<endl;
    cout<<"Use with these arguments:"<<endl;
    cout<<"push <val>       push the stack with val"<<endl;
    cout<<"pop              pop the stack"<<endl;
    cout<<"quit             quit the program"<<endl;
    while(1){
        cin>>op;
       if(strcmp(op, "push") == 0){
           cin>>data;
           s.push(data);
       }else if(strcmp(op, "pop") == 0){
           s.pop();
       }else if(strcmp(op, "quit") == 0){
           break;
       }
       else{
           cout<<"Please use the correct arguments"<<endl;
       }
       s.show();
    }

    return 0;
}
