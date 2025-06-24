bool armstrong(int n){
    int copyn=n,sum=0;
    while(i!=0){
        int dig=n%10;
        sum+=pow(dig,3);
        n=n/10;
    }
    if(copyn==sum) return true;
    else return false;
}