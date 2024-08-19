#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int roll_number;
    float marks;

public:
    void input() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> roll_number;
        cout << "Enter marks: ";
        cin >> marks;
        cin.ignore();  // To ignore the newline character left in the buffer
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll_number << endl;
        cout << "Marks: " << marks << endl;
    }

    string getName() const {
        return name;
    }

    int getRollNumber() const {
        return roll_number;
    }

    void setMarks(float new_marks) {
        marks = new_marks;
    }

    friend ofstream& operator<<(ofstream& ofs, const Student& s);
    friend ifstream& operator>>(ifstream& ifs, Student& s);
    friend fstream& operator>>(fstream& fs, Student& s);
    friend fstream& operator<<(fstream& fs, const Student& s);
};

ofstream& operator<<(ofstream& ofs, const Student& s) {
    ofs << s.name << endl;
    ofs << s.roll_number << endl;
    ofs << s.marks << endl;
    return ofs;
}

ifstream& operator>>(ifstream& ifs, Student& s) {
    getline(ifs, s.name);
    ifs >> s.roll_number;
    ifs >> s.marks;
    ifs.ignore(); // To ignore the newline character after marks
    return ifs;
}

fstream& operator<<(fstream& fs, const Student& s) {
    fs << s.name << endl;
    fs << s.roll_number << endl;
    fs << s.marks << endl;
    return fs;
}

fstream& operator>>(fstream& fs, Student& s) {
    getline(fs, s.name);
    fs >> s.roll_number;
    fs >> s.marks;
    fs.ignore(); // To ignore the newline character after marks
    return fs;
}

int main() {
    // Create a file named students.txt and write data of 5 students to it
    ofstream outFile("students.txt");
    Student students[5];

    cout << "Enter details of 5 students:\n";
    for (int i = 0; i < 5; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        students[i].input();
        outFile << students[i];
    }
    outFile.close();

    // Read the data from the file and display it
    ifstream inFile("students.txt");
    cout << "\nReading student data from file:\n";
    for (int i = 0; i < 5; i++) {
        inFile >> students[i];
        students[i].display();
        cout << endl;
    }
    inFile.close();

    // Modify the marks of a specific student using fstream
    fstream file("students.txt", ios::in | ios::out);
    string target_name;
    cout << "\nEnter the name of the student whose marks you want to modify: ";
    getline(cin, target_name);
    float new_marks;
    cout << "Enter the new marks: ";
    cin >> new_marks;

    bool found = false;
    for (int i = 0; i < 5; i++) {
        streampos pos = file.tellg(); // Save the position of the student data
        file >> students[i];
        if (students[i].getName() == target_name) {
            students[i].setMarks(new_marks);
            file.seekp(pos); // Move the file pointer back to the start of the student data
            file << students[i]; // Overwrite the student data
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }

    file.close();

    // Display the updated data
    cout << "\nUpdated student data:\n";
    inFile.open("students.txt");
    for (int i = 0; i < 5; i++) {
        inFile >> students[i];
        students[i].display();
        cout << endl;
    }
    inFile.close();

    return 0;
}