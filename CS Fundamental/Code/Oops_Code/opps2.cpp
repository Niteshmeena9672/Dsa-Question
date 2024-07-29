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
    Student s1("Rahul Kumar", 8.5);

    // Shallow Copy Example
    Student s2 = s1; // Calls the shallow copy constructor
    cout << "Shallow Copy:" << endl;
    s2.getInfo();
    
    // Modify the shallow copy
    s2.name = "Neha";
    *(s2.cgpa) = 9.2; // Update the CGPA through the pointer

    // Display the original student to show the effect of shallow copy
    cout << "Original after shallow copy modification:" << endl;
    s1.getInfo();

    // Deep Copy Example
    Student s3(s1, true); // Calls the deep copy constructor
    cout << "Deep Copy:" << endl;
    s3.getInfo();

    // Modify the deep copy
    s3.name = "Anjali";
    *(s3.cgpa) = 9.8; // Update the CGPA through the pointer

    // Display the original student to show the effect of deep copy
    cout << "Original after deep copy modification:" << endl;
    s1.getInfo();

    return 0;
}
