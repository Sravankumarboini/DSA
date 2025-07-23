#include <iostream>
#include <string>
using namespace std;

class Teacher{
    //properties
private:
    double salary;
public:
    string name;
    string dept;
    string subject;
    //methods
    void chanegeDept(string newDept){
        dept =newDept;
    }
    void setSalary(double s){
        salary=s;
    }
    double getSalary(){
        return salary;
    }
};

int main(){
    Teacher t1;
    t1.name="sravan";
    t1.subject="dsa";
    t1.dept="computer science";
    t1.setSalary(25000);
    cout<<t1.name<<endl;
    cout<<t1.getSalary();
    return 0;
}