#pragma once
#include<iostream>
#include <vector>
#include "user.h"
#include"Course.h"
#define el '\n'
class student : public user
{
public:
    int maximumHoursAllowed;
    float CGPA;
    int academicYear;
    int academicSemster;
    vector<bool> finishedCourses;
    vector<code> progressCourses;
    vector<float> courseGPA;
    student(int year, int id, const string& name, int numberOfCourses);
    student();
    void SemesterUpdate();
    void ViewAvailableCourses(const vector<Course>&);
    void FilterCourse(const vector<Course>&);
    // gui
    void ViewDetailsCourse( vector<Course>& , code );
    void RegisterCourse(code);
    void ViewAllcourses(const vector<Course>&);
    void ViewCourseGrade_CGPA(const vector<Course>&);
    void EditData();
};
