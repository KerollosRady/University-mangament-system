#pragma once
#include <QString>
#include<vector>
#include<set>
#include<unordered_map>
#include<string>
#include<student.h>
#include <fstream>
#include <iostream>
#include <QTime>
#include <QDate>

using namespace std ;


class Data
{
public:
    Data();
    ~Data();
    vector<Course> course ;
    vector<vector<Student>> student ;
    int last_year ;
    vector<int> filter(int elective, int hours, const string &Instructor);
    QString string_to_Qstring(string s) ;
    QDate startRegDate , endRegDate;
    bool Search_String(string base ,string child) ;
    void UploadDataToCourse();
    void LoadDataFromCourse();
    void UploadDataToStudent();
    void LoadDataFromStudent();
};


