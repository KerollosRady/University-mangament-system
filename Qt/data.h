#include<vector>
#include<set>
#include<unordered_map>
#include<string>
using namespace std ;
#define s1      Data::filterByElectivity
#define s2      Data::filterByHours
#define s3      Data::filterByInstructor

class Data
{
public:
    Data();
    static    unordered_map<string,set<int>> filterByInstructor ;
    static    vector<set<int>>               filterByHours      ;
    static    vector<set<int>>               filterByElectivity ;
    set<int> filter( bool bye ,bool byh , bool byins , bool elective , int hours , const string &Instructor){
        set<int> s  ;
        if(bye)
            for(auto a : s1[elective])
                s.insert(a) ;
        if(byh)
            for(auto a: s2[hours])
                s.insert(a) ;
        if(byins)
            for(auto a :s3[Instructor])
                s.insert(a) ;
        auto it = s.begin() ;
        while(it!=s.end())
        {
            int a = *it ;
            if((!bye || s1[elective].find(a)!=s1[elective].end())&&
                (!byh || s2[hours].find(a)!=s2[hours].end()) &&
                (!byins || s3[Instructor].find(a)!=s3[Instructor].end()))
                it++ ;
            else
                it = s.erase(it);
        }
        return s;
    }
};


