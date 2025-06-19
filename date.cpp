#include "date.h"

#include <ctime>
#include <sstream>
Date::Date(long sec) {
  this->sec = sec;
  this->strform = "";
  // # of seconds from January 1st 1970
  int seconds = sec % 60, minutes = sec / 60, hours = minutes / 60,
      days = hours / 24, years = 1970;
  hours %= 24;
  minutes %= 60;
  while (days >= 365) {
    if (isLeapYear(years)) {
      if (days > 365) {
        days -= 366;
        years++;
      } else {
        break;
      }
    } else {
      days -= 366;
      years++;
    }
  }
  int months_length[] = {
      31, 28 + isLeapYear(years), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int months = 0;
  while (days >= months_length[months]) {
    days -= months_length[months];
    months++;
  }
  this->day = days + 1;
  this->month = months + 1;
  this->year = years;
  this->hour = hours;
  this->minute = minutes;
  this->second = seconds;
}
string Date::getStrForm() {
  if (this->strform == "") {
    ostringstream oss;
    string weekdays[] = {"Mon", "Tue", "Wen", "Thu", "Fri", "Sat", "Sun"};
    Date *today = new Date(time(nullptr));
    if (today->month == this->month && today->year == this->year &&
        today->day - this->day <= 7) {
      // if it's the same week, use weekdays,
      // unless it's today, in which case just
      // tell the hours.
      if (today->day != this->day) oss << weekdays[this->day - 1] << " ";
    } else {
      oss << this->day << "/" << this->month << "/" << this->year << " ";
    }
    oss << this->hour << ":" << this->minute << ":" << this->second;
    this->strform = oss.str();
    delete today;
  }
  return this->strform;
}
