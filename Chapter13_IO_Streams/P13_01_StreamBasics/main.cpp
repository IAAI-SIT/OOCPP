#include <iostream>
using namespace std;
int main()
{
    int id; double score;
    cout << "Input id and score: ";
    cin >> id >> score;
    if(!cin)
    {
        cerr << "Input format error." << endl;
        return 1;
    }
    cout << "id = " << id << ", score = " << score << endl;
    clog << "[log] input/output finished." << endl;
    return 0;
}
