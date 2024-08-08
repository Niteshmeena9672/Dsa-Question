#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    double salary;  // Data hiding

public:
    string name;
    string dept;
    string subject;

    // Default constructor
    Teacher() {
        name = "Unknown";
        dept = "Unknown";
        subject = "Unknown";
        salary = 0.0;
        cout << "Default constructor called" << endl;
    }

    // Parameterized constructor
    Teacher(string newName, string newDept, string newSubject, double newSalary) {

        // attributes = instance variables
        // properties = function arguments
        // name = newName;
        // dept = newDept;
        // subject = newSubject;
        // salary = newSalary;
      
    // this keyword is a pointer that points to the current object
    // if some variable is same as the instance variable, then we use this keyword to differentiate between the two
        this->name = newName;
        this->dept = newDept;
        this->subject = newSubject;
        this->salary = newSalary;
        cout << "Parameterized constructor called" << endl;
    }

    // Copy constructor

    // In the copy constructor, using & copies the values of the original object's members to the new object, creating two separate objects. Changes to the new object do not affect the original object because they do not share the same memory addresses for their members.
    
    Teacher(const Teacher &other) {
        name = other.name;
        dept = other.dept;
        subject = other.subject;
        salary = other.salary;
        cout << "Copy constructor called" << endl;
    }

    // Method to change department
    void changeDept(string newDept) {
        dept = newDept;
    }

    // Setter function
    void setSalary(double newSalary) {
        salary = newSalary;
    }

    // Getter function
    double getSalary() const {
        return salary;
    }
};

int main() {
    // Using default constructor
    Teacher t1;
    cout << "Name: " << t1.name << endl;
    cout << "Department: " << t1.dept << endl;
    cout << "Subject: " << t1.subject << endl;
    cout << "Salary using getter function: " << t1.getSalary() << endl;
    cout << endl;

    // Using parameterized constructor
    Teacher t2("Mr. John", "Computer Science", "Data Structures", 50000);
    cout << "Name: " << t2.name << endl;
    cout << "Department: " << t2.dept << endl;
    cout << "Subject: " << t2.subject << endl;
    cout << "Salary using getter function: " << t2.getSalary() << endl;
    cout << endl;

    // Using copy constructor
    // Teacher t3 = t2;
    Teacher t3(t2);
    t3.name = "Mr. Smith";
    t3.dept = "Electronics";


    cout << "t2 after changing t3 cahnge Name: " << t2.name << endl;
    cout << "Department: " << t2.dept << endl;
    cout << "Name: " << t3.name << endl;
    cout << "Department: " << t3.dept << endl;
    cout << "Subject: " << t3.subject << endl;
    cout << "Salary using getter function: " << t3.getSalary() << endl;

    return 0;
}
