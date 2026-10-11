#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void showFile(const string& fn)
{
    ifstream in(fn.c_str()); 
    string line;
    cout << "---- " << fn << " ----" << endl;
    while(getline(in,line)) 
        cout << line << endl;
}
int main()
{
    const string fn="log.txt";
    ofstream out1(fn.c_str());
    if(!out1)
    {
        cerr<<"open error"<<endl;
        return 1;
    } 
    out1<<"A"<<endl;
    out1.close();
    ofstream out2(fn.c_str());
    out2<<"B"<<endl; 
    out2.close();
    showFile(fn);
    ofstream out3(fn.c_str(),ios::app);
    out3<<"C"<<endl; 
    out3.close();
    showFile(fn);
    return 0;
}
