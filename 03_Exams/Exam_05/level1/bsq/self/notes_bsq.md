Problem Summary

  Find the largest square of empty cells in a map, avoiding obstacles. Mark it with a "full" character. If multiple
  solutions exist, prioritize: top-most, then left-most.

  ---
  Implementation Logic (Step-by-Step)

  Step 1: Parse the First Line

  - Extract 4 values: num_lines, empty_char, obstacle_char, full_char
  - Store these for later validation and processing

  Step 2: Validate Map Structure

  - Check all lines have the same length
  - Verify at least one line exists with content
  - Ensure each line ends with \n
  - Validate that only the 3 valid characters appear (empty, obstacle, full)
  - Ensure the 3 characters are distinct (no duplicates)
  - If invalid → print "map error" to stderr and skip to next map

  Step 3: Read the Map into Memory

  - Dynamically allocate a 2D array or buffer to store the map
  - Store all rows of the map (excluding the first info line)

  Step 4: Build a Auxiliary Matrix for Distances

  This is the key algorithm - use dynamic programming:
  - Create a matrix dp[i][j] where each cell stores the size of the largest square ending at that position
  - For each cell (i, j):
    - If it's an obstacle: dp[i][j] = 0
    - If it's empty: dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
    - This tells us the maximum square size possible with that cell at the bottom-right corner

  Step 5: Find the Maximum Square

  - Scan through the dp matrix
  - Track the largest value found
  - If multiple cells have the same max value, pick the first one encountered (top-to-bottom, left-to-right) → this
  gives top-most, then left-most priority
  - Record the position (max_row, max_col) and the size max_size

  Step 6: Mark the Square on the Map

  - Starting from the bottom-right corner of the identified square
  - Fill all cells in the square with the full_char
  - The square extends from:
    - Top-left: (max_row - max_size + 1, max_col - max_size + 1)
    - To bottom-right: (max_row, max_col)

  Step 7: Output the Result

  - Print the modified map to stdout
  - Add a newline after each map

  Step 8: Handle Multiple Maps

  - Read from arguments or stdin if no arguments provided
  - Process each map independently
  - Print "map error" on stderr for invalid maps
  - Continue to next map after error

  ---
  Key Algorithmic Points

  DP Recurrence Relation:
  If map[i][j] == obstacle:
      dp[i][j] = 0
  Else:
      dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1

  This works because:
  - The minimum of the three neighbors + 1 ensures we can form a valid square
  - If any neighbor has a smaller max-square, we're limited by that

  Selection Criteria (Top-most, then Left-most):
  - Scan the dp matrix row-by-row (top to bottom)
  - Within each row, scan left to right
  - Update max only when dp[i][j] > current_max (not >=)
  - This ensures first occurrence wins



  >>> Testing: map19_full_integration ... ❌ FAIL (output mismatch)
Expected:
...................xxxxxx..
....o..............xxxxxx..
............o......xxxxxx..
...................xxxxxxo.
....o....o........oxxxxxx..
......o....o...o...xxxxxx..
...........................
......o..............o.....
..o.......o................
Got:
...........................
....o..............xxxxxxxx
............o......xxxxxxxx
...................xxxxxxxx
....o....o........oxxxxxxxx
......o....o...o...xxxxxxxx
...................xxxxxxxx
......o............xxxxxxxx
..o.......o........xxxxxxxx
>>> Testing: map20_full_integration_2 ... ❌ FAIL (output mismatch)
Expected:
................xxxxxxx....
....o...........xxxxxxx....
............o...xxxxxxx....
................xxxxxxx....
....o...........xxxxxxx....
.........o.....oxxxxxxx....
................xxxxxxx....
......o..............o.....
..o.......o................
Got:
.......xxxxxxxx............
....o..xxxxxxxx............
.......xxxxxxxx............
.......xxxxxxxx............
....o..xxxxxxxx............
.......xxxxxxxxo...........
.......xxxxxxxx............
......oxxxxxxxx......o.....
..o.......o................