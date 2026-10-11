#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double x=3.14159;
    cout << "setprecision(2): " << setprecision(2) << x << endl;
    cout << "fixed + setprecision(2): " << fixed << setprecision(2) << x << endl;
    cout << "\nsetw only affects the next field:" << endl;
    cout << setw(10) << 12 << "|" << 34 << endl;
    cout << "\nScore table:" << endl;
    cout << left << setw(12) << "Name" << right << setw(8) << "Score" << endl;
    cout << left << setw(12) << "Tom" << right << fixed << setprecision(1) << setw(8) << 92.5 << endl;
    cout << left << setw(12) << "Alice" << right << setw(8) << 88.0 << endl;
    cout << "\nsetfill example:" << endl;
    cout << setfill('0') << setw(6) << 25 << endl;
    return 0;
}
