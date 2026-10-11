#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    {
        ofstream out("scores_bad.txt"); 
        out<<"Tom 90"<<endl<<"Alice 95"<<endl<<"Bob abc"<<endl<<"Jack 88"<<endl;
    }

    ifstream in("scores_bad.txt"); 
    if(!in)
    {
        cerr<<"open error"<<endl;
        return 1;
    }
    string name; double score;
    while(in>>name>>score)
        cout<<name<<" "<<score<<endl;
    cout<<endl;
    if(in.eof())
        cout<<"Loop ended at EOF."<<endl;
    else if(in.fail()) 
        cout<<"Loop ended because the data format was invalid."<<endl;
    else if(in.bad())
        cout<<"Serious I/O error."<<endl;
    return 0;
}
