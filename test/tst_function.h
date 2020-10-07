#ifndef TST_FUNCTION_H
#define TST_FUNCTION_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <math.h>
#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <stdexcept>
#include <tuple>
#include <vector>

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

//#include <random>
//#include "../bit_sequence.h"

// void TestFileWrite(int num) {
//  std::ofstream file_out;
//  file_out.open("input.txt");
//  auto num_s = std::to_string(num);

//  file_out.write(num_s.data(), num_s.size());
//  file_out.write("\n", 1);
//  for (int i = 0; i != num; i++) {
//    file_out.write("1\n", 2);
//  }
//  file_out.close();
//}
// void TestFileWriteMinus(int num) {
//  std::ofstream file_out;
//  file_out.open("input.txt");
//  auto num_s = std::to_string(num);
//  file_out.write(num_s.data(), num_s.size());
//  file_out.write("\n", 1);
//  file_out.close();
//}
// void TestFileWriteRandom(int num) {
//  std::ofstream file_out;
//  file_out.open("input.txt");
//  auto num_s = std::to_string(num);

//  file_out.write(num_s.data(), num_s.size());
//  file_out.write("\n", 1);
//  for (int i = 0; i != num; i++) {
//    file_out.write(std::to_string(std::rand() % 2).data(), 1);
//    file_out.write("\n", 1);
//  }
//  file_out.close();
//}

// void TestFileWrite(std::vector<bool> sequence) {
//  std::ofstream file_out;
//  file_out.open("input.txt");
//  auto size_seq = sequence.size();
//  auto size_seq_str = std::to_string(size_seq);
//  auto size_seq_str_size = std::to_string(size_seq).size();

//  file_out.write(size_seq_str.data(), static_cast<long>(size_seq_str_size));
//  file_out.write("\n", 1);

//  for (auto unit : sequence) {
//    file_out.write(std::to_string(unit).data(), 1);
//    file_out.write("\n", 1);
//  }
//  file_out.close();
//}

// TEST(bit_sequence_0, functions) {
//  TestFileWrite(std::vector<bool>{1, 1, 1, 1, 1, 1, 1});
//  EXPECT_EQ(BitSequence("input.txt"), 7);
//}
// TEST(bit_sequence_1, functions) {
//  TestFileWrite(std::vector<bool>{0, 0, 0, 0, 0, 0, 0});
//  EXPECT_EQ(BitSequence("input.txt"), 0);
//}
// TEST(bit_sequence_2, functions) {
//  TestFileWrite(std::vector<bool>{0, 1, 1, 1, 1, 1, 0});
//  EXPECT_EQ(BitSequence("input.txt"), 5);
//}
// TEST(bit_sequence_3, functions) {
//  TestFileWrite(std::vector<bool>{1, 0, 0, 0, 0, 0, 1});
//  EXPECT_EQ(BitSequence("input.txt"), 1);
//}
// TEST(bit_sequenc_4, functions) {
//  TestFileWrite(std::vector<bool>{1, 1, 1, 0, 1, 1, 1});
//  EXPECT_EQ(BitSequence("input.txt"), 3);
//}
// TEST(bit_sequence_5, functions) {
//  TestFileWrite(std::vector<bool>{0, 0, 0, 1, 0, 0, 0});
//  EXPECT_EQ(BitSequence("input.txt"), 1);
//}
// TEST(bit_sequence_6, functions) {
//  TestFileWrite(std::vector<bool>{1, 0, 1, 0, 1, 0, 1});
//  EXPECT_EQ(BitSequence("input.txt"), 1);
//}
// TEST(bit_sequence_7, functions) {
//  TestFileWrite(std::vector<bool>{1, 1, 0, 1, 0, 1, 1, 1, 0});
//  EXPECT_EQ(BitSequence("input.txt"), 3);
//}
// TEST(bit_sequence_8, functions) { EXPECT_EQ(BitSequence("/dev/null"), -1); }

// TEST(bit_sequence_9, functions) {
//  TestFileWrite(10001);
//  EXPECT_EQ(BitSequence("input.txt"), -1);
//}
// TEST(bit_sequence_10, functions) {
//  TestFileWriteMinus(-10);
//  EXPECT_EQ(BitSequence("input.txt"), -1);
//}

//#include <math.h>
//#include <algorithm>
//#include <array>
//#include <iomanip>
//#include <iostream>
//#include <limits>
//#include <map>
//#include <set>
//#include <stdexcept>
//#include <tuple>
//#include <vector>

// using namespace std;

// enum class Lang { DE, FR, IT };

// struct Region {
//  string std_name;
//  string parent_std_name;
//  map<Lang, string> names;
//  int64_t population;
//};

// bool operator<(const Region &lhs, const Region &rhs) {
//  return std::make_tuple(lhs.std_name, lhs.parent_std_name, lhs.names,
//                         lhs.population) <
//         std::make_tuple(rhs.std_name, rhs.parent_std_name, rhs.names,
//                         rhs.population);
//}

// int FindMaxRepetitionCount(const std::vector<Region> &r) {
//  if (r.size() == 0) return 0;
//  long count = 0;
//  std::map<Region, int> counts;
//  for (const auto &unit : r) {
//    counts[unit]++;
//    if (counts[unit] > count) count = counts[unit];
//  }
//  return static_cast<int>(count);
//}

// TEST(repit, functions) {
//  FindMaxRepetitionCount(
//      {{"Moscow",
//        "Russia",
//        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//        89},
//       {"Russia",
//        "Eurasia",
//        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//        89},
//       {"Moscow",
//        "Russia",
//        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//        89},
//       {"Moscow",
//        "Russia",
//        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//        89}});
//  FindMaxRepetitionCount({
//      {"Moscow",
//       "Russia",
//       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//       89},
//      {"Russia",
//       "Eurasia",
//       {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//       89},
//      {"Moscow",
//       "Russia",
//       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//       89},
//      {"Moscow",
//       "Russia",
//       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//       89},
//      {"Russia",
//       "Eurasia",
//       {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//       89},
//  });

//  FindMaxRepetitionCount({
//      {"Moscow",
//       "Russia",
//       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//       89},
//      {"Russia",
//       "Eurasia",
//       {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//       89},
//      {"Moscow",
//       "Russia",
//       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
//       89},
//      {"Moscow",
//       "Toulouse",
//       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//       89},
//      {"Moscow",
//       "Russia",
//       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//       31},
//  });
//}

// TEST(bit_sequence_7, functions) {
//  TestFileWrite(std::vector<bool>{1, 1, 0, 1, 0, 1, 1, 1, 0});
//  EXPECT_EQ(BitSequence("input.txt"), 3);
//}

#endif  // TST_FUNCTION_H
