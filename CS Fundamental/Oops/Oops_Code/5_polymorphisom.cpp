#include <iostream>
#include <string>
using namespace std;

// Polymorphism is the ability of a function to behave differently based on the object that calls it.
// In C++, polymorphism is mainly divided into two types:
// 1. Compile-time polymorphism (Static polymorphism)
// 2. Run-time polymorphism (Dynamic polymorphism)

// Compile-time polymorphism is achieved using function overloading and operator overloading.
// Run-time polymorphism is achieved using inheritance and virtual functions.




// Constructor overlaoding
class Student {
public:
    string name;
    int age;
    int roll_no;

    // Default constructor
    Student() {
        name = "Unknown";
        age = 0;
        roll_no = 0;
    }

    // Parameterized constructor
    Student(string name, int age, int roll_no) {
        this->name = name;
        this->age = age;
        this->roll_no = roll_no;
    }

    // Overloaded parameterized constructor (with default values)
    Student(string name, int age) {
        this->name = name;
        this->age = age;
        this->roll_no = 0; // Default roll number
    }

    // Method to display student information
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << roll_no << endl;
    }
};

int main() {
    // Creating objects using different constructors

    // Using default constructor
    Student s1;
    s1.display(); // Display default values

    // Using parameterized constructor with all parameters
    Student s2("Rahul Kumar", 20, 101);
    s2.display(); // Display provided values

    // Using overloaded parameterized constructor with two parameters
    Student s3("Neha Sharma", 22);
    s3.display(); // Display provided values with default roll number

    return 0;
}

// Homework : operator overloading
// Difference between overloading and overridden.

// Priority : Child class functino > parent class ( For child class implementation) 
// **************************************************************************************

// Function overlaoding 


// #include <iostream>
// #include <string>
// using namespace std;

// class Printer { // Renamed the class to avoid conflict with method name
// public:
//     void show(int x) {
//         cout << "The value of int x is: " << x << endl;
//     }

//     void show(char c) {
//         cout << "The value of char c is: " << c << endl;
//     }
// };

// int main() {
//     Printer Print;  // Create an instance of the Printer class
//     Print.show(10); // Call show with an int argument
//     Print.show('A'); // Call show with a char argument
//     return 0;
// }
