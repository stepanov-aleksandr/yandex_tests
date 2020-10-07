#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

int main() {
  std::ifstream file_in;
  file_in.open("input.txt", std::ios::in);
  if (!file_in.is_open()) {
    return 0;
  }
  std::ofstream file_out;
  file_out.open("output.txt", std::ios::out);
  if (!file_out.is_open()) {
    file_in.close();
    return 0;
  }

  std::string buffer;
  std::string accum;

  std::string nc;
  std::getline(file_in, nc);

  int count = 0;
  int ret = 0;

  auto itr = static_cast<size_t>(std::atoi(nc.data()));
  if (itr > 10000 || itr <= 0) {
    file_out.write(std::to_string(0).data(), 1);
    file_in.close();
    file_out.close();
    return 0;
  }

  while (itr--) {
    std::getline(file_in, buffer);
    if ((buffer[0] - 48) == 1) {
      count++;
    } else {
      if (count > ret) ret = count;
      count = 0;
    }
  }

  if (ret > count) {
    file_out.write(std::to_string(ret).data(),
                   static_cast<long>(std::to_string(ret).size()));
  } else {
    file_out.write(std::to_string(count).data(),
                   static_cast<long>(std::to_string(count).size()));
    ret = count;
  }

  file_in.close();
  file_out.close();
  return 0;
}
