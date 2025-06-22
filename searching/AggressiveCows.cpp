bool ispossible(vector<int> &arr,int n,int k,int mid){
    int c=1,lastpossible=arr[0];
    for(int i=1;i<n;i++){
        if((arr[i]-lastpossible)>=mid){
            c++;
            lastpossible=arr[i];
        }
        if(c==k) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int n, int k) {
    // code here
    sort(stalls.begin(),stalls.end());
    int ans=-1;
    int st=1,end=stalls[n-1]-stalls[0];
    while(st<=end){
        int mid=st+(end-st)/2;
        if(ispossible(stalls,n,k,mid)){
            ans=mid;
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}