#include <iostream>
#include <string>
using namespace std;

class Teacher{
private:
    //access specifier
    //private: only accessible within the class
    //public: accessible from outside the class
    //protected: accessible from outside the class but only ininherited class

    double salary;  // Data hiding
public:

    
    // properties or attributes of class
    string name;
    string dept;
    string subject;

    // method // member function
    void changeDept (string newDept){
        dept = newDept;
    }
    //setter function
    void setSalary(double newSalary){
        salary = newSalary;
    }

    //getter function
    double getSalary(){
        return salary;
    }
};

int main(){
    Teacher t;
    t.name = "Mr. John";
    t.dept = "Computer Science";
    t.subject = "Data Structure";
    // t.salary = "50000";

    // setter function
    t.setSalary(50000);
    
    cout << "Name: " << t.name << endl;
    cout << "Department: " << t.dept << endl;
    cout << "Subject: " << t.subject << endl;
    // getter function
    cout << "Salary using getter function: " << t.getSalary() << endl;
    // cout << "Salary: " << t.salary << endl;

    cout<<endl <<"If we don't provide any parameter in the constructor, it will take the default value"<<endl<<endl;
    Teacher t2;
cout << "Name: " << t2.name << endl;
    cout <<"Department: " << t2.dept << endl;
    cout << "Subject: " << t2.subject << endl;
    // getter function
    cout << "Salary using getter function: " << t2.getSalary() << endl;
    // cout << "Salary: " << t.salary << endl;    return 0;
}
