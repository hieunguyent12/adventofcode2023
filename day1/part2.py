def main():
  file = open("input.txt", "r")
  content = file.readlines()

  sum = 0
  word_digits = ["one", "two", "three", "four", 
                 "five", "six", "seven", "eight", "nine"]

  for line in content:
    last_digit = None
    
    digit = ""
    word = ""
    for c in line:
        if c.isdigit():
          word = ""
          last_digit = c;

          if len(digit) == 0:
            digit += c
        else:
          word += c
          
          for valid_word in word_digits:
            if valid_word in word:
              last_digit = str(word_digits.index(valid_word) + 1)
              word = ""

              if len(digit) == 0:
                digit += last_digit
          
    digit += last_digit
    sum += int(digit)

  
  print(sum)

main()