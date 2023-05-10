#include "data.h"

Data::Data()
{

}

set<int> Data::filter(int elective, int hours, const string &Instructor)
{
    bool bye = (elective != -1),
        byh = (hours != -1),
        byins = (Instructor != "-1");

    set<int> s={};
    for(int i=0 ;i<course.size();i++)
        s.insert(i) ;

    auto it = s.begin();
    while (it != s.end())
    {
        int a = *it;
        if ((!bye || filterByElectivity[elective].find(a) != filterByElectivity[elective].end()) &&
            (!byh || filterByHours[hours].find(a) != filterByHours[hours].end()) &&
            (!byins || filterByInstructor[Instructor].find(a) != filterByInstructor[Instructor].end()))
            it++;
        else
            it = s.erase(it);
    }
    return s;
}


