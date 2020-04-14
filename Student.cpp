#include "Student.h"

Student::Student() {
    sName = "Student"; // initialize name
    sID = 0;// initialize id
    sDepartment = "Department"; // initialize department
}

void Student::setInfo() {
    cout << "Student Name: ";
    getline(cin, sName); // name input
    cout << "Student ID: ";
    while (!(cin >> sID) || sID < 0) { // check for invalid data type input or ID
        cin.clear(); // clear stream
        cin.ignore(9999, '\n'); // ignore characters in the stream
        cout << "Invalid Student ID" << endl;
    }
    cin.ignore();
    cout << "Student Department: ";
    getline(cin, sDepartment); // department input
    cout << "Number of Courses: ";
    int coursesNum = 0;
    while (!(cin >> coursesNum) || coursesNum < 0) { // check for invalid count or data type input
        cin.clear(); // clear stream
        cin.ignore(9999, '\n'); // ignore characters in the stream
        cout << "Invalid Number of Courses" << endl;
    }
    cin.ignore();
    for (int i = 0; i < coursesNum; i++) {
        courses.push_back(Course()); // add element in the courses vector
        courses[i].setInfo(); // set the course info
    }
}

void Student::printInfo() {
    cout << "\nStudent Name: " << sName << endl; // print student's name
    cout << "Student ID: " << sID << endl; // print student's id
    cout << "Student Department: " << sDepartment << endl; // print student's department
    cout << "Number of Courses: " << courses.size() << endl << endl; // print student's number of courses
    for (int i = 0; i < courses.size(); i++) { // print student's courses
        cout << "Course " << i + 1 << ':' << endl;
        courses[i].printCourseInfo();
    }
}

ostream& operator<<(ostream& out, Student& x) {
    x.printInfo();
    return out;
}

istream& operator>>(istream& in, Student& x) {
    x.setInfo();
    return in;
}

Student& Student::operator=(Student x) {
    sID = x.sID; // copy student's id
    sDepartment = x.sDepartment; // copy student's department
    sName = x.sName; // copy student's name
    for (int i = 0; i < x.courses.size(); i++) { // copy student's courses
        courses.push_back(Course());
        courses[i] = x.courses[i];
    }
    return *this; // dereference current object pointer and return
}