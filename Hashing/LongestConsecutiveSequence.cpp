#include<iostream>
#include<vector>
#include<set>
#include <climits>
using namespace std;
int LongestSequence(vector<int> arr){
    set<int> s;
    for(int i=0;i<arr.size();i++){
        s.insert(arr[i]);
    }
    auto it=s.begin();
    auto next_it=next(it);
    int max_length=1;
    int cnt=1;
    for(auto it=s.begin();next_it!=s.end();it++){
        if(*next_it-1==*it) cnt++;
        else{
            max_length=max(max_length,cnt);
            cnt=1;
        }
        next_it++;
    }
    return max_length;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int length=LongestSequence(arr);
    cout<<"longest consicutive sequence is "<<length;
}