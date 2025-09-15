//https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        queue<pair<Node*,int>> q;
        map<int,int> m;
        q.push({root,0});
        
        while(q.size()>0){
            Node* curr=q.front().first;
            int currHD=q.front().second;
            q.pop();
            if(m.find(currHD)==m.end()){
                m[currHD]=curr->data;
            }
            if(curr->left!=NULL) q.push({curr->left,currHD-1});
            if(curr->right!=NULL) q.push({curr->right,currHD+1});
        }
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};