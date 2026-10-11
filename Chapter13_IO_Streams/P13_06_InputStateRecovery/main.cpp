#include <iostream>
#include <limits>
using namespace std;
int main(){
    int x;
    while(true){
        cout << "Input an integer: ";
        if(cin >> x){ cout << "OK, x = " << x << endl; break; }
        cout << "Invalid input. Recovering..." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}
