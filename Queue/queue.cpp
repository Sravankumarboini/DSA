#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
class queue{
    node* head;
    node* tail;
    public:
    queue(){
        head=NULL;
        tail=NULL;
    }

    void push(int val){
        node *newNode=new node(val);
        if(empty()){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void pop(){
        if(empty()){
            cout<<"queue is empty";
            return;
        }
        node* temp=head;
        head=head->next;
        delete temp;
    }

    int front(){
        return head->data;
    }

    bool empty(){
        return head==NULL;
    }
};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    cout<<"front :"<<q.front()<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    } 
}