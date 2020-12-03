// Copyright 2020 Kavykin Andrey Kaviandr@yandex.ru

#include "parser.hpp"

Student get_student_from_json(const nlohmann::json& j) {
  Student s;
  const int arg_one = 1;
  const int arg_two = 2;
  if (j.at("name").size() == arg_one)
    s.Name = j.at("name");
  else
    throw std::runtime_error{"invalid name exists in file"};

  if (j.at("group").size() == arg_one) {
    s.Group = j.at("group").dump();
    if (s.Group[0] == '\"')
      s.Group = s.Group.substr(arg_one, s.Group.size() - arg_two);
  } else {
    throw std::runtime_error{"invalid group exists in file"};
  }

  if (j.at("avg").size() == arg_one) {
    s.Avg = j.at("avg").dump();
    if (s.Avg[0] == '\"') s.Avg = s.Avg.substr(arg_one, s.Avg.size() - arg_two);
  } else {
    throw std::runtime_error{"invalid avg exists in file"};
  }

  if (j.at("debt").size() > arg_one) {
    s.Debt = std::to_string(j.at("debt").size()) + " items";
  }
  if (j.at("debt").size() == 0) s.Debt = "null";
  if (j.at("debt").size() == arg_one) {
    s.Debt = j.at("debt").dump();
    if (s.Debt[0] == '\"')
      s.Debt = s.Debt.substr(arg_one, s.Debt.size() - arg_two);
  }

  return s;
}

std::vector<Student> get_vector_from_json(const nlohmann::json& data) {
  std::vector<Student> students;
  for (auto const& student : data.at("items")) {
    students.push_back(get_student_from_json(student));
  }
  return students;
}

void print(const std::vector<Student>& students) {
  const int arg_fiften = 15;
  std::cout
      << "|name           |group          |avg            |debt           |"
      << std::endl
      << "|---------------|---------------|---------------|---------------|"
      << std::endl;
  std::cout.setf(std::ios::left);
  for (auto const& student : students) {
    std::cout << "|" << std::setw(arg_fiften) << student.Name;
    std::cout << "|" << std::setw(arg_fiften) << student.Group;
    std::cout << "|" << std::setw(arg_fiften) << student.Avg;
    std::cout << "|" << std::setw(arg_fiften) << student.Debt;
    std::cout
        << "|" << std::endl
        << "|---------------|---------------|---------------|---------------|"
        << std::endl;
  }
}

bool is_valid_meta(const nlohmann::json& data,
                   const std::vector<Student>& students) {
  return data.at("_meta").at("count") == students.size();
}
