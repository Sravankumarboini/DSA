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
    while(next_it!=s.end()){
        if(*next_it-1==*it) cnt++;
        else{
            max_length=max(max_length,cnt);
            cnt=1;
        }
        it=next_it;
        next_it++;
    }
    max_length=max=max(cnt,max_length);
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