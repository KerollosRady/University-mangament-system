#pragma once
#include "student.h"
#include <fstream>
#include <iostream>
using namespace std;

void UploadDataToCourse(vector<Course>& course)
{
    ofstream outfile("Course.txt");

    if (outfile.is_open())
    {
        outfile << course.size() << '\n';
        for (int i = 0; i < course.size(); i++)
        {
            outfile << course[i].name << "\n" << (int)course[i].isElective << "\n" << course[i].instructor << "\n" << course[i].hours << "\n" << course[i].MaxNumOfStud << '\n';

            outfile << course[i].PreReqCourses.size();
            for (auto& x : course[i].PreReqCourses)
                outfile << x << '\n';
        }
    }
    outfile.close();
}

void LoadDataFromCourse(vector<Course>& course)
{
    ifstream infile("Course.txt");

    int elec, sz;
    if (infile.is_open())
    {
        infile >> sz;
        course = vector<Course>(sz);
        for (int i = 0; i < sz; i++)
        {
            infile >> course[i].name >> elec >> course[i].instructor >> course[i].hours >> course[i].MaxNumOfStud;
            course[i].isElective = elec;
            int preqSz;
            infile >> preqSz;
            for (int j = 0, x; j < preqSz; j++)
                infile >> x, course[i].PreReqCourses.insert(x);
        }
    }
    infile.close();
}

void UploadDataToStudent(vector<Student>& student)
{
    ofstream outfile("Student.txt");

    if (outfile.is_open())
    {
        outfile << student.size() << '\n';

        for (auto& s : student)
        {
            outfile << s.name << '\n';
            outfile << s.ID << '\n';
            outfile << s.getEmail() << '\n';
            outfile << s.getPassword() << '\n';
            outfile << s.maximumHoursAllowed << '\n';
            outfile << s.academicYear << '\n';
            outfile << s.academicSemster << '\n';
            outfile << s.CGPA << '\n';

            outfile << s.progressCourses.size() << '\n';
            for (auto& pc : s.progressCourses)
                outfile << pc << '\n';

            outfile << s.finishedCourses.size() << '\n';
            for (auto isFinshed : s.finishedCourses)
                outfile << isFinshed << '\n';

            outfile << s.courseGPA.size();
            for (auto& cg : s.courseGPA)
                outfile << cg << '\n';
        }
    }
    outfile.close();
}

void LoadDataFromStudent(vector<Student>& student)
{
    ifstream infile("Student.txt");

    if (infile.is_open())
    {
        int sz; infile >> sz;
        student = vector<Student>(sz);
        for (auto& s : student)
        {
            infile >> s.name >> s.ID;
            string email, password;
            infile >> email >> password;
            s.setEmail(email);
            s.setPassword(password);

            infile >> s.maximumHoursAllowed >> s.academicYear >> s.academicSemster >> s.CGPA;

            infile >> sz;
            s.progressCourses = vector<int>(sz);
            for (auto& pc : s.progressCourses)
                infile >> pc;

            infile >> sz;
            for (int i = 0, x; i < sz; i++)
                infile >> x, s.finishedCourses.push_back(x);

            infile >> sz;
            s.courseGPA = vector<float>(sz);
            for (auto& cg : s.courseGPA)
                infile >> cg;
        }
    }
    infile.close();
}
