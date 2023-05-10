#ifndef FILTERCOURSES_H
#define FILTERCOURSES_H
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std ;

class filtercourses
{
public:
    filtercourses();
    vector<set<int>> filterByElectivity;
    vector<set<int>> filterByHours;
    unordered_map<string, set<int>> filterByInstructor;
    set<int> filter(int elective, int hours, const string &Instructor);
};

#endif // FILTERCOURSES_H
