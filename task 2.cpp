#include <iostream>
#include <string>

using namespace std;

class Shape {
protected:
    string color;

public:
    // Base class constructor
    Shape(string c) : color(c) {
        cout << "Shape constructor called. Color: " << color << endl;
    }

    void setColor(string c) {
        color = c;
    }

    string getColor() const {
        return color;
    }
};

class Rectangle : public Shape {
private:
    float length;
    float breadth;

public:
    // Derived class constructor
    Rectangle(string c, float l, float b) : Shape(c), length(l), breadth(b) {
        cout << "Rectangle constructor called. Length: " << length << ", Breadth: " << breadth << endl;
    }

    float calculateArea() const {
        return length * breadth;
    }

    float calculatePerimeter() const {
        return 2 * (length + breadth);
    }

    void display() const {
        cout << "Rectangle color: " << color << endl;
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
    }
};

int main() {
    // Creating a Rectangle object
    Rectangle rect("Blue", 10.0, 5.0);

    // Displaying rectangle details
    cout << endl;
    rect.display();

    return 0;
}
