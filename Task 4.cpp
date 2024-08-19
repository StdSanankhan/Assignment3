#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    string address;

public:
    // Constructor
    Person(string n, string addr) : name(n), address(addr) {
        cout << "Person constructor called. Name: " << name << ", Address: " << address << endl;
    }

    void setName(string n) {
        name = n;
    }

    string getName() const {
        return name;
    }

    void setAddress(string addr) {
        address = addr;
    }

    string getAddress() const {
        return address;
    }
};

class Employee {
protected:
    int employeeID;
    double salary;

public:
    // Constructor
    Employee(int id, double sal) : employeeID(id), salary(sal) {
        cout << "Employee constructor called. Employee ID: " << employeeID << ", Salary: " << salary << endl;
    }

    void setEmployeeID(int id) {
        employeeID = id;
    }

    int getEmployeeID() const {
        return employeeID;
    }

    void setSalary(double sal) {
        salary = sal;
    }

    double getSalary() const {
        return salary;
    }
};

class Teacher : public Person, public Employee {
private:
    string subject;

public:
    // Constructor
    Teacher(string n, string addr, int id, double sal, string subj)
        : Person(n, addr), Employee(id, sal), subject(subj) {
        cout << "Teacher constructor called. Subject: " << subject << endl;
    }

    void setSubject(string subj) {
        subject = subj;
    }

    string getSubject() const {
        return subject;
    }

    void display() const {
        cout << "Name: " << getName() << endl;
        cout << "Address: " << getAddress() << endl;
        cout << "Employee ID: " << getEmployeeID() << endl;
        cout << "Salary: " << getSalary() << endl;
        cout << "Subject: " << getSubject() << endl;
    }
};

int main() {
    // Creating a Teacher object
    Teacher myTeacher("Alice", "123 Main St", 101, 55000, "Mathematics");

    // Accessing members of all classes
    cout << "\nTeacher Details:" << endl;
    myTeacher.display();

    return 0;
}
