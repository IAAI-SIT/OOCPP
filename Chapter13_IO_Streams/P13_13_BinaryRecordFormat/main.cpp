#include <iostream>
#include <fstream>
using namespace std;
struct StudentRecord
{
    int id; 
    double score;
};

bool writeRecord(ofstream& out,const StudentRecord& s)
{
    out.write(reinterpret_cast<const char*>(&s.id),sizeof(s.id));
    out.write(reinterpret_cast<const char*>(&s.score),sizeof(s.score));
    return static_cast<bool>(out);
}
bool readRecord(ifstream& in,StudentRecord& s)
{
    in.read(reinterpret_cast<char*>(&s.id),sizeof(s.id));
    in.read(reinterpret_cast<char*>(&s.score),sizeof(s.score));
    return static_cast<bool>(in);
}
int main()
{
    StudentRecord a[3]={{1001,90.0},{1002,95.5},{1003,82.0}};
    ofstream out("students.bin",ios::binary); 
    if(!out)
    {
        cerr<<"open error"<<endl;
        return 1;
    }
    int count=3;
    out.write(reinterpret_cast<const char*>(&count),sizeof(count));
    for(int i=0;i<count;++i) 
        if(!writeRecord(out,a[i]))
        {
            cerr<<"write error"<<endl;
            return 1;
        }
    out.close();
    ifstream in("students.bin",ios::binary); 
    if(!in)
    {
        cerr<<"open error"<<endl;
        return 1;
    }
    int n=0; in.read(reinterpret_cast<char*>(&n),sizeof(n));
    if(!in||n<0||n>1000)
    {
        cerr<<"bad file format"<<endl;
        return 1;
    }
    for(int i=0;i<n;++i)
    {
        StudentRecord s;
        if(!readRecord(in,s))
        {
            cerr<<"incomplete record"<<endl;
            return 1;
        }
        cout<<s.id<<" "<<s.score<<endl;
    }
    return 0;
}
