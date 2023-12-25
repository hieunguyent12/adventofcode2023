def part1():
  file = open("input.txt", "r")
  sum = 0
  content = file.readlines()
  directions = [
    [1, 0],
    [-1, 0],
    [0, 1],
    [0, -1],
    [-1, -1],
    [1, -1],
    [1, 1],
    [-1, 1]
  ]
  sum = 0 

  for x, line in enumerate(content):
    for y, c in enumerate(line):
      if not c.isdigit() and c != "." and c != "\n":
        # check every directions
        searched = []

        for dir in directions:
 
          new_x = x + dir[0]
          new_y = y + dir[1]

          if new_x >= len(content):
            new_x = x

          if new_y >= len(line):
            new_y = y

          adjacent = content[new_x][new_y]
          if adjacent.isdigit():
            number = f"{adjacent}"
            should_add = True
            searched.append(f"{new_x}{new_y}")
            # search left or right for full number
 
            # left
            for i in range(new_y-1, -1, -1):
              if not content[new_x][i].isdigit():
                break
              else:
                temp = f"{new_x}{i}"
                if temp in searched:
                  should_add = False
                  break
                searched.append(temp)
                number = f"{content[new_x][i]}{number}"
            # right 
            for i in range(new_y+1, len(line)):
              if not content[new_x][i].isdigit():
                break
              else:
                temp = f"{new_x}{i}"
                if temp in searched:
                  should_add = False
                  break
                searched.append(temp)
                number = f"{number}{content[new_x][i]}" 

            if should_add:
              sum += int(number)
            
  
  print(sum)

# part1()


def part2():
  file = open("input.txt", "r")
  sum = 0
  content = file.readlines()
  directions = [
    [1, 0],
    [-1, 0],
    [0, 1],
    [0, -1],
    [-1, -1],
    [1, -1],
    [1, 1],
    [-1, 1]
  ]
  sum = 0 

  for x, line in enumerate(content):
    for y, c in enumerate(line):
      if c == "*": 
        nums_found = [];
        # check every directions
        searched = []

        for dir in directions:
 
          new_x = x + dir[0]
          new_y = y + dir[1]

          if new_x >= len(content):
            new_x = x

          if new_y >= len(line):
            new_y = y

          adjacent = content[new_x][new_y]
          if adjacent.isdigit():
            number = f"{adjacent}"
            should_add = True
            searched.append(f"{new_x}{new_y}")
            # search left or right for full number
 
            # left
            for i in range(new_y-1, -1, -1):
              if not content[new_x][i].isdigit():
                break
              else:
                temp = f"{new_x}{i}"
                if temp in searched:
                  should_add = False
                  break
                searched.append(temp)
                number = f"{content[new_x][i]}{number}"
            # right 
            for i in range(new_y+1, len(line)):
              if not content[new_x][i].isdigit():
                break
              else:
                temp = f"{new_x}{i}"
                if temp in searched:
                  should_add = False
                  break
                searched.append(temp)
                number = f"{number}{content[new_x][i]}" 

      
            if should_add:
              nums_found.append(int(number))
        
        if len(nums_found) == 2:
          sum += nums_found[0] * nums_found[1]
              
            
  
  print(sum)


part2()