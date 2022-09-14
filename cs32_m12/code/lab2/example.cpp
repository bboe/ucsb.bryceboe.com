// example.cpp - Example class definition, application and implementation
// for use as a guide/reminder for CS 32 lab2

#include <iostream>
using namespace std;

class SimpleDate {

public:
    void set(int, int, int);
    void print() const;

private:
  int month, day, year;
};

SimpleDate getDate();

int main() {
    SimpleDate d = getDate();
    cout << "Your date: ";
    d.print();
    cout << endl;
    return 0;
}

SimpleDate getDate() {
    SimpleDate result;
    int m, d, y;
    cout << "Enter month day year --> ";
    cin >> m >> d >> y;
    result.set(m, d, y);
    return result;
}

void SimpleDate::set(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
}

void SimpleDate::print() const {
    cout << month << "/" << day << "/" << year;
}
