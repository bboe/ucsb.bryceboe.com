#include <cstdlib>
#include <iostream>
using namespace std;

class Date {
public:
  Date(int d, int m, int y);
  Date();
  void update_date(int d, int m, int y);
  void update_date(const Date &other);
  void output(ostream &stream);
private:
  int day;
  int month;
  int year;
};

/* Output the date in day/month/year format */
void Date::output(ostream &stream) {
  stream << day << "/" << month << "/" << year << endl;
}

/* Update the date using another date object */
void Date::update_date(const Date &other) {
  day = other.day;
  month = other.month;
  year = other.year;
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
  /* Perform date validation */
  if (day < 1 || day > 31 || month < 1 || month > 12) {
    cout << "Invalid date specification\n";
    exit(1);
  }
}

Date::Date() : day(0), month(0), year(0) {}


int main() {
  /* These all result in the similar instances of class Date */
  Date date_a;
  Date date_b(30, 12, 2012);
  date_a.update_date(date_b);
  date_a.output(cout);
  date_b.output(cout);
  return 0;
}
