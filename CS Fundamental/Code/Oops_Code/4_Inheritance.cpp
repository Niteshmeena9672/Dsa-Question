// #include <iostream>
// #include <string>
// using namespace std;

// // Constructor sequence : Base class -> Child or derived class
// // Destructor sequence : Child or derived class or base class

// class Person   // Base class
// {
// public:
//     string name;
//     int age;

//     // Parameterized constructor for Person
//     Person(string name, int age) {
//         this->name = name;
//         this->age = age;
//     }

//     void display() const
//     {
//         cout << "Name: " << name << endl;
//         cout << "Age: " << age << endl;
//     }
// };

// class Student : public Person   // Derived class
// {
// public:
//     int roll_no;

//     // Parameterized constructor for Student
//     Student(string name, int age, int roll_no) : Person(name, age) {
//         this->roll_no = roll_no;
//     }

//     void displays() const
//     {
//         cout << "Roll No: " << roll_no << endl;
//         Person::display();  // Call base class display
//     }
// };

// int main(){
//     // Create an instance of Student using the parameterized constructor
//     Student s1("Rahul Kumar", 20, 101);

//     s1.displays(); // Display student information

//     return 0;
// }


// Multi levl inheritance

#include <iostream>
#include <string>
using namespace std;

class Person   // Base class
{
public:
    string name;
    int age;

    // Parameterized constructor for Person
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void display() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person   // Derived class
{
public:
    int roll_no;

    // Parameterized constructor for Student
    Student(string name, int age, int roll_no) : Person(name, age) {
        this->roll_no = roll_no;
    }

    void display() const
    {
        Person::display();  // Call base class display
        cout << "Roll No: " << roll_no << endl;
    }
};

class GradStudent : public Student   // Derived class
{
public:
    string research_area;

    // Parameterized constructor for GradStudent
    GradStudent(string name, int age, int roll_no, string research_area) : Student(name, age, roll_no) {
        this->research_area = research_area;
    }

    void display() const
    {
        Student::display();  // Call base class display
        cout << "Research Area: " << research_area << endl;
    }
};

int main(){
    // Create an instance of Student using the parameterized constructor
    Student s1("Rahul Kumar", 20, 101);
    s1.display(); // Display student information
    cout<<endl;
    cout<<endl;
    // Create an instance of GradStudent using the parameterized constructor
    GradStudent gs1("Neha Sharma", 24, 202, "Artificial Intelligence");
    gs1.display(); // Display graduate student information

    return 0;
}
