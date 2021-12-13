#pragma once

enum class run_state { running, halted };

struct instruction_result {
  int instruction_pointer_delta;
  run_state new_run_state;
};