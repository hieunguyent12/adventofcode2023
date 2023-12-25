def part1():
  file = open("input.txt", "r")
  config = {
    "red": 12,
    "green": 13,
    "blue": 14
  }
  sum = 0
  
  for line in file.readlines():
    game_info = line.split(':')
    game_id = int(game_info[0].split(" ")[1])
    sets = game_info[1].split(';')
    good = True

    for set in sets:
      cube_info = set.split(',')
      for cube in cube_info:
        [_, num_of_cubes, cube_color] = cube.split(' ')

        cube_color = cube_color.rstrip()

        if int(num_of_cubes) > config[cube_color]:
          good = False
          break
      if not good:
        break
      
    if good:
       sum += game_id
  # print(sum)
  print(f"Part 1: {sum}")

# part1()


def part2():
  file = open("input.txt", "r")
  sum = 0
  
  for line in file.readlines(): 
    game_info = line.split(':')
    sets = game_info[1].split(';')
    highest = {
      "red": 0,
      "blue": 0,
      "green": 0
    }

    for set in sets:
      cube_info = set.split(',')
      for cube in cube_info:
        [_, num_of_cubes, cube_color] = cube.split(' ')
        cube_color = cube_color.rstrip()

        if highest[cube_color] < int(num_of_cubes):
          highest[cube_color] = int(num_of_cubes)

    sum += highest["blue"] * highest["red"] * highest["green"]
  
  print(sum)
part2()