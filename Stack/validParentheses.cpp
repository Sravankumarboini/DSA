#include<iostream>
#include<stack>
using namespace std;
bool isValid(string str){
    stack<char> s;
    for(int i=0;i<str.size();i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')//opening
            s.push(str[i]);
        else{//closing
             if(s.size()==0) return false;
             if((str[i]==')' && s.top()=='(') || (str[i]=='}' && s.top()=='{') || (str[i]==']' && s.top()=='[')){
                s.pop();
             }else{
                return false;
             }
        }
    }
    return s.size()==0;
}
int main(){
    string s="({[]})";
    cout << isValid(s);
}