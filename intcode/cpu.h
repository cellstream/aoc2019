#pragma once

#include "common.h"

#include <vector>

class intcode_computer {
 public:
  intcode_computer(const std::vector<int>& memory);
  intcode_computer(const std::vector<int>& memory, int ip);

  run_state execute_instruction(bool print = false);

  int access_memory(int position) const;

 private:
  int m_ip;
  std::vector<int> m_memory;
};
