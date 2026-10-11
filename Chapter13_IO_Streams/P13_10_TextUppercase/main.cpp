#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    { 
        ofstream sample("input.txt"); 
        if(!sample)
        {
            cerr<<"cannot create input.txt"<<endl;
            return 1;
        }
        sample<<"Hello, C++ file stream!"<<endl<<"Tom 90, Alice 95."<<endl; 
    }
    ifstream in("input.txt"); 
    if(!in)
    {
        cerr<<"cannot open input.txt"<<endl;
        return 1;
    }
    ofstream out("output.txt"); 
    if(!out)
    {
        cerr<<"cannot open output.txt"<<endl;
        return 1;
    }
    char ch;
    while(in.get(ch))
    {
        if(ch>='a'&&ch<='z') 
            ch=ch-'a'+'A'; 
        out.put(ch); 
    }
    in.close();
    out.close();
    cout<<"Finished. Check output.txt."<<endl; return 0;
}
