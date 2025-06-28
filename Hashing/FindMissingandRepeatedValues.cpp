//https://leetcode.com/problems/find-missing-and-repeated-values/
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int a,b;
        unordered_set<int> s;
        vector<int> ans;
        int actualsum=0,exsum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                actualsum+=grid[i][j];
                if(s.find(grid[i][j])!=s.end()){
                    a=grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        exsum=(n*n)*(n*n+1)/2;
        b=exsum+a-actualsum;
        ans.push_back(b);
        return ans;
    }
};