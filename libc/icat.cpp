#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Missing Parameters\n";
    return 1;
  }

  std::ifstream in(argv[1]);

  if (!in.good()) {
    std::cerr << "Error open file: " << argv[1] << '\n';
    return 1;
  }

  std::string line;
  int count = 0;

  while(std::getline(in, line)) {
    std::cout << "[" << count + 1 << "]::["
    << line.length() << "] " << line << '\n';
    ++count;
  }

  in.close();
}
