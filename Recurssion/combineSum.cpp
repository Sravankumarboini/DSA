//https://leetcode.com/problems/combination-sum/
class Solution {
public:
    set<vector<int>> s;
    void cs(vector<int>& arr,int i,vector<int>& comb,vector<vector<int>>& ans,int tar){
        if(i==arr.size() || tar<0) return;
        if(tar==0){
            if(s.find(comb)==s.end()){
                s.insert(comb);
            ans.push_back(comb);
            }
            return;
        }
        comb.push_back(arr[i]);
        //single include
        cs(arr,i+1,comb,ans,tar-arr[i]);
        //multiple include
        cs(arr,i,comb,ans,tar-arr[i]);
        //exclude
        comb.pop_back();
        cs(arr,i+1,comb,ans,tar);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> ans;
        cs(candidates,0,comb,ans,target);
        return ans;
    }
};