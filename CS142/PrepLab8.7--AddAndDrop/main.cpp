#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

class Student {
public:
    Student(string name = "not initialized", double GPA = 0.0);
    void SetName(string studentName);
    void SetGPA(double newGPA);
    string ToString() const;
private:
    string name;
    double GPA;
};

Student::Student(string initialName, double initialGPA) {
    name = initialName;
    GPA = initialGPA;
}

void Student::SetName(string inputName) {
    name = inputName;
}

void Student::SetGPA(double newGPA) {
    GPA = newGPA;
}

string Student::ToString() const {
    ostringstream studentOSS;
    studentOSS << name << " has a GPA of " << fixed << setprecision(6) << GPA;
    return studentOSS.str();
}

//Insert the ToString member function here

int main() {
    vector<Student*> students;
    //options are: add drop print quit
    string userOption = "";

    do {
        cout << "Enter Option: ";
        cin >> userOption;
        cout << endl;

        if(userOption == "add"){
            string name;
            double GPA;
            cout << "Student name: ";
            cin >> name;
            cout << endl;

            cout << name << "'s GPA: ";
            cin >> GPA;
            cout << endl;

            Student* student = new Student(name, GPA);
            students.push_back(student);
        }else if(userOption == "drop") {
            int index = 0;
            cout << "Index of student to drop: ";
            cin >> index;
            cout << endl;

            delete students.at(index);
            students.erase(students.begin() + index);
        }else if(userOption == "print"){
            for(int i = 0; i < students.size(); i++){
                cout << i << ": " << students.at(i)->ToString() << endl;
            }
            cout << endl;
        }
    }while(userOption != "quit");

    return 0;
}