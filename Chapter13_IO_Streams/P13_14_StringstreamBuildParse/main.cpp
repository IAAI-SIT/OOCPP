#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
    ostringstream out; 
    out<<"id="<<1001<<", score="<<fixed<<setprecision(1)<<92.5;

    string text=out.str(); 
    cout<<"built text: "<<text<<endl;

    string line="1002 Alice 88.5";
    istringstream in(line);
    int id; 
    string name;
    double score;
    if(in>>id>>name>>score)
        cout<<"parsed: "<<id<<" "<<name<<" "<<score<<endl;
    else 
        cout<<"bad record"<<endl;
    return 0;
}
