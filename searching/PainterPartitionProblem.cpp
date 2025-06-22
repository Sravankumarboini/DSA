//we can implement using bookallocation problem
//https://www.codechef.com/practice/course/binary-search/INTBINS01/problems/BSEX03?tab=statement
#include <bits/stdc++.h>
using namespace std;

// Implement the painter_partition method here 
bool isvalid(vector<int> arr,int k,int mid){
    int n=arr.size();
    int time=0,pai=1;
    for(int i=0;i<n;i++){
        if(arr[i]>mid) return false;
        if(time+arr[i]<=mid){
            time+=arr[i];
        }
        else{
            pai++;
            time=arr[i];
        }
    }
    return pai>k?false:true;
}
int painter_partition(vector<int> arr, int k){
    int sum=0,maxval=INT_MIN;
    for(int i:arr){
        sum+=i;
        maxval=max(maxval,i);
    }
    int st=maxval,end=sum,ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isvalid(arr,k,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    return ans;
}
int main() {
    // Write your code here
    int t;
    cin>>t;
    while(t--){
    int N, k;
    cin >> N >> k;
    vector<int> boards(N);
    for (int i = 0; i < N; i++)
        cin >> boards[i];

    cout << painter_partition(boards, k) << endl;
    }
    return 0;
}