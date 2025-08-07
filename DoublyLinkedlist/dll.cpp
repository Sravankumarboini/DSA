#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        prev=next=NULL;
    }
};
class DoublyLinkedlist{
    node* head;
    node* tail;
public:
    DoublyLinkedlist(){
        head=tail=NULL;
    }
    void push_front(int val){
        node* newNode=new node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }
    void push_back(int val){
        node* newNode=new node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void pop_front(){
        node* temp=head;
        head=head->next;
        if(head!=NULL)
            head->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
    void pop_back(){
        node* temp=tail;
        tail=tail->prev;
        if(tail!=NULL)
            tail->next=NULL;
        temp->prev=NULL;
        delete temp;
    }
};
int main(){
    DoublyLinkedlist dll;
    dll.push_front(2);
    dll.push_front(1);
    dll.push_back(3);
    dll.display();
    dll.pop_front();
    dll.display();
    dll.pop_back();
    dll.display();
}