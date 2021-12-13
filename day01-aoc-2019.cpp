#include "common.h"

#include <iostream>

int calculate_fuel(int mass) {
  return (mass / 3) - 2;
}

int calculate_total_fuel(int mass) {
  auto total_fuel{0};
  auto required_fuel{calculate_fuel(mass)};
  while (required_fuel > 0) {
    total_fuel += required_fuel;
    required_fuel = calculate_fuel(required_fuel);
  }

  return total_fuel;
}

int main(int argc, char* argv[]) {
  auto part1{0};
  auto part2{0};
  auto streams = read_file_into_streams("inputs/day01.real");
  for (auto& stream : streams) {
    int mass{0};
    stream >> mass;
    part1 += calculate_fuel(mass);
    part2 += calculate_total_fuel(mass);
  }

  answer(1, part1);
  answer(2, part2);

  return 0;
}