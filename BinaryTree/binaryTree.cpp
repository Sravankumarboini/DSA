#include<iostream>
#include<vector>
#include<queue>
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

void inorder(node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        node* cur=q.front();
        q.pop();
        if(cur==NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }

        cout<<cur->data<<" ";
        if(cur->left!=NULL) 
        q.push(cur->left);
        if(cur->right!=NULL)
        q.push(cur->right);
    }
}
int main(){
    vector<int> preord={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node* root=buildTree(preord);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<"levelorder:"<<endl;
    levelorder(root);
}