#pragma once
#include<vector>
#include<set>
#include<unordered_map>
#include<string>
#include<student.h>

using namespace std ;


class Data
{
public:
    Data();
    vector<set<int>> filterByElectivity;
    vector<set<int>> filterByHours;
    unordered_map<string, set<int>> filterByInstructor;
    vector<Course> course ;
    vector<vector<Student>> student ;
    set<int> filter(int elective, int hours, const string &Instructor);
};


