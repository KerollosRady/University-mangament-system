#include <QWidget>
#include "data.h"
Data::Data()
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
            (!byins || course[i].instructor==Instructor ))
            v.push_back(i) ;
    }
    return v;
}


