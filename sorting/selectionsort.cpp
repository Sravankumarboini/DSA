vector<int> selectionSort(vector<int>& nums) {
        int n = nums.size();
        for (int j = n - 1; j >= 0; j--) {
            int maxIdx = 0;
            for (int i = 1; i <= j; i++) {
                if (nums[i] > nums[maxIdx]) {
                    maxIdx = i;
                }  
            }
            swap(nums[maxIdx], nums[j]);
        }
        return nums;
    }
};
