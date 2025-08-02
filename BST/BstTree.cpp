#include<iostream>
#include<list>
using namespace std;
class node{
public:
    int data;
    node* left,*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
class BstTree{
public:
    node* insert(node* root,int val){
        node* newNode=new node(val);
        if(root==NULL){
            root=newNode;
            return root;
        }
        else if(root->data<val){
           root->right=insert(root->right,val);
        }
        else{
            root->left=insert(root->left,val);
        }
        return root;
    }
    void display(node* head){
            if(head==nullptr) return;
            display(head->left);
            cout<<head->data<<" "; 
            display(head->right);
    }
    int cnt=0;
    node* ans=nullptr;
    node *kthsmall(node* root,int val,node* r){
        if(root==r) cnt=0;
        if(root==NULL) return NULL;
        kthsmall(root->left,val,r);
        cnt++;
        if(cnt==val) {
            ans=root;
        }
        kthsmall(root->right,val,r);
        return ans;
    }
    node* inorderSuccessor(node* root){
        while(root!=NULL && root->left!=NULL)
            root=root->left;
        return root;
    }
    node* delnode(node* root,int key){
        if(root==NULL) return NULL;
        if(key<root->data){
            root->left=delnode(root->left,key);
        }
        else if(key>root->right){
            root->right=delnode(root->right,key);
        }
        else{
            if(root->left==NULL){
                node* temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                node* temp=root->left;
                delete root;
                return temp;
            }
            else{//2 children
                node* IS=inorderSuccessor(root->right);
                root->data=IS->data;
                root->right=delnode(root->right,IS->data);
            }
        }
    }
    node* search(node* head,int val){
        if(head==NULL) return NULL;
        else if(head->data==val) return head;
        else if(val>head->data) return search(head->right,val);
        else return search(head->left,val);
    }
};
int main(){
    BstTree bst;
    node* head=NULL;
    head=bst.insert(head,10);
    bst.insert(head,50);
    bst.insert(head,20);
    bst.insert(head,9);
    bst.display(head);
    cout<<endl;
    node* ele=bst.search(head,20);
    cout<<ele<<endl;

    node* k=bst.kthsmall(head,3,head);
    cout<<"kth small:"<<k->data<<endl;
    node* k1=bst.kthsmall(head,2,head);
    cout<<"kth small:"<<k1->data;
}