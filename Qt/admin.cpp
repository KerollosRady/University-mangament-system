#pragma once
#include "Admin.h"

Admin::Admin(const string &name, const string &password) {
    this->name = name;
    setPassword(password);
}

void Admin::addCourse(Course &newCourse, vector<Course>& Courses) {
    Courses.push_back(newCourse);
}

void Admin::editName(string &name, code course_code , vector<Course> & Courses) {
    Courses[course_code].name=name;
}

void Admin::editRequirement(bool isElective, code course_code, vector<Course> & Courses) {
    Courses[course_code].isElective = isElective ;
}

void Admin::editMaximumStudents(int maximumStudents, code course_code , vector<Course> & Courses) {
    Courses[course_code].MaxNumOfStud=maximumStudents;
}

void Admin::EnterCoursePrerequisite(code course_code, code pre_code, vector<Course> & Courses){
    Courses[course_code].PreReqCourses.insert(pre_code);
}

void Admin::RemoveCoursePrerequisite(code course_code, code pre_code , vector<Course> & Courses){
    set<code> &s = Courses[course_code].PreReqCourses;
    auto it = s.find(pre_code);
    if (it != s.end())
        s.erase(it);
}

void Admin::editHours(int hours, code course_code, vector<Course>& Courses) {
    Courses[course_code].hours = hours ;
}

void Admin::editInstructor(string &instructor, code course_code, vector<Course>& Courses) {
    Courses[course_code].instructor=instructor;
}
