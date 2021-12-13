#include "cpu.h"
#include "instructions.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <ranges>
#include <sstream>

const inline int k_words_per_instruction{4};

intcode_computer::intcode_computer(const std::vector<int>& memory) : intcode_computer(memory, 0) {}
intcode_computer::intcode_computer(const std::vector<int>& memory, int ip) : m_ip{ip}, m_memory{memory} {}

run_state intcode_computer::execute_instruction(bool print) {
  std::unique_ptr<instruction> current_instruction;
  const auto word_view = std::ranges::drop_view(m_memory, m_ip) | std::ranges::views::take(k_words_per_instruction);
  std::vector<int> instruction_data(word_view.begin(), word_view.end());
  const auto opcode = word_view.front();
  switch (opcode) {
    case 1: {
      current_instruction = std::make_unique<instruction_add>(instruction_data, m_memory);
      break;
    }
    case 2: {
      current_instruction = std::make_unique<instruction_mul>(instruction_data, m_memory);
      break;
    }
    case 99: {
      current_instruction = std::make_unique<instruction_term>(instruction_data);
      break;
    }
  }

  auto run_state = run_state::running;
  if (current_instruction) {
    auto result = current_instruction->execute();
    m_ip += result.instruction_pointer_delta;
    run_state = result.new_run_state;

    if (print) {
      std::cout << current_instruction->to_string() << " ip: " << m_ip << "\n";
    }
  }

  return run_state;
}

int intcode_computer::access_memory(int position) const {
  assert(position >= 0);
  assert(position < m_memory.size());
  return m_memory.at(position);
}