// Copyright 2020 Kavykin Andrey Kaviandr@yandex.ru

#ifndef INCLUDE_STUDENT_HPP_
#define INCLUDE_STUDENT_HPP_

#include <any>
#include <iostream>
#include <string>

struct Student {
  std::string Name;
  std::string Group;
  std::string Avg;
  std::string Debt;

  friend bool operator==(const Student& lhs, const Student& rhs);
};
#endif  // INCLUDE_STUDENT_HPP_
