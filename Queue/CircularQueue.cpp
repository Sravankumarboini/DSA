#include<iostream>
using namespace std;
class circularQueue{
    int *arr;
    int f,r;
    int currsize,cap;
    public:
    circularQueue(int size){
        cap=size;
        arr=new int[cap];
        f=0,r=-1;
        currsize=0;
    }

    void push(int val){
        if(!empty()){
            cout<<" full";
            return;
        }
        r=(r+1)%cap;
        arr[r]=val;
        currsize++;
    }

    void pop(){
        if(empty()){
            cout<<"empty";
            return;
        }
        f=(f+1)%cap;
        currsize--;
    }

    int front(){
        if(empty()){
            return -1;
        }
        return arr[f];
    }

    bool empty(){
        return currsize==cap;
    }
};

int main(){
    circularQueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
}