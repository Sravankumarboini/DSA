//https://leetcode.com/problems/palindrome-number/
class Solution {
public:
    int reverse(int n){
        int revn=0;
        while(n!=0){
            int dig=n%10;
            if(revn>INT_MAX/10 || revn<INT_MIN/10) return 0;
            revn=revn*10+dig;
            n/=10;
        }
        return revn;
    }
    bool isPalindrome(int x) {
        if(x<0) return false;
        int revn=reverse(x);
        if(x==revn) return true;
        else return false;
    }
};