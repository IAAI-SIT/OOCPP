#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    const char* fn="scores.txt";
    ofstream out(fn);
    if(!out)
    {
        cerr<<"Cannot open output file."<<endl;
        return 1;
    }
    out<<"Tom 90"<<endl<<"Alice 95"<<endl<<"Bob 82.5"<<endl; 
    out.close();

    ifstream in(fn);
    if(!in)
    {
        cerr<<"Cannot open input file."<<endl;
        return 1;
    }
    string name; double score;
    while(in>>name>>score) 
        cout<<name<<" "<<score<<endl;
    in.close(); return 0;
}
