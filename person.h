#pragma once

#include <iostream>

#define MIN_YEAR 1910
#define MAX_YEAR 2020
#define MIN_MONTH 1
#define MAX_MONTH 12

class Person {
private:
  std::string m_name;
  std::string m_last_name;
  unsigned int m_year;
  unsigned int m_month;
  unsigned int m_day;
  unsigned int m_max_days;
  bool m_is_leap_year;
  std::string m_zodiac_sign_month;
  std::string m_zodiac_sign_year;
public:
  Person(std::string name, std::string last_name, unsigned int year,
         unsigned int  month, unsigned int day);
  void print() const;
private:
  void set_max_days();
  void check_set_day();
  void check_set_month();
  void check_set_year();
  void set_zodiac_sign_month();
  void set_zodiac_sign_year();
};
