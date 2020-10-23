// Copyright 2020 Kavykin Andrey Kaviandr@yandex.ru

#include "student.hpp"

bool operator==(const Student& lhs, const Student& rhs) {
  return (lhs.Debt == rhs.Debt && lhs.Avg == rhs.Avg &&
          lhs.Group == rhs.Group && lhs.Name == rhs.Name);
}
