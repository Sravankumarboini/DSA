class Solution {
public:
    vector<int> insertionSort(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int j=i;
            while(j>0&& nums[j]<nums[j-1]){
                swap(nums[j],nums[j-1]);
                j--;
            }
        }
        return nums;
    }
};
