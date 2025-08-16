#include<iostream>
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
class circularLinkedList{
    node* head;
    node* tail;
    circularLinkedList(){
        head=tail=NULL;
    }
    void insertAtHead(int val){
        node* newNode=new node(val);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
        }else{
            newNode->next=head;
            head=newNode;
            tail->next=head;
        }
    }
    void insertAtTail(int val){
        node* newNode=new node(val);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
        }else{
            newNode->next=head;
            tail->next=newNode;
            tail=newNode;
        }
    }
    void print(){
        if(head==NULL) return;
        cout<<head->data<<"->";
        node* temp=head->next;
        while(temp!=head){
            cout<<head->data<<"->";
        }
    }
    void deleteAtHead(){
        
    }
};