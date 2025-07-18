//https://leetcode.com/problems/subsets/
class Solution {
public:
    void allSubsets(vector<int> arr,vector<int> &ans,int i,vector<vector<int>> &subs){
        if(i==arr.size()){
            subs.push_back({ans});
            return;
        }
        //include
        ans.push_back(arr[i]);
        allSubsets(arr,ans,i+1,subs);
        //exclude
        ans.pop_back();
        allSubsets(arr,ans,i+1,subs);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> ans;
        allSubsets(nums,ans,0,subs);
        return subs;
    }
};