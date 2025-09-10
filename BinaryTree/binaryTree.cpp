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
        left=right=NULL;
    }
};
static int idx=-1;
node* buildTree(vector<int> preorder){
    idx++;
    if(preorder[idx]==-1) return NULL;
    node* root=new node(preorder[idx]);
    root->left=buildTree(preorder);//left
    root->right=buildTree(preorder);//right
    return root;
}

void preorder(node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    vector<int> preord={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node* root=buildTree(preord);
    preorder(root);
    cout<<endl;
}