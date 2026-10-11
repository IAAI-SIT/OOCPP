#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;
bool parseStudent(const string& line,string& name,double& score){
    istringstream in(line); string extra;
    if(!(in>>name>>score)) return false;
    if(in>>extra) return false;
    return true;
}
int main()
{
    {
        ofstream s("students.txt");

        if (!s)
        {
            cerr << "cannot create students.txt" << endl;
            return 1;
        }

        s << "Tom 90" << endl
            << "Alice 95.5" << endl
            << "Bob abc" << endl
            << "Jack 88 extra" << endl
            << "Mary 92" << endl;
    }

    ifstream in("students.txt");

    if (!in)
    {
        cerr << "cannot open students.txt" << endl;
        return 1;
    }

    ofstream report("report.txt");

    if (!report)
    {
        cerr << "cannot open report.txt" << endl;
        return 1;
    }

    report << left
        << setw(12) << "Name"
        << right
        << setw(8) << "Score"
        << endl;

    report << string(20, '-') << endl;

    string line;
    int lineNo = 0;
    int valid = 0;

    while (getline(in, line))
    {
        ++lineNo;

        if (line.empty())
        {
            continue;
        }

        string name;
        double score = 0;

        if (!parseStudent(line, name, score))
        {
            cerr << "Bad record at line "
                << lineNo
                << ": "
                << line
                << endl;

            continue;
        }

        report << left
            << setw(12) << name
            << right
            << fixed
            << setprecision(1)
            << setw(8) << score
            << endl;

        ++valid;
    }

    in.close();
    report.close();

    cout << "Finished. Valid records: "
        << valid
        << endl;

    cout << "Check report.txt." << endl;

    return 0;
}
