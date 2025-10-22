Project Goal:

  Implement Conway's Game of Life - a cellular automaton simulator with an interactive drawing phase.

  Program Signature:

  ./life width height iterations

  Parameters:
  - width - Board width (horizontal size)
  - height - Board height (vertical size)
  - iterations - Number of generations to simulate

  Two Phases:

  Phase 1: Drawing (from stdin)

  A virtual pen starts at the top-left (0,0) and you control it with commands:

  | Command | Action                       |
  |---------|------------------------------|
  | w       | Move pen UP                  |
  | a       | Move pen LEFT                |
  | s       | Move pen DOWN                |
  | d       | Move pen RIGHT               |
  | x       | Toggle pen (draw/erase mode) |

  Rules:
  - Pen cannot move outside the board boundaries (stays at edge if asked to move outside)
  - Invalid commands are ignored
  - When pen is DOWN, mark cells as alive ('0')
  - When pen is UP, cells are dead (space ' ')

  Phase 2: Simulation (Game of Life)

  After reading all drawing commands, simulate N iterations of Conway's Game of Life:

  Rules for each cell:

  | Condition                     | Result                |
  |-------------------------------|-----------------------|
  | Alive with ≤1 neighbors       | Dies (solitude)       |
  | Alive with 2-3 neighbors      | Survives              |
  | Alive with ≥4 neighbors       | Dies (overpopulation) |
  | Dead with exactly 3 neighbors | Becomes alive         |

  Neighbors: 8 surrounding cells (up, down, left, right, diagonals)

  Output:

  - Alive cells: '0' (zero)
  - Dead cells: ' ' (space)
  - Print the board after all iterations complete

  Examples:

  Example 1: Draw a 3x3 vertical line, 0 iterations
  Input: dxss  (right, pen down, down, down)
  Width=3, Height=3, Iterations=0

  Output:
   0
   0
   0

  Example 2: Same setup but 1 iteration (line becomes horizontal due to Game of Life rules)
  Input: dxss
  Width=3, Height=3, Iterations=1

  Output:
  000



  Example 3: Vertical line, 2 iterations (oscillates back)
  Input: dxss
  Width=3, Height=3, Iterations=2

  Output:
   0
   0
   0

  Key Implementation Points:

  1. Board representation - 2D array to track alive/dead cells
  2. Pen state - Track position (x, y) and whether it's down/up
  3. Command parsing - Read from stdin and execute pen movements
  4. Game of Life simulation - Count neighbors for each cell, apply rules
  5. Output formatting - Print board with '0' for alive, ' ' for dead

  This is a classic cellular automaton project testing:
  - 2D array manipulation
  - Boundary handling
  - State transitions
  - Neighbor counting algorithms