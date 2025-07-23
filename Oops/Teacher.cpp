#include <iostream>
#include <string>
using namespace std;

class Teacher{
    //properties
public:
    string name;
    string dept;
    string subject;
    double salary;
    //methods
    void chanegeDept(string newDept){
        dept =newDept;
    }
};

int main(){
    Teacher t1;
    t1.name="sravan";
    t1.subject="dsa";
    t1.dept="computer science";
    t1.salary=25000;
    cout<<t1.name<<endl;
    return 0;
}