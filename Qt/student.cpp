#pragma once
#include <ctime>
#include <string>
#include "student.h"
#include <cmath>
#include <algorithm>
#define el  '\n'
#define inRange(x, l, r) (l <= x && x <= r)

Student::Student(int year, int id, const string& name, int numberOfCourses)
{
    this->name = name;
    this->ID = GenerateID(id, year);
    setPassword(GeneratePassword());
    setEmail(GenerateEmail());
    this->finishedCourses = vector<bool>(numberOfCourses);
    this->courseGPA       = vector<float>(numberOfCourses);
    this->academicSemster = 1  ;
    this->academicYear    = 1  ;
    this->CGPA            = 0.0;
}

Student::Student()
{
}

void Student::SemesterUpdate()
{
    this->academicSemster++;
    // updating CGPA & finishedCourses

    int finishedCnt = count(finishedCourses.begin(),finishedCourses.end(), 1);
    int allFinished = finishedCnt;

    CGPA *= finishedCnt;

    for (auto& id : progressCourses)
    {
        if (courseGPA[id] < 2)
            courseGPA[id] = 0;
        else
            allFinished++, finishedCourses[id] = 1;
        CGPA += courseGPA[id];
    }

    CGPA /= max(int(progressCourses.size() + finishedCnt),1) ;


    progressCourses.clear();
    academicYear = allFinished/10 + 1;

    if (academicYear == 5){
        graduated = 1;
        return;
    }

    //	 determining max hours allowed depending on GPA
    if (inRange(CGPA, 3, 4))
        this->maximumHoursAllowed = 21;
    else if (inRange(CGPA, 2, 3))
        this->maximumHoursAllowed = 18;
    else if (inRange(CGPA, 0, 2))
        this->maximumHoursAllowed = 14;
}

void Student::ViewAvailableCourses(const vector<Course>& c)
{
    for (int i = 0; i < c.size(); i++)
    {
        if (!finishedCourses[i] && maximumHoursAllowed>=c[i].hours)
        {
            bool ok = 1;
            for (auto pre : c[i].PreReqCourses)
                ok &= finishedCourses[pre] ;
            if (ok)
                cout << c[i].name << el ;
        }
    }
}

void Student::FilterCourse(const vector<Course>& c)
{
    //
}

void Student::ViewDetailsCourse(vector<Course>& course, code id)
{
    course[id].DisplayData();
}

void Student::RegisterCourse(code c)
{
    progressCourses.push_back(c);
}
void Student::ViewAllcourses(const vector<Course>&course)
{
    cout << "Finished courses"<<el;
    for (int i = 0; i < finishedCourses.size(); i++)
    {
        if (finishedCourses[i])
        {
            cout << course[i].name << el;
        }
    }
    cout << "Progress Courses" << el;
    for (auto c : progressCourses)
        cout << course[c].name << el;
}
void Student::ViewCourseGrade_CGPA(const vector<Course>&course)
{
    cout << " cumulative GPA" << el;
    cout << CGPA << el;
    for (int i = 0; i < finishedCourses.size(); i++)
    {
        if (finishedCourses[i])
        {
            cout <<course[i].name<<" Grade : " << courseGPA[i] << el;
        }
    }
}

void Student::EditData()
{
    string oldpass ;
    cout << "Enter Old Password  : " << el;
    cin >> oldpass;
    if (oldpass == getPassword()) {
        string newPass , reNewPass;
        cout << "Enter New Password : " << el;
        cin >> newPass;
        cout << "Renter New Password : " << el;
        cin >> reNewPass;
        if (newPass == reNewPass)
            setPassword(newPass);
    }
}



