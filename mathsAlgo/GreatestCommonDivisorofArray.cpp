//https://leetcode.com/problems/find-greatest-common-divisor-of-array/
class Solution {
public:
    int gcd(int a,int b){
        while(a>0 && b>0){
            if(a>b) a=a%b;
            else b=b%a;
        }
        if(a==0) return b;
        else return a;
    }
    int findGCD(vector<int>& nums) {
        int min=*min_element(nums.begin(),nums.end());
        int max=*max_element(nums.begin(),nums.end());
        return gcd(min,max);
    }
};