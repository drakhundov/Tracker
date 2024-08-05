#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;
#define isLeapYear(year) (year % 4 == 0)
class Date {
   public:
    Date(long);  // seconds returned by time(nullptr).
    ~Date(){}
    short getDay() { return day; }
    short getMonth() { return month; }
    short getYear() { return year; }
    short getHour() { return hour; }
    short getMinute() { return minute; }
    short getSecond() { return second; }
    string getStrForm();

   private:
    short day, month, year, hour, minute, second;
    long sec;
    string strform;
};
#endif
