#include <iostream>
using namespace std;

class CDate {
public:
    bool setDate(int y, int m, int d) {
        if (!isValidDate(y, m, d)) return false;
        year = y; month = m; day = d;
        return true;
    }
    void show() const { cout << year << '-' << month << '-' << day << '\n'; }
    void nextDay() {
        ++day;
        if (day > daysInMonth(year, month)) {
            day = 1;
            ++month;
            if (month > 12) { month = 1; ++year; }
        }
    }
private:
    int year{2000};
    int month{1};
    int day{1};

    static bool isLeap(int y) {
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }
    static int daysInMonth(int y, int m) {
        static const int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if (m == 2 && isLeap(y)) return 29;
        return days[m];
    }
    static bool isValidDate(int y, int m, int d) {
        if (y <= 0 || m < 1 || m > 12) return false;
        return d >= 1 && d <= daysInMonth(y, m);
    }
};

int main() {
    CDate d;
    const int tests[][3] = {{2026,9,7},{2026,9,30},{2026,12,31},{2024,2,28},{2025,2,28}};
    for (const auto& x : tests) {
        if (d.setDate(x[0], x[1], x[2])) {
            d.show();
            cout << "next day: ";
            d.nextDay();
            d.show();
            cout << "---\n";
        }
    }
    return 0;
}
