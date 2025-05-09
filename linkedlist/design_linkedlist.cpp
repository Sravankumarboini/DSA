class node{
    public:
    int val;
    node* next;
    node(int x):val(x),next(nullptr){}
};

class MyLinkedList {
public:
    node* head;
    int size;
    MyLinkedList() {
        head=NULL;
        size=0;
    }
    
    int get(int index) {
        if(index<0 || index>=size){
            return -1;
        }
        node* temp=head;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        node* newNode=new node(val);
        if(head==NULL){
            head=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
        size++;
    }
    
    void addAtTail(int val) {
        node* newNode=new node(val);
        if(head==NULL){
            head=newNode;
        }
        else{
            node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size){
            return;
        }
        else if(index==0){
            addAtHead(val);
            return;
        }
        else if(index==size){
            addAtTail(val);
            return;
        }
        node* temp=head;
        for(int i=0;i!=(index-1);i++){
            temp=temp->next;
     }
     node* newNode=new node(val);
     newNode->next=temp->next;
     temp->next=newNode;
     size++;
    }
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        if(head==NULL)
            return;
        node* temp =head;
        node* temp2;
        if(index==0){
            head=head->next;
           delete temp;
           size--;
           return;
        }
        else if(index==size-1){
            temp=head;
            while(temp->next!=NULL){
                temp2=temp;
                temp=temp->next;
            }
            temp2->next=NULL;
            delete temp;
            size--;
            return;
        }
       else{ for(int i=0;i!=index;i++){
            temp2=temp;
            temp=temp->next;
        }
        temp2->next=temp->next;
        delete temp;
    }
    size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */