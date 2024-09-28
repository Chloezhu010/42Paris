# Puzzle implementation logic
1. Rule:
  - no same number on each row and col
  - clue on the edge indicate the range of number
2. Setup file
  - main.c - entry point of the program
  - grid.c - function for managing the grid
  - print.c - function for displaying the grid
  - solve.c - backtracking algo to solve the puzzle
  - valid.c - check validity of placements
3. Compile
  - cc -Wall -Wextra -Werror -o rush-01 *.c
4. Define the data sructure
  - grid.c: define the structure in the grid and its features
  - grid[4][4]
  - clues[16]
5. Initialize the puzzle
  - grid.c: initialize the puzzle
  - initialize the puzzle with the clues provided as input
  - set all heights to 0
6. Implement validity checks
  - valid.c: check if the current state of grid is good
  - check if row and col have duplicates
7. Implement backtracking algo
  - solve.c: attempt to solve the puzzle
  - doesn't understand here
8. Display the grid
  - print.c: display the current state of the grid
9. Main function
  - main.c: to read input and run the solver




# Malloc 
memory allocation



# Free

