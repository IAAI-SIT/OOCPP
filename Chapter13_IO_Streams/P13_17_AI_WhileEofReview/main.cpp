#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void createFile()
{
	ofstream out("scores.txt");
	out<<"Tom 90"<<endl<<"Alice 95"<<endl;
}
void wrongRead()
{
	ifstream in("scores.txt");
	string name;
	double score=0;
	cout<<"[wrong while(!eof())]"<<endl;
	while(!in.eof())
	{
		in>>name>>score;cout<<name<<" "<<score<<endl;
	}
}
void correctRead()
{
	ifstream in("scores.txt");
	string name;
	double score=0;
	cout<<"\n[correct while(in >> name >> score)]"<<endl;
	while(in>>name>>score)
		cout<<name<<" "<<score<<endl;
}
int main()
{
	createFile();
	wrongRead();
	correctRead();
	return 0;
}
