//https://leetcode.com/problems/subsets-ii/
class Solution {
public:

void ps(vector<int> &arr,vector<int> &ans,int i,vector<vector<int>> &allSubSets){
    if(i==arr.size()){
        allSubSets.push_back({ans});
        return;
    }
    ans.push_back(arr[i]);
    ps(arr,ans,i+1,allSubSets);
…        ps(nums,ans,0,allSubSets);
        return allSubSets;
    }
};