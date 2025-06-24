class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans="",word="";
        for(int i=0;i<s.length();i++){
            word="";
            while(i<s.length() && s[i]!=' '){
                word+=s[i];
                i++;
            }
            if(word.length()>0){
                reverse(word.begin(),word.end());
                ans+=" "+word;
            }
        }
        return ans.substr(1);
    }
};