#pragma once
#include<iostream>
#include <vector>
#include"Course.h"
#define el '\n'
class Student
{
public:
    string email;
    string password;
    string name;
    string ID;
    int maximumHoursAllowed;
    float CGPA;
    int academicYear;
    int academicSemster;
    bool graduated = false;
    string collegeName = "Faculty Of Computer Science" ;
    vector<bool> finishedCourses;
    vector<code> progressCourses ;
    vector<float> courseGPA;
    Student(int year, int id, const string& name, int numberOfCourses ,const string& collegeName );
    Student();
    void setEmail(string email);
    string GenerateEmail();
    void setPassword(string password);
    string GeneratePassword();
    string GenerateID(int id, int year);
    string getEmail();
    string getPassword();
    bool validate_password(string password);
    void SemesterUpdate();
    void ViewAvailableCourses(const vector<Course>&);
    void FilterCourse(const vector<Course>&);
    // gui
    void ViewDetailsCourse( vector<Course>& , code );
    void RegisterCourse(code);
    void delete_progresscourse( vector<Course>&);
    void ViewCourseGrade_CGPA(const vector<Course>&);
    void EditData();
};
