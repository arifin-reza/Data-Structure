#include <iostream>
#include <string.h>

using namespace std;

//Node structure
struct node{
    int val;
    node *next;
};

//Queue class
class queue{
    struct node *front;
    struct node *rear;

    public:
    queue();
    void enqueue(int val);
    void dequeue();
    void show();
};

//Queue
queue::queue(){
    front = NULL;
    rear = NULL;
}

//Enqueue
void queue::enqueue(int val){
    struct node *ptr;
    ptr = new node;
    ptr->val = val;
    ptr->next = NULL;
    if(front == NULL){
        front = ptr;
    }else{
        rear->next = ptr;
    }
    rear = ptr;
}

//Dequeue
void queue::dequeue(){
    struct node *ptr;
    if(front == NULL){
        cout<<"The queue is empty"<<endl;
    }else{
        ptr = front;
        front = front->next;
        cout<<"Dequeued value is: "<<ptr->val<<endl;
        delete ptr;
    }
}

//Show the queue
void queue::show(){
    struct node *cur;
    cout<<"The queue: "<<endl;
    cout<<"Front <-";
    for(cur = front; cur != NULL; cur = cur->next){
        cout<<cur->val<<" <-";
    }
    cout<<"Rear"<<endl;
}

int main(){
    queue q;
    char op[8];
    int data;
    cout<<"         Queue Implementation"<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Use with these arguments:"<<endl;
    cout<<"enq <val>            enqueue val to queue"<<endl;
    cout<<"deq                  dequeue front item"<<endl;
    cout<<"quit                 quit the program"<<endl;
    while(1){
        cin>>op;
        if(strcmp(op, "enq") == 0){
            cin>>data;
            q.enqueue(data);
        }else if(strcmp(op, "deq") == 0){
            q.dequeue();
        }else if(strcmp(op, "quit") == 0){
            break;
        }else{
            cout<<"Please use the correct arguments"<<endl;
        }
        q.show();
    }

    return 0;
}
