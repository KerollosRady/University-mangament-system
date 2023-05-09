
#include "filtercourses.h"

filtercourses::filtercourses()
{

}
set<int> filtercourses::filter(int elective, int hours, const string &Instructor)
{
    bool bye = (elective != -1),
        byh = (hours != -1),
        byins = (Instructor != "-1");
    set<int> s;
    if (bye)
        for (auto a : filterByElectivity[elective])
            s.insert(a);
    if (byh)
        for (auto a : filterByHours[hours])
            s.insert(a);
    if (byins)
        for (auto a : filterByInstructor[Instructor])
            s.insert(a);
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

