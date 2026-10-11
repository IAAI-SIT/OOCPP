#include <iostream>
using namespace std;
int main()
{
    char ch;
    cout << "Input one line; spaces will be removed:" << endl;
    while(cin.get(ch) && ch!='\n')
        if(ch!=' ') 
            cout.put(ch);
    cout.put('\n');
    return 0;
}
