// Copyright 2020 Kavykin Andrey Kaviandr@yandex.ru

#ifndef INCLUDE_PARSER_HPP_
#define INCLUDE_PARSER_HPP_

#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "nlohmann/json.hpp"
#include "student.hpp"

using std::cout;

Student get_student_from_json(const nlohmann::json& j);

std::vector<Student> get_vector_from_json(const nlohmann::json& data);

void print(const std::vector<Student>& students);

bool is_valid_meta(const nlohmann::json& data,
                   const std::vector<Student> students);

#endif  // INCLUDE_PARSER_HPP_
