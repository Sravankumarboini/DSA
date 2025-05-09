#include <iostream>
#include <vector>
using namespace std;
vector<int> pairsum(vector<int> nums,int tar){
    vector<int> ans;
    int n=nums.size();
    int i=0,j=n-1;
    while (i<j)
    {
        int ps=nums[i]+nums[j];
        if(ps>tar) j--;
        else if(ps<tar) i++;
        else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
}
    int main(){
        vector<int> nums={2,7,11,15};
        int target=13;
        vector<int> ans=pairsum(nums,target);
        cout<<ans[0]<<','<<ans[1];
        return 0;
      }
    
