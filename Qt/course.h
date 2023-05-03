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
    set<code> PreReqCourses;

    void insert(const string& name, const string& instructor, int MaxNumOfStud, int hours,const set<int>& PreReqCourses);
    void DisplayData();
};
