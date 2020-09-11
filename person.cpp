#include "person.h"

PERSON::Person::Person(std::string name, std::string last_name, unsigned int year,
               unsigned int month, unsigned int day)
               : m_name(name)
               , m_last_name(last_name)
               , m_year(year)
               , m_month(month)
               , m_day(day)
{
    set_year();
    set_month();
    set_day();
    set_zodiac_sign_year();
    set_zodiac_sign_month();
}

void PERSON::Person::print() const
{
  std::cout << m_name << " " << m_last_name << " "  << m_zodiac_sign_year
            << " " << m_zodiac_sign_month << std::endl;
}

void PERSON::Person::set_max_days()
{
  switch(m_month) {
    case 4: case 6: case 9: case 11:
      m_max_days = 30;
      break;
    case 2:
      if(is_leap_year()) {
        m_max_days = 29;
      }else{
        m_max_days = 28;
      }
      break;
    default:
      m_max_days = 31;
  }
}

bool PERSON::Person::is_less_than_min(int m, int min)
{
  if(m < min) {
    return true;
  }
  return false;
}

bool PERSON::Person::is_more_than_max(int m, int max)
{
  if(m > max) {
    return true;
  }
  return false;
}

bool PERSON::Person::is_leap_year()
{
  if ((m_year % 4 == 0 && m_year % 100 != 0) || m_year % 400 == 0) {
    return true;
  }
  return false;
}

void PERSON::Person::set_year()
{
  if(is_less_than_min(m_year, Min_year)) {
    m_year = Min_year;
  } else if (is_more_than_max(m_year, Max_year)) {
    m_year = Max_year;
  }
}

void PERSON::Person::set_month()
{
  if(is_less_than_min(m_month, Min_month)) {
    m_month = Min_month;
  } else if(is_more_than_max(m_month, Max_month)) {
    m_month = Max_month;
  }
}

void PERSON::Person::set_day()
{
  set_max_days();
  if(is_less_than_min(m_day, Min_day)) {
    m_day = Min_day;
  } else if (is_more_than_max(m_day, m_max_days)) {
    m_day = m_max_days;
  }
}

void PERSON::Person::set_zodiac_sign_year()
{
  std::string zodiac_year_signs[12] = {"Monkey", "Rooster", "Dog", "Pig",
                                       "Rat", "Ox", "Tiger", "Rabbit",
                                       "Dragon", "Snake", "Horse", "Sheep"};
  unsigned int rem = m_year % 12;
  m_zodiac_sign_year = zodiac_year_signs[rem];
}

void PERSON::Person::set_zodiac_sign_month()
{
  if((m_month == 12 and m_day > 23) or (m_month == 1 and m_day < 21)) {
    m_zodiac_sign_month = "Capricorn";
  } else if((m_month == 1 and m_day > 22) or (m_month == 2 and m_day < 19)) {
    m_zodiac_sign_month = "Aquarius";
  } else if((m_month == 2 and m_day > 20) or (m_month == 3 and m_day < 21)) {
    m_zodiac_sign_month = "Pisces";
  } else if((m_month == 3 and m_day > 22) or (m_month == 4 and m_day < 21)) {
    m_zodiac_sign_month = "Aries";
  } else if((m_month == 4 and m_day > 22) or (m_month == 5 and m_day < 22)) {
    m_zodiac_sign_month = "Taurus";
  } else if((m_month == 5 and m_day > 23) or (m_month == 6 and m_day < 22)) {
    m_zodiac_sign_month = "Gemini";
  } else if((m_month == 6 and m_day > 23) or (m_month == 7 and m_day < 23)) {
    m_zodiac_sign_month = "Cancer";
  } else if((m_month == 7 and m_day > 24) or (m_month == 8 and m_day < 24)) {
    m_zodiac_sign_month = "Leo";
  } else if((m_month == 8 and m_day > 25) or (m_month == 9 and m_day < 23)) {
    m_zodiac_sign_month = "Virgo";
  } else if((m_month == 9 and m_day > 24) or (m_month == 10 and m_day < 24)) {
    m_zodiac_sign_month = "Libra";
  } else if((m_month == 10 and m_day > 25) or (m_month == 11 and m_day < 23)) {
    m_zodiac_sign_month = "Scorpio";
  } else if((m_month == 11 and m_day > 24) or (m_month == 12 and m_day < 22)) {
    m_zodiac_sign_month = "Sagittarius";
  }
}
