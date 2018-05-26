#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <gtest/gtest.h>

// Problem 1.2
void Reverse(char* str)
{
  if (str != nullptr)
  {
    // count num of chars
    unsigned int arraySize = 0;
    unsigned int curIndex = 0;
    while (str[curIndex] != '\0')
    {
      arraySize++;
      curIndex++;
    }

    for (unsigned int i = 0; i < (int)(arraySize / 2); i++)
    {
      const char temp = str[i];
      str[i] = str[arraySize - 1 - i];
      str[arraySize - 1 - i] = temp;
    }
  }
}

// Problem 1.3
bool IsPermutation(std::string _str1, std::string _str2)
{
  bool isPermutation{ false };
  if (_str1.size() == _str2.size())
  {
    std::sort(_str1.begin(), _str1.end());
    std::sort(_str2.begin(), _str2.end());
    if (_str1 == _str2)
      isPermutation = true;
  }
  return isPermutation;
}

// Problem 1.4
void ReplaceSpaceWithTwenty(char* _str, const unsigned int _strSize)
{
  char* end = _str;
  unsigned int total_str_space = 0;
  while (*end)
  {
    total_str_space++;
    ++end;
  }
  total_str_space--;
  for (unsigned int real_index = _strSize - 1; real_index > 0; real_index--)
  {
    if (_str[real_index] != ' ')
      _str[total_str_space] = _str[real_index];
    else
    {
      _str[total_str_space] = '0';
      _str[--total_str_space] = '2';
      _str[--total_str_space] = '%';
    }
    total_str_space--;
  }
}

// Problem 1.5
std::string CompressStr(const std::string& _str)
{
  char cur_char = '\0';
  int cur_char_count = 0;
  std::vector<char> comp_result;

  const auto flush_comp_chars = [&comp_result, &cur_char, &cur_char_count]()
  {
    comp_result.push_back(cur_char);
    comp_result.push_back('0' + cur_char_count);
    cur_char_count = 1;
  };

  for (unsigned int i = 0; i < _str.size(); i++)
  {
    if (_str[i] == cur_char || i == 0)
    {
      cur_char_count++;
    }
    else
    {
      if (i != 0)
      {
        flush_comp_chars();
      }
    }
    cur_char = _str[i];
  }

  flush_comp_chars();

  if (comp_result.size() >= _str.size())
    return _str;
  else
  {
    std::string result(comp_result.begin(), comp_result.end());
    return result;
  }
}

// Problem 1.6
void Rotate90DegreesRight(int* _matrix, int _width, int _height)
{
  const auto getIndex = [&_width](int x, int y) { return x + y * _width; };
  for (unsigned int j = 0; j < (int)(_height / 2); j++)
  {
    for (unsigned int i = j; i < _width - 1 - j; i++)
    {
      int x = i;
      int y = j;
      int index = getIndex(x, y);
      int put_val = _matrix[index];
      int hold_val = _matrix[index];
      for (unsigned int t = 0; t < 4; t++)
      {
        const int x_i = _width - 1 - y;
        const int y_i = x;
        index = getIndex(x_i, y_i);
        hold_val = _matrix[index];
        _matrix[index] = put_val;
        put_val = hold_val;
        x = x_i;
        y = y_i;
      }
    }
  }
}

void ZeroOutRowAndCol(int* _matrix, int _width, int _height)
{
  std::vector<bool> vis_row(_width, false);
  std::vector<bool> vis_col(_height, false);

  const auto getIndex = [&_width](const int x, const int y) {return x + y * _width; };
  for (unsigned int y = 0; y < _height; y++)
  {
    for (unsigned int x = 0; x < _width; x++)
    {
      int index = getIndex(x, y);
      if (_matrix[index] == 0)
      {
        if (!vis_row[x] && !vis_col[y])
        {
          vis_row[x] = true;
          vis_col[y] = true;

          for (unsigned int row_i = 0; row_i < _width; row_i++)
          {
            index = getIndex(row_i, y);
            _matrix[index] = 0;
          }

          for (unsigned int col_i = 0; col_i < _height; col_i++)
          {
            int index = getIndex(x, col_i);
            _matrix[index] = 0;
          }
        }
      }
    }
  }

}

TEST(problem_1_2)
{
  char* nullStr = nullptr;
  Reverse(nullStr);
  ASSERT_TRUE(nullStr == nullptr);

  char emptyStr[] = "";
  Reverse(emptyStr);
  ASSERT_STREQ("", emptyStr);

  char str[] = "String";
  Reverse(str);
  ASSERT_STREQ("gnirtS", str);

  char head[] = "head";
  Reverse(head);
  ASSERT_STREQ("daeh", head);
}

TEST(problem_1_3)
{
  ASSERT_TRUE(IsPermutation("", ""));
  ASSERT_TRUE(IsPermutation("string", "rginst"));
}

TEST(problem_1_4)
{
  char str[] = "Mr John Smith    ";
  ReplaceSpaceWithTwenty(str, 13);
  ASSERT_STREQ("Mr%20John%20Smith", str);
}

TEST(problem_1_5)
{
  const std::string result1 = CompressStr("aabcccccaaa");
  ASSERT_STREQ("a2b1c5a3", result1.c_str());

  const std::string result2 = CompressStr("abc");
  ASSERT_STREQ("abc", result2.c_str());

  const std::string result3 = CompressStr("");
  ASSERT_STREQ("", result3.c_str());
}

TEST(problem_1_6)
{
  int matrix[] = {
    0, 1, 2, 3,
    4, 5, 6, 7,
    8, 9, 10, 11,
    12, 13, 14, 15
  };

  Rotate90DegreesRight(matrix, 4, 4);

  const int expected_matrix_output[] = {
    12, 8, 4, 0,
    13, 9, 5, 1,
    14, 10, 6, 2,
    15, 11, 7, 3
  };

  for (unsigned int i = 0; i < 16; i++)
  {
    ASSERT_TRUE(expected_matrix_output[i] == matrix[i]);
  }
}

TEST(problem_1_7)
{
  int matrix[] = {
     0,  1,  2,  3,  4,  5,  6,  7,
     8,  9, 10, 11,  0, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23,
    24, 25, 26, 27, 28, 29, 30, 31
  };

  ZeroOutRowAndCol(matrix, 8, 4);

  const int expected_matrix_output[] = {
     0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,
     0, 17, 18, 19,  0, 21, 22, 23,
     0, 25, 26, 27,  0, 29, 30, 31
  };

  for (unsigned int i = 0; i < 32; i++)
  {
    EXPECT_EQ(expected_matrix_output[i], matrix[i]);
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  const int result = RUN_ALL_TESTS();
  std::getchar();
  return result;
}