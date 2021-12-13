#pragma once

#include "common.h"

#include <string>
#include <vector>

class instruction {
 public:
  virtual instruction_result execute() = 0;
  virtual std::string to_string() const = 0;
};

class instruction_add : public instruction {
 public:
  instruction_add(std::vector<int> instruction_data, std::vector<int>& memory);

  instruction_result execute() override;
  std::string to_string() const override;

 private:
  std::vector<int>& m_memory;
  int m_input_one;
  int m_input_two;
  int m_destination_address;
};

class instruction_mul : public instruction {
 public:
  instruction_mul(std::vector<int> instruction_data, std::vector<int>& memory);

  instruction_result execute() override;
  std::string to_string() const override;

 private:
  std::vector<int>& m_memory;
  int m_input_one;
  int m_input_two;
  int m_destination_address;
};

class instruction_term : public instruction {
 public:
  instruction_term(std::vector<int> instruction_data);

  instruction_result execute() override;
  std::string to_string() const override;
};