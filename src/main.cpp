#include <algorithm>
#include <iostream>
#include <string>
#include <unistd.h>

class CuteString
{
  enum AnimMode_t
  {
    NORMAL = 0,
    REVERSE = 1,
    BACKWARDS = 2,
  } mode;

public:
  auto
  stringAnimate(std::string input) -> decltype(std::string())
  {
    if (input.empty())
      return "Input cannot be empty!\n";

    this->mode = AnimMode_t::NORMAL;

    switch (this->mode) {
    case AnimMode_t::NORMAL: {
      for (int i = 0; i < this->stringLength(input) * sizeof(input); ++i) {
        std::printf("%s\n", input.c_str());
        input.pop_back();
      }
      break;
    }
    case AnimMode_t::REVERSE: {
      for (int i = 0; i < this->stringLength(input) * sizeof(input); ++i) {
        std::printf("%s\n", input.c_str());
        std::reverse(input.begin(), input.end());
        input.pop_back();
      }
      break;
    }
    case AnimMode_t::BACKWARDS: {
      for (int i = 0; i < this->stringLength(input) * sizeof(input); ++i) {
        std::printf("%s\n", input.c_str());
        input.erase(0, 1);
      }
      break;
    }
    }

    return "";
  }

private:
  auto
  stringLength(std::string input, int output = 0) -> decltype(int())
  {
    if (input.empty())
      return output;

    int len{};

    for (len = 0; len < input.length(); ++len)
      ;

    if (len != 0)
      output = len;

    return output;
  }
} cute;

auto
main(int argc, char **argv) -> decltype(int())
{
  std::string testAnimate{"hi this is a test! :3"};
  std::cout << cute.stringAnimate(testAnimate) << '\n';

  return 0;
}
