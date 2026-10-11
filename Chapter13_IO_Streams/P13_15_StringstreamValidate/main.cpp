#include <iostream>
#include <sstream>
#include <string>
using namespace std;
bool parseRecord(const string& line,string& name,double& score)
{
    istringstream in(line); 
    string extra;
    if(!(in>>name>>score)) 
        return false;
    if(in>>extra)
        return false;
    return true;
}
int main()
{
    string tests[4]={"Tom 88.5","Tom abc","Tom","Tom 88.5 extra"};
    for(int i=0;i<4;++i)
    {
        string name; 
        double score=0.0; 
        cout<<"["<<tests[i]<<"] -> "; 
        if(parseRecord(tests[i],name,score)) 
            cout<<"OK: "<<name<<" "<<score<<endl; 
        else 
            cout<<"BAD RECORD"<<endl;
    }
    return 0;
}
