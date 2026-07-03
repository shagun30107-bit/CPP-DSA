#include<bits/stdc++.h>
using namespace std;


class Person{
public:
    string name;
    int age;

    // Person(string name,int age){
    //     this->name = name;
    //     this->age = age;
    // }

    Person(){
        cout << "Parent constructor..\n";
    }
};

class Student : public Person{
public:
    int rollno;

    Student(){
        cout << "Child constructor..\n";
    }
    void getInfo(){
        cout << "name" << name << endl;
        cout << "age" << age << endl;
        cout << "rollno" << rollno << endl;
    }
};

class Gradstudent : public Student {
public:
    string researchArea;
};
int main(){
    Gradstudent s1;
    s1.name = "Shagun";
    s1.age=18;
    s1.researchArea = "Quantum";
    s1.rollno=1233;

    s1.getInfo();
    cout << s1.researchArea << endl;
    return 0;
}