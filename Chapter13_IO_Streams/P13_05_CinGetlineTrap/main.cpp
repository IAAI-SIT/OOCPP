#include <iostream>
#include <string>
#include <limits>
using namespace std;
int main()
{
    int age; string name;
    cout << "Input age: ";
    cin >> age;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Input full name: ";
    getline(cin,name);
    cout << "age = " << age << endl;
    cout << "name = " << name << endl;
    return 0;
}
