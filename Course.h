#pragma once

#include <iostream>
#include <string>

using namespace std;

class Course {
private:
    string courseName;
    string courseCode;
    char courseGrade;
    float coursePoint;
    int courseYear;
    int courseSemester;
public:
    Course();

    void setInfo();

    void printCourseInfo();

    Course& operator=(Course&);
};