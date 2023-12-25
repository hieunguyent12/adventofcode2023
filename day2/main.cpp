#include <iostream>
#include <fstream>
#include <vector>

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

int part1()
{
  std::ifstream file{"input.txt"};
  int sum = 0;
  int red = 12;
  int green = 13;
  int blue = 14;

  while (!file.eof())
  {
    std::string content = "";
    std::getline(file, content);

    auto game_info = split_string(content, ':');
    auto sets = split_string(game_info[1], ';');
    int game_id = std::stoi(split_string(game_info[0], ' ')[1]);
    bool valid_set = true;

    for (const auto &set : sets)
    {
      auto cubes = split_string(set, ',');

      for (const auto &cube : cubes)
      {
        auto info = split_string(cube, ' ');

        int num = std::stoi(info[1]);
        auto color = info[2];

        if ((color == "red" && num > red) || (color == "blue" && num > blue) || (color == "green" && num > green))
        {
          valid_set = false;
          break;
        }
      }
    }

    if (valid_set)
    {
      sum += game_id;
    }
  }

  return sum;
}

int main()
{
  auto start = std::chrono::high_resolution_clock::now();

  std::cout << part1();

  auto stop = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "The average execution time of AoC day 2, part 1 (microseconds): " << ((duration.count())) << std::endl;
}