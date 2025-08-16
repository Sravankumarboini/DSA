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
class circularLinkedList{
    node* head;
    node* tail;
    public:
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
        if(head==NULL) return;
        else if(head==tail){
            delete head;
            head=tail=NULL;
        }else{
            node* temp=head;
            head=head->next;
            tail->next=head;
            temp->next=NULL;
            delete temp;
        }
    }
    void deleteAtTail(){
        if(head==NULL) return;
        else if(head==tail){
            delete head;
            head=tail=NULL;
        }else{
            node* temp=tail;
            node* prev=head;
            while(prev->next!=tail){
                prev=prev->next;
            }
            tail=prev;
            tail->next=head;
            temp->next=NULL;
            delete temp;
        }
    }
};
int main(){
    circularLinkedList cll;
    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtTail(3);
}