#pragma once

#include "FciVector.h"
#include "Course.h"

class Student {
private:
    string sName;
    int sID;
    string sDepartment;
    FciVector<Course> courses;
public:
    Student();

    void setInfo();

    void printInfo();

    friend ostream& operator<<(ostream&, Student&);

    friend istream& operator>>(istream&, Student&);

    Student& operator=(Student);
};