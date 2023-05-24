#include <QWidget>
#include "data.h"
Data::Data()
{
}
Data::~Data()
{

}
vector<int> Data::filter(int elective, int hours, const string &Instructor)
{
    bool bye = (elective != -1),
        byh = (hours != -1),
        byins = (Instructor != "-1");
    vector<int> v ;
    for(int i=0 ;i<course.size() ;i++){
        if ((!bye || course[i].isElective==bool(elective) ) &&
            (!byh || course[i].hours ==hours) &&
            (!byins || Search_String(course[i].instructor,Instructor)))
            v.push_back(i) ;
    }
    return v;
}
bool Data::Search_String(string base , string child){
    for(auto &c : base )
        c =tolower(c) ;
    for(auto &c : child )
        c =tolower(c) ;
    return ~base.find(child) ;
}

void Data::UploadDataToCourse()
{
    ofstream outfile("../Qt/Course.txt");
    qCritical()<<startRegDate.toString(Qt::ISODate); // Print the current date in ISO format
    qCritical()<<endRegDate.toString(Qt::ISODate); // Print the current date in ISO format
    outfile<<startRegDate.toString(Qt::ISODate).toStdString()<<el ;
    outfile<<endRegDate.toString(Qt::ISODate).toStdString()<<el ;
    outfile << course.size() << '\n';
        for (int i = 0; i < course.size(); i++)
        {
            outfile << course[i].name << "\n" << (int)course[i].isElective << "\n" << course[i].instructor << "\n" << course[i].hours << "\n" << course[i].MaxNumOfStud << '\n';
        outfile<<course[i].x<<' '<<course[i].y<<'\n' ;
        outfile << course[i].PreReqCourses.size() << '\n';
            for (auto& x : course[i].PreReqCourses)
                outfile << x << '\n';
            outfile<<course[i].CurStudents.size()<<'\n' ;
            for(auto &[f,s] : course[i].CurStudents)
                outfile<<f<<' '<<s<<'\n' ;
        }
    outfile.close();
}

void Data::LoadDataFromCourse()
{
    ifstream infile("../Qt/Course.txt");
    int elec, sz;
    if (infile.is_open())
    {
            string s ;
            infile>>s ;
            QString dateString = QString::fromStdString(s); // Example string representing a date
            QDate convertedDate = QDate::fromString(dateString, Qt::ISODate);
            startRegDate = convertedDate ;
            infile>>s ;
             dateString = QString::fromStdString(s); // Example string representing a date
             convertedDate = QDate::fromString(dateString, Qt::ISODate);
            endRegDate = convertedDate ;
            infile >> sz;
        course = vector<Course>(sz);
        for (int i = 0; i < sz; i++)
        {
            infile.ignore();
            getline(infile,course[i].name) ;
            infile  >> elec  ;
            course[i].isElective = elec;
            infile.ignore();
            getline(infile,course[i].instructor) ;
            infile>> course[i].hours >> course[i].MaxNumOfStud;
            infile>>course[i].x>>course[i].y;
            int preqSz;
            infile >> preqSz;
            for (int j = 0, x; j < preqSz; j++)
                infile >> x, course[i].PreReqCourses.insert(x);
            int szCurrentStudents ;
            infile >>szCurrentStudents ;
            for(int j =0 , x, y ;j< szCurrentStudents ;j++)
                infile>>x>>y  , course[i].CurStudents.emplace(x,y) ;
        }
    }
    infile.close();
}

void Data::UploadDataToStudent()
{
    ofstream outfile("../Qt/Student.txt");
    if (outfile.is_open())
    {
        outfile << student.size() << '\n';
        for(auto &syear : student)
        {
            outfile << syear.size()<< '\n';
            for (auto& s : syear)
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

                outfile << s.courseGPA.size() <<'\n';
                for (auto& cg : s.courseGPA)
                    outfile << cg << '\n';
            }
        }
    }
    outfile.close();
}

void Data::LoadDataFromStudent()
{
    ifstream infile("../Qt/Student.txt");

    int sz;
    if (infile.is_open() && (infile >> sz))
    {
        student = vector<vector<Student>>(sz);
        for (auto& syear : student)
        {
            int szs ;
            infile >>szs ;
            syear= vector<Student>(szs) ;
            for(auto &s:syear)
            {
                infile.ignore();
                getline(infile, s.name);
                infile >> s.ID;
                string email, password;
                infile >> email;
                infile.ignore();
                getline(infile, password) ;
                s.setEmail(email);
                s.setPassword(password);
                infile >> s.maximumHoursAllowed >> s.academicYear >> s.academicSemster >> s.CGPA;
                infile >> sz;
                s.progressCourses = vector<int>(sz);
                for (auto& pc : s.progressCourses)
                    infile >> pc;

                infile >> sz;
                s.finishedCourses = vector<bool>(sz) ;
                for (int i = 0, x; i < sz; i++)
                    infile >> x, s.finishedCourses[i]=x ;

                infile >> sz;
                s.courseGPA = vector<float>(sz);
                for (auto& cg : s.courseGPA)
                    infile >> cg;
            }
        }
    }
    infile.close();
}
QString Data::string_to_Qstring(string s){
    return QString::fromStdString(s) ;
}



