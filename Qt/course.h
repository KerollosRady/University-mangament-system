#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

#define code int

class Course
{
public:
    string name;
    bool isElective;
    string instructor;
    int MaxNumOfStud;
    int hours;
    double x, y;
    set<code> PreReqCourses;
    set<pair<int , int>> CurStudents;
    void insert(const string& name, const string& instructor, int MaxNumOfStud, int hours,const set<int>& PreReqCourses);
    void DisplayData();
};
