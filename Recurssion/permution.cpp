//https://leetcode.com/problems/permutations/submissions/1705043658/
class Solution {
public:
    void ps(vector<int>& nums,int idx,vector<vector<int>>& ans){
        if(idx==nums.size()){
            ans.push_back({nums});
            return;
        }

        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            ps(nums,idx+1,ans);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        ps(nums,0,ans);
        return ans;
    }
};