//https://leetcode.com/problems/subarray-sum-equals-k/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ps(n,0);
        ps[0]=nums[0];
        for(int i=1;i<n;i++){
            ps[i]=ps[i-1]+nums[i];
        }
        int cnt=0;
        unordered_map<int,int> m;
        for(int j=0;j<n;j++){
            if(ps[j]==k) cnt++;
            int val=ps[j]-k;
            if(m.find(val)!=m.end()) cnt+=m[val];
            if(m.find(ps[j])==m.end()) m[ps[j]]=0;
            m[ps[j]]++;
        }
        return cnt;
    }
};