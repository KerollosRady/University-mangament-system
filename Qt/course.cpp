#pragma once
#include "Course.h"

void Course::insert(const string& name, const string& instructor, int MaxNumOfStud, int hours, const set<code>& PreReqCourses)
{
    this->name = name;
    this->instructor = instructor;
    this->MaxNumOfStud = MaxNumOfStud;
    this->hours = hours;
    this->PreReqCourses = PreReqCourses;
}

void Course::DisplayData()
{

    cout << "Election Status: " << this->isElective << "\n";

    cout << "Course Name: " << this->name << "\n";

    cout << "Course Instructor: " << this->instructor << "\n";

    cout << "Course Capacity: " << this->MaxNumOfStud << "\n";

    cout << "Course Hours: " << this->hours << "\n";

    if (!PreReqCourses.empty())
    {

        cout << "Pre Required Courses Codes: ";
        for (auto i : PreReqCourses){
            cout << i ;
            if(i!=*prev(PreReqCourses.end()))
                cout<< " - ";
        }
    }
    else
    {
        cout << "No Required Courses!";
    }

    cout << "\n";
}
