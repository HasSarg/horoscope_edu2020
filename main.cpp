#include <vector>
#include "person.h"

int main()
{
  unsigned int n;
  std::cin >> n;
  std::string name;
  std::string last_name;
  unsigned int year;
  unsigned int month;
  unsigned int day;
  std::vector<PERSON::Person> persons;
  for(int i = 0; i < n; ++i) {
    std::cin >> name >> last_name >> year >> month >> day;
    persons.push_back(PERSON::Person{name, last_name, year, month, day});
  }
  for(int i = 0; i < n; ++i) {
    persons[i].print();
  }
  return 0;
}
