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

  /* Friends can access private variables */
  friend bool equal(const Date &lhs, const Date &rhs);
  /* Similar to above (note the use of const) */
  bool equal(const Date &other) const;

  /* Overloaded equality operator (can only use one or the other) */
  //friend bool operator ==(const Date &lhs, const Date &rhs);
  bool operator ==(const Date &other) const;

  /* Overloaded plus operator */
  Date operator +(int num_days) const;
  friend Date operator +(int lhs, const Date &rhs);

  /* Overloaded unary plus */
  Date operator +() const;

  /* Overloaded << (must be a friend) */
  friend ostream& operator <<(ostream& stream, const Date &date);

  /* Overloaded >> (must be a friend) */
  friend istream& operator >>(istream& stream, Date &date);

private:
  int day;
  int month;
  int year;
};

bool equal(const Date &lhs, const Date &rhs) {
  return lhs.day == rhs.day && lhs.month == rhs.month && lhs.year == rhs.year;
}

bool Date::equal(const Date &other) const {
  /* Compiler error if we attempt to do any of the following (or similar) */
  //++day;
  //other.day = 0;
  return day == other.day && month == other.month && year == other.year;
}


/*
bool operator ==(const Date &lhs, const Date &rhs) {
  return lhs.day == rhs.day && lhs.month == rhs.month && lhs.year == rhs.year;
}
*/

bool Date::operator ==(const Date &other) const {
  return day == other.day && month == other.month && year == other.year;
}

Date Date::operator +(int num_days) const {
  Date retval(day, month, year);
  retval.day += num_days;
  return retval;
}

Date operator +(int lhs, const Date &rhs) {
  Date retval(rhs.day, rhs.month, rhs.year);
  retval.day += lhs;
  return retval;
}

Date Date::operator +() const {
  Date retval(day, month, year);
  return retval;
}

ostream& operator <<(ostream& stream, const Date &date) {
  return stream << date.day << "/" << date.month << "/" << date.year;
}

istream& operator >>(istream& stream, Date &date) {
  return stream >> date.day >> date.month >> date.year;
}



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

/* Update the date using individual elements */
void Date::update_date(int d, int m, int y) {
  day = d;
  month = m;
  year = y;
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
  Date date_b(20, 8, 2012);
  date_a.update_date(date_b);

  /* Output the dates */
  date_a.output(cout);
  date_b.output(cout);


  /* Test equality */
  cout << (equal(date_a, date_b) ? "Equal" : "Not equal") << endl;
  cout << (date_a.equal(date_b) ? "Equal" : "Not equal") << endl;
  cout << (date_a == date_b ? "Equal" : "Not equal") << endl;

  /* Use the overloaded plus operators */
  (+date_a + 5).output(cout);
  (10 + date_a).output(cout);

  /* Use the overloaded << operator */
  cout << date_a << " " << date_b << endl;

  /* Use the overloaded >> operator */
  cout << "Input a date (day month year): ";
  cin >> date_a;
  cout << date_a << endl;
  return 0;
}
