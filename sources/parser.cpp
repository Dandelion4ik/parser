// Copyright 2020 Kavykin Andrey Kaviandr@yandex.ru

#include "parser.hpp"

Student get_student_from_json(const nlohmann::json& j) {
  Student s;
  if (j.at("name").size() == 1)
    s.Name = j.at("name");
  else
    throw std::runtime_error{"invalid name exists in file"};

  if (j.at("group").size() == 1) {
    s.Group = j.at("group").dump();
    if (s.Group[0] == '\"') s.Group = s.Group.substr(1, s.Group.size() - 2);
  } else {
    throw std::runtime_error{"invalid group exists in file"};
  }

  if (j.at("avg").size() == 1) {
    s.Avg = j.at("avg").dump();
    if (s.Avg[0] == '\"') s.Avg = s.Avg.substr(1, s.Avg.size() - 2);
  } else {
    throw std::runtime_error{"invalid avg exists in file"};
  }

  if (j.at("debt").size() > 1) {
    s.Debt = std::to_string(j.at("debt").size()) + " items";
  }
  if (j.at("debt").size() == 0) s.Debt = "null";
  if (j.at("debt").size() == 1) {
    s.Debt = j.at("debt").dump();
    if (s.Debt[0] == '\"') s.Debt = s.Debt.substr(1, s.Debt.size() - 2);
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
  cout << "|name           |group          |avg            |debt           |"
       << std::endl
       << "|---------------|---------------|---------------|---------------|"
       << std::endl;
  cout.setf(std::ios::left);
  for (auto const& student : students) {
    cout << "|" << std::setw(15) << student.Name;
    cout << "|" << std::setw(15) << student.Group;
    cout << "|" << std::setw(15) << student.Avg;
    cout << "|" << std::setw(15) << student.Debt;
    cout << "|" << std::endl
         << "|---------------|---------------|---------------|---------------|"
         << std::endl;
  }
}

bool is_valid_meta(const nlohmann::json& data,
                   const std::vector<Student> students) {
  return data.at("_meta").at("count") == students.size();
}
