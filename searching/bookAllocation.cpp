class Solution {
public:
    bool isvalid(vector<int> &arr,int m,int mid){
        int n=arr.size(),stu=1,pages=0;
        for(int i=0;i<n;i++){
            if(arr[i]>mid) return false;
            if(pages+arr[i]<=mid){
                pages+=arr[i];
            }
            else{
                stu++;
                pages=arr[i];
            }
        }
        if(stu>m) return false;
        else return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        int st=0,end=sum,ans=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(isvalid(nums,k,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return ans;
    }
};