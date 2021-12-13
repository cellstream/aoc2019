#include "common.h"
#include "intcode/cpu.h"

#include <vector>

int main(int argc, char* argv[]) {
  auto streams = read_file_into_streams("inputs/day02.real", {','});
  std::vector<int> part1_memory;
  std::vector<int> part2_memory;
  for (auto& stream : streams) {
    while (stream.good()) {
      int instruction;
      stream >> instruction;
      part1_memory.push_back(instruction);
      part2_memory.push_back(instruction);
    }
  }

  part1_memory.at(1) = 12;
  part1_memory.at(2) = 2;
  intcode_computer part1_cpu(part1_memory);
  while (part1_cpu.execute_instruction() != run_state::halted) {
  }

  answer(1, part1_cpu.access_memory(0));

  for (auto noun = 0; noun <= 99; ++noun) {
    for (auto verb = 0; verb <= 99; ++verb) {
      part2_memory.at(1) = noun;
      part2_memory.at(2) = verb;
      intcode_computer part2_cpu{part2_memory};
      while (part2_cpu.execute_instruction() != run_state::halted) {
      }

      if (part2_cpu.access_memory(0) == 19690720) {
        answer(2, 100 * noun + verb);
      }
    }
  }

  return 0;
}