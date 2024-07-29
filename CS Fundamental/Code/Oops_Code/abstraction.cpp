#include <iostream>
using namespace std;


// By creating any virtual functiion (virtual void draw() = 0;), we can make the class abstract and the direct object of this class
// can't be instantiated.

// Abstract class Shape
// Abstract classes are used to provide a base class from which other classes can be derived.
// They cannot be instantiated and are meant to be inherited.
// Abstract classes are typically used to define an interface for derived classes.
class Shape {
public:
    // Pure virtual function
    // A pure virtual function is a function with no implementation in the base class.
    // It makes the class abstract, meaning it cannot be instantiated.
    // Derived classes must provide an implementation for this function.
    virtual void draw() = 0; 
    void draws() {
        cout<<"hello"<<endl;
    } ; 
};

// Derived class Circle from the base class Shape
// This class must provide an implementation for the pure virtual function draw.
class Circle : public Shape {
public:
    // Override the pure virtual function draw
    // The override keyword indicates that this function is meant to override a base class function.
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

int main() {
    // Create an instance of Circle
    // Since Circle provides an implementation for the pure virtual function, it can be instantiated.
    Circle c;
    
    // Call the draw method of Circle
    // This will output: Drawing a circle
    c.draw(); 
    Shape rect;
    rect.draws();
    return 0;
}
