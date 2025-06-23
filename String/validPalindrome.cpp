//https://leetcode.com/problems/valid-palindrome/
class Solution {
public:
    bool isPalindrome(string s) {
       transform(s.begin(), s.end(), s.begin(), ::tolower);
        int st=0,end=s.length()-1;
         
        while(st<end){
            while (st < end && !isalnum(s[st])) st++;
            while (st < end && !isalnum(s[end])) end--;
            if(s[st]!=s[end]) return false;
            st++;end--;
        }
        return true;
    }
};