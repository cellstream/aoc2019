#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ranges>
#include <sstream>
#include <utility>
#include <vector>

std::vector<std::stringstream> read_file_into_streams(const std::string& filename,
                                                      const std::vector<char>& characters_to_remove = {}) {
  std::string line;
  std::ifstream file(filename);
  std::vector<std::stringstream> streams;
  while (std::getline(file, line)) {
    for (const auto& character_to_remove : characters_to_remove) {
      std::ranges::replace(line, character_to_remove, ' ');
    }
    streams.emplace_back(line);
  }
  return streams;
}

template <typename... Args>
void answer(int part, Args&&... args) {
  std::cout << "The answer to part " << part << " is ";
  ((std::cout << args << " "), ...);
  std::cout << "\n";
}