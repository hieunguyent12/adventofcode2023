#include <iostream>
#include <fstream>
#include <vector>
#include <map>

std::vector<std::string> split_string(const std::string &input, char delimiter)
{
  std::vector<std::string> parts{};
  std::string substring = "";

  // loop through every character in the input string until we find a delimiter
  // then we push the substring into the parts array

  for (const auto &c : input)
  {
    if (c != delimiter)
    {
      substring += c;
    }
    else
    {
      parts.push_back(substring);
      substring = "";
    }
  }

  if (!substring.empty())
  {
    parts.push_back(substring);
  }

  return parts;
}

int main()
{
  std::ifstream file{"input.txt"};
  int sum = 0;
  // std::vector<int> queue{};
  // std::map<std::string, int> nums{};
  int card_num = 1;
  int length = 0;
  std::vector<std::string> input{};

  while (!file.eof())
  {
    std::string line = "";
    std::getline(file, line);
    input.push_back(line);
  }

  std::vector<int> card_count(input.size(), 1);

  for (const auto &line : input)
  {
    auto card_numbers = split_string(line, ':')[1];
    auto parts = split_string(card_numbers, '|');
    auto winning_numbers = split_string(parts[0], ' ');
    auto my_numbers = split_string(parts[1], ' ');

    int match_count = 0;
    for (const auto &my_num : my_numbers)
    {
      for (const auto &winning_num : winning_numbers)
      {
        if (my_num != "" && my_num == winning_num)
        {
          match_count++;
          break;
        }
      }
    }

    for (int i = 0; i < match_count; i++)
    {
      card_count[card_num + 1 + i] += card_count[card_num];
    }
    card_num++;
  }

  // while (!file.eof())
  // {
  //   std::string line = "";
  //   std::getline(file, line);

  //   auto card_numbers = split_string(line, ':')[1];
  //   auto parts = split_string(card_numbers, '|');
  //   auto winning_numbers = split_string(parts[0], ' ');
  //   auto my_numbers = split_string(parts[1], ' ');

  //   // PART 1
  //   // int worth = 0;

  //   // for (const auto &my_num : my_numbers)
  //   // {
  //   //   for (const auto &winning_num : winning_numbers)
  //   //   {
  //   //     if (my_num != "" && my_num == winning_num)
  //   //     {
  //   //       if (worth != 0)
  //   //       {
  //   //         worth *= 2;
  //   //       }
  //   //       else
  //   //       {
  //   //         worth = 1;
  //   //       }
  //   //     }
  //   //   }
  //   // }

  //   // sum += worth;

  //   // PART 2
  //   int match_count = 0;
  //   for (const auto &my_num : my_numbers)
  //   {
  //     for (const auto &winning_num : winning_numbers)
  //     {
  //       if (my_num != "" && my_num == winning_num)
  //       {
  //         match_count++;
  //         break;
  //       }
  //     }
  //   }

  //   for (int i = 0; i < match_count; i++)
  //   {
  //     card_count[card_num + 1 + i] += card_count[card_num];
  //   }

  //   card_num++;
  // }

  for (const auto &c : card_count)
  {
    sum += c;
  }

  std::cout << sum;
}