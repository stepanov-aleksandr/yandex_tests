#ifndef TST_FUNCTION_H
#define TST_FUNCTION_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

using namespace testing;

// TEST(function_0, functions) {
//  std::string read_buff(
//      (std::istreambuf_iterator<char>(
//          *(std::shared_ptr<std::ifstream>(new std::ifstream("input.txt")))
//               .get())),
//      std::istreambuf_iterator<char>());

//  auto end = std::find(read_buff.begin(), read_buff.end(), '\n');
//  std::string jewels(read_buff.begin(), end), stones(end + 1,
//  read_buff.end());

//  EXPECT_EQ(1, 1);
//}

// TEST(bit_sequence, functions) {
//  std::ifstream file;
//  file.open("input.txt", std::ios::in);
//  if (!file.is_open()) {
//    std::cerr << "Error open file" << std::endl;
//  }
//  std::string buffer;
//  std::string accum;

//  while (file >> buffer) {
//    accum.append(buffer);
//  }

//  int count = 0;
//  int ret = 0;

//  for (auto itr = accum.begin() + 1; itr != accum.end(); itr++) {
//    if (*itr == '1') count++;
//    if (*itr == '0') {
//      if (ret == 0) ret = count;
//      if (count > ret) ret = count;
//      count = 0;
//    }
//  }
//  std::cout << "ret = " << ret;

//  EXPECT_EQ(1, 1);
//}

#include <random>
#include "../bit_sequence.h"

void TestFileWrite(int num) {
  std::ofstream file_out;
  file_out.open("input.txt");
  auto num_s = std::to_string(num);

  file_out.write(num_s.data(), num_s.size());
  file_out.write("\n", 1);
  for (int i = 0; i != num; i++) {
    file_out.write("1\n", 2);
  }
  file_out.close();
}
void TestFileWriteMinus(int num) {
  std::ofstream file_out;
  file_out.open("input.txt");
  auto num_s = std::to_string(num);
  file_out.write(num_s.data(), num_s.size());
  file_out.write("\n", 1);
  file_out.close();
}
void TestFileWriteRandom(int num) {
  std::ofstream file_out;
  file_out.open("input.txt");
  auto num_s = std::to_string(num);

  file_out.write(num_s.data(), num_s.size());
  file_out.write("\n", 1);
  for (int i = 0; i != num; i++) {
    file_out.write(std::to_string(std::rand() % 2).data(), 1);
    file_out.write("\n", 1);
  }
  file_out.close();
}

void TestFileWrite(std::vector<bool> sequence) {
  std::ofstream file_out;
  file_out.open("input.txt");
  auto size_seq = sequence.size();
  auto size_seq_str = std::to_string(size_seq);
  auto size_seq_str_size = std::to_string(size_seq).size();

  file_out.write(size_seq_str.data(), static_cast<long>(size_seq_str_size));
  file_out.write("\n", 1);

  for (auto unit : sequence) {
    file_out.write(std::to_string(unit).data(), 1);
    file_out.write("\n", 1);
  }
  file_out.close();
}

int TestFileRead(std::string path = "output.txt") {
  std::ifstream file_in;
  file_in.open(path, std::ios::in);
  if (!file_in.is_open()) {
    std::cerr << "Error open file" << std::endl;
    return 0;
  }
  std::string nc;
  std::getline(file_in, nc);
  return std::atoi(nc.data());
}

TEST(bit_sequence_0, functions) {
  TestFileWrite(std::vector<bool>{1, 1, 1, 1, 1, 1, 1});
  auto ret_alg = BitSequence("input.txt");
  auto ret_res = TestFileRead();
  EXPECT_EQ(ret_alg, ret_res);
}
TEST(bit_sequence_1, functions) {
  TestFileWrite(std::vector<bool>{0, 0, 0, 0, 0, 0, 0});
  auto ret_alg = BitSequence("input.txt");
  auto ret_res = TestFileRead();
  EXPECT_EQ(ret_alg, ret_res);
}
TEST(bit_sequence_1_1, functions) {
  TestFileWrite(std::vector<bool>{0, 0, 0, 0, 0, 0, 1});
  auto ret_alg = BitSequence("input.txt");
  auto ret_res = TestFileRead();
  EXPECT_EQ(ret_alg, ret_res);
}
TEST(bit_sequence_2, functions) {
  TestFileWrite(std::vector<bool>{0, 1, 1, 1, 1, 1, 0});
  auto ret_alg = BitSequence("input.txt");
  auto ret_res = TestFileRead();
  EXPECT_EQ(ret_alg, ret_res);
}
TEST(bit_sequence_3, functions) {
  TestFileWrite(std::vector<bool>{1, 0, 0, 0, 0, 0, 1});
  auto ret_alg = BitSequence("input.txt");
  auto ret_res = TestFileRead();
  EXPECT_EQ(ret_alg, ret_res);
}
TEST(bit_sequenc_4, functions) {
  TestFileWrite(std::vector<bool>{1, 1, 1, 0, 1, 1, 1});
  auto ret_alg = BitSequence("input.txt");
  auto ret_res = TestFileRead();
  EXPECT_EQ(ret_alg, ret_res);
}
TEST(bit_sequenc_4_, functions) {
  TestFileWrite(std::vector<bool>{0, 1, 1, 0, 1, 1, 1});
  auto ret_alg = BitSequence("input.txt");
  auto ret_res = TestFileRead();
  EXPECT_EQ(ret_alg, ret_res);
}
TEST(bit_sequence_5, functions) {
  TestFileWrite(std::vector<bool>{0, 0, 0, 1, 0, 0, 0});
  auto ret_alg = BitSequence("input.txt");
  auto ret_res = TestFileRead();
  EXPECT_EQ(ret_alg, ret_res);
}
TEST(bit_sequence_6, functions) {
  TestFileWrite(std::vector<bool>{0, 0, 0, 1, 0, 0, 0});
  auto ret_alg = BitSequence("input.txt");
  auto ret_res = TestFileRead();
  EXPECT_EQ(ret_alg, ret_res);
}
TEST(bit_sequence_7, functions) {
  TestFileWrite(std::vector<bool>{1, 1, 0, 1, 0, 1, 1, 1, 0});
  auto ret_alg = BitSequence("input.txt");
  auto ret_res = TestFileRead();
  EXPECT_EQ(ret_alg, ret_res);
}
// TEST(bit_sequence_8, functions) { EXPECT_EQ(BitSequence("/dev/null"), -1); }

TEST(bit_sequence_9, functions) {
  TestFileWrite(10005);
  auto ret_alg = BitSequence("input.txt");
  auto ret_res = TestFileRead();
  EXPECT_EQ(ret_alg, ret_res);
}

TEST(bit_sequence_10, functions) {
  TestFileWriteMinus(-10);
  auto ret_alg = BitSequence("input.txt");
  auto ret_res = TestFileRead();
  EXPECT_EQ(ret_alg, ret_res);
}
TEST(bit_sequence_11, functions) {
  TestFileWrite(9999);
  auto ret_alg = BitSequence("input.txt");
  auto ret_res = TestFileRead();
  EXPECT_EQ(ret_alg, ret_res);
}
TEST(bit_sequence_12, functions) {
  TestFileWrite(10000);
  auto ret_alg = BitSequence("input.txt");
  auto ret_res = TestFileRead();
  EXPECT_EQ(ret_alg, ret_res);
}
TEST(bit_sequence_13, functions) {
  TestFileWrite(0);
  auto ret_alg = BitSequence("input.txt");
  auto ret_res = TestFileRead();
  EXPECT_EQ(ret_alg, ret_res);
}
#endif  // TST_FUNCTION_H
