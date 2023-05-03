#pragma once
#include"student.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Admin : public user
{
public:
    Admin(const string &name, const string &password);

    //void viewStudentsOfCourse();
    //void viewCoursesOfStudent();

    void addCourse(Course&, vector<Course>&);
    void editName(string&, code , vector<Course>&);
    void editRequirement(bool, code , vector<Course>&);
    void editMaximumStudents(int, code , vector<Course>&);
    void editHours(int, code , vector<Course>&);
    void editInstructor(string&, code , vector<Course>&);
    void EnterCoursePrerequisite(code, code , vector<Course>&);
    void RemoveCoursePrerequisite(code, code , vector<Course>&);

};
