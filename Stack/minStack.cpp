#include<iostream>
#include<stack>
using namespace std;
class minStack{
    stack<long long int> s;
    long long minVal;
    public:
    void push(int val){
        if(s.empty()) {
            s.push(val);
            minVal=val;
        }else{
            if(val<minVal){
                s.push(2*val-minVal);
                minVal=val;
            }else{
                s.push(val);
            }
        }
    }
    void pop(){
        if(s.top()<minVal){
            minVal=2*minVal-s.top();
        }
        s.pop();
    }
    int top(){
        if(s.top()<minVal) return minVal;
        else return s.top();
    }
    int getMin(){
        return minVal;
    }
};
int main(){
    minStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout<<ms.getMin()<<endl;
    ms.pop();
    cout<<ms.getMin()<<endl;
    cout<<ms.top()<<endl;
}