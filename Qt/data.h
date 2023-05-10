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
    vector<Course> course ;
    vector<vector<Student>> student ;
    vector<int> filter(int elective, int hours, const string &Instructor);
    bool Search_String(string base ,string child) ;
};


