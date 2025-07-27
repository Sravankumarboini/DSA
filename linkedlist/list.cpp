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
    void insert(int val,int pos){
        if(pos<0) {
            cout<<"invalid pos";
            return;
        }
        if(pos==0){
            push_front(val);
            return;
        }
        node* temp=head;
        for(int i=0;i<pos-1;i++){
            if(temp==NULL){
                cout<<"invalid pos";
                return;
            }
            temp=temp->next;
        }
        node* newNode=new node(val);
        newNode->next=temp->next;
        temp->next=newNode;
    }
    void pop_front(){
        if(head==NULL) return;
        else{
            node* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
    }
    void pop_back(){
        if(head==NULL){
            cout<<"ll is empty";
            return;
        }
        else{
            node* temp=head;
            while(temp->next!=tail) temp=temp->next;
            temp->next=NULL;
            delete tail;
            tail=temp;
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
    int search(int key){
        node* temp=head;
        for(int i=0;temp!=NULL;i++){
            if(temp->data==key) return i;
            temp=temp->next;
        }
        return -1;
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
    ll.pop_front();
    ll.display();
    ll.pop_back();
    ll.display();
    ll.insert(55,3);
    ll.display();
    cout<<ll.search(55);
}