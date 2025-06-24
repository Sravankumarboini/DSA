//https://leetcode.com/problems/count-primes/
class Solution {
public:
    bool isprime(int dig){
        if(dig<2) return false;
        for(int i=2;i*i<=dig;i++){
            if(dig%i==0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        int count=0;
        if(n==0) return 0;
        while(n--){
            if(isprime(n)) count++;
        }
        return count;
    }
};