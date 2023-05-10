#pragma once
#include<vector>
#include<set>
#include<unordered_map>
#include<string>
#include<course.h>
#include<student.h>

using namespace std ;
#define s1      Data::filterByElectivity
#define s2      Data::filterByHours
#define s3      Data::filterByInstructor

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


