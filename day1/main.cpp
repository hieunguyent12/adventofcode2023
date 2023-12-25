#include <fstream>
#include <iostream>

int main()
{
  std::ifstream file{"input.txt"};
  int sum = 0;

  if (!file)
  {
    std::cerr << "Can't open file for reading";
    return 1;
  }

  while (!file.eof())
  {
    std::string input;
    std::getline(file, input);

    std::string digit = "";
    std::string last_digit = "";

    for (const auto &c : input)
    {
      if (std::isdigit(c))
      {
        last_digit = c;

        if (digit.length() == 0)
        {
          digit += c;
        }
      }
    }

    digit += last_digit;

    sum += std::stoi(digit);
  }

  std::cout << "SUM: " << sum;
  return 0;
}