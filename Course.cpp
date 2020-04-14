#include "Course.h"

Course::Course() {
    courseCode = "Code"; // initialize course code
    courseGrade = 'G'; // initialize course grade
    courseName = "Course"; // initialize course name
    coursePoint = 0.0; // initialize course point
    courseSemester = 1; // initialize course semester
    courseYear = 1; // initialize course year
}

void Course::setInfo() {
    cout << "Course Name: ";
    getline(cin, courseName); // course name input
    cout << "Course Code: ";
    getline(cin, courseCode); // course code input
    cout << "Course Grade: ";
    while (!(cin >> courseGrade) || courseGrade == 'E' || (courseGrade < 'A' || courseGrade > 'F')) { // check for invalid data type input or grade
        cin.clear(); // clear stream
        cin.ignore(9999, '\n'); // ignore characters in the stream
        cout << "Invalid Course Grade" << endl;
    }
    cout << "Course Point: ";
    while (!(cin >> coursePoint) || coursePoint < 0) {// check for invalid data type input or point
        cin.clear(); // clear stream
        cin.ignore(9999, '\n'); // ignore characters in the stream
        cout << "Invalid Course Point" << endl;
    }
    cout << "Course Year: ";
    while (!(cin >> courseYear) || courseYear < 0) {// check for invalid data type input or year
        cin.clear(); // clear stream
        cin.ignore(9999, '\n'); // ignore characters in the stream
        cout << "Invalid Course Year" << endl;
    }
    cout << "Course Semester: ";
    while (!(cin >> courseSemester) || courseSemester < 0) {// check for invalid data type input or semester
        cin.clear(); // clear stream
        cin.ignore(9999, '\n'); // ignore characters in the stream
        cout << "Invalid Course Semester" << endl;
    }
    cin.ignore();
}

void Course::printCourseInfo() {
    cout << "Course Name: " << courseName << endl; // print course name
    cout << "Course Code: " << courseCode << endl; // print course code
    cout << "Course Grade: " << courseGrade << endl; // print course grade
    cout << "Course Point: " << coursePoint << endl; // print course pointer
    cout << "Course Year: " << courseYear << endl; // print course year
    cout << "Course Semester: " << courseSemester << endl; // print course semester
}

Course& Course::operator=(Course& x) {
    courseSemester = x.courseSemester; // copy course semester
    coursePoint = x.coursePoint; // copy course pointer
    courseGrade = x.courseGrade; // copy course grade
    courseCode = x.courseCode; // copy course code
    courseName = x.courseName; // copy course name
    courseYear = x.courseYear; // copy course year
    return *this; // dereference this object's pointer and return
}