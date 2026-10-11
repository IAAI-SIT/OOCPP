#include <iostream>
#include <string>
using namespace std;
int main()
{
    string name; int score;
    cout << "Try: Tom 90   or   Tom Smith 90\\n> ";
    cin >> name >> score;
    if(!cin)
    { 
        cerr << "Expected: <one-word-name> <number>" << endl; 
        return 1; 
    }
    cout << "name = " << name << endl;
    cout << "score = " << score << endl;
    return 0;
}
