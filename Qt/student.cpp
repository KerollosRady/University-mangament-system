#pragma once
#include <ctime>
#include <string>
#include "student.h"
#include <cmath>
#include <algorithm>
#define el  '\n'
#define inRange(x, l, r) (l <= x && x <= r)

Student::Student(int year, int id, const string& name, int numberOfCourses,const string& collegeName )
{
    this->name = name;
    this->ID = GenerateID(id, year);
    setPassword(GeneratePassword());
    setEmail(GenerateEmail());
    this->collegeName = "Faculty Of Computer Science ." ;
    this->finishedCourses = vector<bool>(100,0);
    this->courseGPA       = vector<float>(100,0);
    this->academicSemster = 1  ;
    this->academicYear    = 1  ;
    this->CGPA            = 0.0;
    this->maximumHoursAllowed = 14 ;
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
        if (!finishedCourses[i] && maximumHoursAllowed >= c[i].hours)
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
void Student::delete_progresscourse(vector<Course>&course)
{
    for(auto c : progressCourses)
        course[c].CurStudents.erase({stoi(this->ID.substr(0,4))-2000,stoi(this->ID.substr(4,4))}) ;
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
string Student::GenerateEmail()
{
    return ID + "@cis.asu.eg";
}

string Student::GeneratePassword()
{
    string password;
    pair<char, char> ranges[3] = { {'0', '9'}, {'A', 'Z'}, {'a', 'z'} };
    int standardSize = 10;

    for (int i = 0; i < standardSize; i++)
    {
        int choosedRange = i % 3;
        int start = ranges[choosedRange].first, end = ranges[choosedRange].second;
        password += start + rand() % (end - start + 1);
    }

    return password;
}

string Student::GenerateID(int id, int year)
{
    string ID = to_string(id);
    string leadingZeros = string(4 - ID.size(), '0');
    return to_string(year) + leadingZeros + ID;
}

void Student::setEmail(string email)
{
    this->email = email;
}

void Student::setPassword(string password)
{
    this->password = password;
}

string Student::getEmail()
{
    return email;
}

string Student::getPassword()
{
    return password;
}

//check whether the password is valid
bool Student::validate_password(string password)
{
    if (password.size() < 8 || password.size() > 16)
        return false;

    // at least 1 digit
    if (!count_if(password.begin(), password.end(), [&](auto c) {return '0' <= c && c <= '9'; }))
        return false;

    // at least 1 lower case
    if (!count_if(password.begin(), password.end(), [&](auto c) {return 'a' <= c && c <= 'z'; }))
        return false;

    // at least 1 upper case
    if (!count_if(password.begin(), password.end(), [&](auto c) {return 'A' <= c && c <= 'Z'; }))
        return false;

    return true;
}



