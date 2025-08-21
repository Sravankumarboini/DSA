#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    int arr[]={6,8,0,1,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> ans(n);
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        while(s.size()>0 && s.top()<=arr[i]) s.pop();
        if(s.empty()) ans[i]=-1;
        else ans[i]=s.top();
        s.push(arr[i]);
    }
    for(int i:ans)
        cout<<i<<" ";
}