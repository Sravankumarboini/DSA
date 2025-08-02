#include<iostream>
#include<vector>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
node* insert(node*root,int val){
    node* newNode=new node(val);
    if(root==NULL){
        root=newNode;
        return root;
    }
    else if(val>root->data){
        root->right=insert(root->right,val);
    }
    else{
        root->left=insert(root->left,val);
    }
    return root;
}
void inorder(node* head){
    if(head==NULL) return;
    cout<<head->data;
    inorder(head->left);
    inorder(head->right);
}
int maxdepth(node* root){
    if(root==NULL) return 0;
    return 1+max(maxdepth(root->left),maxdepth(root->right));
}
bool check(node* root){
    if(root->left==NULL && root->right==NULL) return true;
    if(root->left==NULL) return check(root->right);
    if(root->right==NULL) return check(root->left);
    if(root->left->data<root->data && root->right->data>root->data){
        return check(root->left);
        return check(root->right);
    }else{
        return false;
    }
}
int main(){
    node* head=NULL;
    vector<int> arr={3,2,1,5,4,6,7};
    head=insert(head,arr[0]);
    for(int i=1;i<arr.size();i++){
        insert(head,arr[i]);
    }
    inorder(head);
    cout<<endl;
    int d=maxdepth(head);
    cout<<"max height of binary tree: "<<d-1;
    bool temp=check(head);
    cout<<temp;
}