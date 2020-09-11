#pragma once
#include <iostream>

namespace PERSON {
 const int Min_year = 1910;
 const int Max_year = 2020;
 const int Min_month = 1;
 const int Max_month = 12;

 class Person {
 private:
   std::string m_name;
   std::string m_last_name;
   unsigned int m_year;
   unsigned int m_month;
   unsigned int m_day;
   unsigned int m_max_days;
   std::string m_zodiac_sign_month;
   std::string m_zodiac_sign_year;
 public:
   Person(std::string name, std::string last_name, unsigned int year,
          unsigned int month, unsigned int day);
   void print() const;
 private:
   void set_max_days();
   void check_set_day();
   void check_set_month();
   bool is_leap_year();
   bool is_less_than_min();
   bool is_more_than_max();
   void set_year();
   void set_zodiac_sign_month();
   void set_zodiac_sign_year();
 };
}
