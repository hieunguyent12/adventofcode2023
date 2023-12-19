def main():
  file = open("input.txt", "r")
  content = file.readlines()

  sum = 0


  for line in content:
    digit = ""
    last_digit = None

    for c in line:
      if c.isdigit():
        last_digit = c;

        if len(digit) == 0:
          digit += c

    digit += last_digit
    sum += int(digit)

  
  print(sum)

main()