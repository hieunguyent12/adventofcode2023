#include <fstream>
#include <iostream>
#include <vector>

int part1()
{
  std::ifstream file{"input.txt"};
  std::vector<std::string> file_content{};
  int sum = 0;
  const int directions[8][2] = {
      {1, 0},
      {-1, 0},
      {0, 1},
      {0, -1},
      {-1, -1},
      {1, -1},
      {1, 1},
      {-1, 1}};

  while (!file.eof())
  {
    std::string content = "";
    std::getline(file, content);

    file_content.push_back(content);
  }

  for (std::size_t row = 0; row < file_content.size(); row++)
  {

    std::string current_num = "";
    bool found_adjacent_symbol = false;

    for (std::size_t col = 0; col < file_content[row].size(); col++)
    {
      char c = file_content[row][col];
      if (std::isdigit(c))
      {
        current_num += c;
        if (!found_adjacent_symbol)
        {
          // check along every directions to check for adjacent symbols
          for (const auto &dir : directions)
          {
            std::size_t new_row = std::clamp(static_cast<int>(row + dir[0]), 0, static_cast<int>(file_content.size()));
            std::size_t new_col = std::clamp(static_cast<int>(col + dir[1]), 0, static_cast<int>(file_content[row].size()));

            auto adjacent = file_content[new_row][new_col];

            if (!std::isdigit(adjacent) && adjacent != '.')
            {
              found_adjacent_symbol = true;
              break;
            }
          }
        }
      }
      else if (!std::isdigit(c) && c == '.')
      {
        if (found_adjacent_symbol && !current_num.empty())
        {
          std::cout << current_num << "\n";
          sum += std::stoi(current_num);
        }
        current_num = "";
        found_adjacent_symbol = false;
      }
      else
      {
        if (!current_num.empty())
        {
          sum += std::stoi(current_num);
          current_num = "";
          found_adjacent_symbol = false;
        }
      }
    }

    if (!current_num.empty() && found_adjacent_symbol)
    {
      sum += std::stoi(current_num);
    }
  }

  return sum;
}

int main()
{
  std::cout << part1();
}