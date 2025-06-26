//https://leetcode.com/problems/reverse-integer/submissions/1676780981/
class Solution {
public:
    int reverse(int x) {
        int revn=0;
        while(x!=0){
            int dig=x%10;
            if(revn>INT_MAX/10 || revn<INT_MIN/10) return 0;
            revn=revn*10+dig;
            x/=10;
        }
        return revn;
    }
};