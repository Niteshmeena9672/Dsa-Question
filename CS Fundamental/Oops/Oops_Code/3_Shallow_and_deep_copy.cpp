#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    double* cgpa;

    // Constructor
    Student(string name, double cgpa) {
        this->name = name;
        this->cgpa = new double(cgpa); // Allocate memory and assign value
    }

    // Destructor
    ~Student() {
        delete cgpa; // Free allocated memory
    }

    // Copy Constructor (Shallow Copy)
    Student(const Student& other) {
        name = other.name;
        cgpa = other.cgpa; // Shallow copy (just copies the pointer)
    }

    // Copy Constructor (Deep Copy)
    Student(const Student& other, bool deepCopy) {
        if (deepCopy) {
            name = other.name;
            cgpa = new double(*(other.cgpa)); // Deep copy (allocates new memory and copies the value)
        } else {
            name = other.name;
            cgpa = other.cgpa; // Shallow copy
        }
    }

    // Method to get info
    void getInfo() const {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpa << endl; // Dereference pointer to get value
    }
};

int main() {
    // Create a student using the constructor
    Student s1("Alice", 9.5);
    cout << "Student s1:" << endl;
    s1.getInfo();
    cout << endl;

    // Create a student using the shallow copy constructor
    Student s2(s1);
    cout << "Student s2 (shallow copy of s1):" << endl;
    s2.getInfo();
    cout << endl;

    // Modify the CGPA of s2 and observe the effect on s1
    *(s2.cgpa) = 8.5;
    cout << "After modifying s2's CGPA:" << endl;
    cout << "Student s1:" << endl;
    s1.getInfo();
    cout << "Student s2:" << endl;
    s2.getInfo();
    cout << endl;

    // Create a student using the deep copy constructor
    Student s3(s1, true);
    cout << "Student s3 (deep copy of s1):" << endl;
    s3.getInfo();
    cout << endl;

    // Modify the CGPA of s3 and observe the effect on s1
    *(s3.cgpa) = 7.5;
    cout << "After modifying s3's CGPA:" << endl;
    cout << "Student s1:" << endl;
    s1.getInfo();
    cout << "Student s3:" << endl;
    s3.getInfo();
    cout << endl;

    return 0;
}
