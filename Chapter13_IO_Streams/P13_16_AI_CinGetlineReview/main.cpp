#include <iostream>
#include <sstream>
#include <string>
#include <limits>
using namespace std;
void buggy()
{
	istringstream input("20\nTom Smith\n"); 
	int age; 
	string name;
	input>>age; 
	getline(input,name); 
	cout<<"[buggy] age="<<age<<", name=["<<name<<"]"<<endl; 
}
void fixed()
{ 
	istringstream input("20\nTom Smith\n"); 
	int age; 
	string name;
	input>>age; 
	input.ignore(numeric_limits<streamsize>::max(),'\n');
	getline(input,name); 
	cout<<"[fixed] age="<<age<<", name=["<<name<<"]"<<endl; 
}
int main()
{
	buggy();
	fixed();
	return 0;
}
