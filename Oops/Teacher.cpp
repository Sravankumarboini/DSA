#include <iostream>
#include <string>
using namespace std;

class Teacher{
    //properties
private:
    double salary;
public:
    Teacher(){
        cout<<"Hi,I am constructor"<<endl;
    }
    string name;
    string dept;
    string subject;
    //methods
    void chanegeDept(string newDept){
        dept =newDept;
    }
    void setSalary(double s){//setter
        salary=s;
    }
    double getSalary(){//getter
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