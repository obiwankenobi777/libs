#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
  std::istream *input = nullptr;
  std::ifstream file;

  if (argc < 2) {
    input = &std::cin;
  } else {
    file.open(argv[1]);
    if (!file.good()) {
      std::cerr << "Error open file: " << argv[1] << '\n';
      return 1;
    }
    input = &file;
  }

  std::string line;
  int count = 0;

  while (std::getline(*input, line)) {
    std::cout << "[" << count + 1 << "]::[" 
              << line.length() << "] "
              << line << '\n';
    ++count;
  }
}

