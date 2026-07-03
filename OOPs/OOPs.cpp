#include<bits/stdc++.h>
using namespace std;

class Teacher{
    // properties/attributes

private:
    double salary;
public:

    //  Non-paeameterized
    Teacher(){
        cout << "Hi, I am constructor\n";
    }

    // Parameterized
    Teacher(string name , string d, string s, double sal){
        this->name=name; //when u hve same thing both side just to 
        //specify left one is object name and right one is constructor parameterized
        dept=d;
        subject=s;
        salary=sal;
    }

    // copy construtor
    Teacher(Teacher &orgOb){
        cout << "I am custom copy construtor...\n";
        this->name=orgOb.name;
        this->dept = orgOb.dept;
    }
    string name;
    string dept;
    string subject;

    //method/member functions
    //setter
    void setSalary(double s){
        salary=s;
    }
    //getter
    double getSalary(){
        return salary;
    }
    void changeDept(string newDept){
        dept=newDept;
    }

    void getinfo(){
        cout << "name: " << name << endl;
        cout << "subject: " << subject << endl;
    }
    

};
int main(){
    Teacher t1("Shagun", "OK", "C++",25000);
    // Teacher t1; //Constructor call

    // t1.name ="Shagun";
    // t1.dept = "OL";
    // t1.setSalary(25000);
    // t1.subject="c++";

    // cout << t1.name << endl;
    // cout << t1.getSalary() << endl;
    // t1.getinfo();

    Teacher t2(t1); //default copy constructor - invoke
    t2.getinfo();
    return 0;
}
