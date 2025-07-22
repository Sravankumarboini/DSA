//https://leetcode.com/problems/palindrome-partitioning/submissions/1707383487/
class Solution {
public:
    bool ispalin(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }
    void getAllPart(string s,vector<string> &par,vector<vector<string>> &ans){
        if(s.size()==0){
            ans.push_back(par);
            return;
        }
        for(int i=0;i<s.size();i++){
            string part=s.substr(0,i+1);
            if(ispalin(part)){
                par.push_back(part);
                getAllPart(s.substr(i+1),par,ans);
                par.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
         vector<vector<string>> ans;
         vector<string> par;
         getAllPart(s,par,ans);
         return ans;
    }
};