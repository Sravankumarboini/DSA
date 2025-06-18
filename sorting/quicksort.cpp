class Solution {
public:
    vector<int> quickSort(vector<int>& nums) {
        qs(nums,0,nums.size()-1);
        return nums;
    }
    void qs(vector<int> &arr,int low,int high){
        if(low<high){
            int partition=f(arr,low,high);
            qs(arr,low,partition-1);
            qs(arr,partition+1,high);
        }
    }
    int f(vector<int> &arr,int low,int high){
        int pivot=arr[low];
        int i=low,j=high;
        while(i<j){
            while(i<=high-1 && arr[i]<=pivot) i++;
            while(j>=low+1 && arr[j]>pivot) j--;
            if(i<j) swap(arr[i],arr[j]);
        }
        swap(arr[low],arr[j]);
        return j;
    }
};
