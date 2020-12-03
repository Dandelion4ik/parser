// Copyright 2020 Kavykin Andrey Kaviandr@yandex.ru

#include <fstream>
#include <iostream>
#include <string>

#include "nlohmann/json.hpp"
#include "parser.hpp"

using nlohmann::json;

int main(int arguments_count, char* argument[]) {
  const int arg = 2;
  try {
    if (arguments_count > arg) throw std::runtime_error{"too much arguments"};

    std::string path;

    if (arguments_count == arg)
      path = argument[1];
    else
      std::getline(std::cin, path);

    std::ifstream file{path};

    if (!file) throw std::runtime_error{"unable to open json"};

    json data;
    file >> data;
    std::vector<Student> students;

    students = get_vector_from_json(data);

    if (is_valid_meta(data, students))
      print(students);
    else
      throw std::runtime_error{"invalid meta"};
  } catch (std::exception& exc) {
    std::cerr << "Exception catched: " << exc.what() << std::endl;
    return 1;
  }

  return 0;
}
