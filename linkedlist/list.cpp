#include<iostream>
#include<list>
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
class linkedlist{
    node* head;
    node* tail;
public:
    linkedlist(){
        head=NULL;
        tail=NULL;
    }
    void push_front(int val){
        node* newNode=new node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }
    void push_back(int val){
        node* newNode=new node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    linkedlist ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_front(40);
    ll.display();
    ll.push_back(50);
    ll.display();
}