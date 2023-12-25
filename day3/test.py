def get_engine_number():
    with open("input.txt", "r") as file:
        rows = file.readlines()
        total_sum = 0 
        print(f"Rows: {len(rows[0])}")
        print(f"Cols: {len(rows)}")

        # Row i
        for i in range(len(rows)):
            # Row i, col j
            for j in range(len(rows[i])):
                c = rows[i][j] 
                # Check each char to see if its a symbol
                if not c.isdigit() and c != '.' and c != "\n":
                    # Left 1
                    if j != 0:
                        if rows[i][j-1].isdigit():
                            number = rows[i][left(rows, j, i):j]
                            print(f"Left Number: {number}")

                    # Right 1
                    if j!= len(rows[i]) - 1: 
                        if rows[i][j+1].isdigit():
                            number = rows[i][j+1:right(rows, j, i)]
                            print(f"Right Number: {number}")

                    # Up 1
                    if i != 0:
                        if rows[i-1][j].isdigit():
                            number_left_index = left(rows, j, i-1)
                            number_right_index = right(rows, j, i-1)
                            number = rows[i-1][number_left_index+1:number_right_index]
                            print(f"Up Number: {number}")

                    # Down 1
                    if i != len(rows) - 2:
                        if rows[i+1][j].isdigit():
                            number_left_index = left(rows, j, i+1)
                            number_right_index = right(rows, j, i+1)
                            number = rows[i+1][number_left_index+1:number_right_index]
                            print(f"Down Number: {number}")  

def left(rows, current_index, col):
    for index in range(current_index-1, -1, -1):
       if not rows[col][index].isdigit():
            return index

def right(rows, current_index, col):
    for index in range(current_index+1, len(rows[col])):
       if not rows[col][index].isdigit():
            return index

get_engine_number()