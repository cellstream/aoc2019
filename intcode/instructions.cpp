#include "instructions.h"

#include <sstream>
#include <cassert>


instruction_add::instruction_add(std::vector<int> instruction_data, std::vector<int>& memory) : m_memory{memory} {
  assert(instruction_data.size() == 4);

  assert(instruction_data[1] >= 0);
  assert(instruction_data[1] < memory.size());

  assert(instruction_data[2] >= 0);
  assert(instruction_data[2] < memory.size());

  assert(instruction_data[3] >= 0);
  assert(instruction_data[3] < memory.size());

  m_input_one = memory.at(instruction_data[1]);
  m_input_two = memory.at(instruction_data[2]);
  m_destination_address = instruction_data[3];
}

instruction_result instruction_add::execute() {
  m_memory.at(m_destination_address) = m_input_one + m_input_two;
  return {4, run_state::running};
}

std::string instruction_add::to_string() const {
  std::stringstream ss;
  ss << "instruction_add: " << m_input_one << " + " << m_input_two << " = " << m_input_one + m_input_two << " into ["
     << m_destination_address << "]";
  return ss.str();
}

instruction_mul::instruction_mul(std::vector<int> instruction_data, std::vector<int>& memory) : m_memory{memory} {
  assert(instruction_data.size() == 4);

  assert(instruction_data[1] >= 0);
  assert(instruction_data[1] < memory.size());

  assert(instruction_data[2] >= 0);
  assert(instruction_data[2] < memory.size());

  assert(instruction_data[3] >= 0);
  assert(instruction_data[3] < memory.size());

  m_input_one = memory.at(instruction_data[1]);
  m_input_two = memory.at(instruction_data[2]);
  m_destination_address = instruction_data[3];
}

instruction_result instruction_mul::execute() {
  m_memory.at(m_destination_address) = m_input_one * m_input_two;
  return {4, run_state::running};
}

std::string instruction_mul::to_string() const {
  std::stringstream ss;
  ss << "instruction_mul: " << m_input_one << " * " << m_input_two << " = " << m_input_one * m_input_two << " into ["
     << m_destination_address << "]";
  return ss.str();
}

instruction_term::instruction_term(std::vector<int> instruction_data) {}

instruction_result instruction_term::execute() {
  return {0, run_state::halted};
}

std::string instruction_term::to_string() const {
  std::stringstream ss;
  ss << "instruction_term";
  return ss.str();
}