#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int data[3]={10,20,30};
    ofstream out("data.bin",ios::binary); 
    if(!out)
    {
        cerr<<"open write error"<<endl;
        return 1;
    }
    out.write(reinterpret_cast<const char*>(data),sizeof(data)); 
    if(!out)
    {
        cerr<<"write error"<<endl;
        return 1;
    } 
    out.close();
    int loaded[3]={0,0,0};
    ifstream in("data.bin",ios::binary);
    if(!in)
    {
        cerr<<"open read error"<<endl;
        return 1;
    }
    in.read(reinterpret_cast<char*>(loaded),sizeof(loaded)); 
    if(!in)
    {
        cerr<<"read error"<<endl;
        return 1;
    }
    in.close();
    cout<<"loaded: "; 
    for(int i=0;i<3;++i) 
        cout<<loaded[i]<<" "; 
    cout<<endl; 
    return 0;
}
