# Project description
- A sorting algo project
- Objective: Sort a stack of integers using a limited set of operations.
    - incl. sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
- Constraints: 
    - Must use the fewest number of operations possible
    - Can only use the allowed operations
# Resource
- A visualizer for push swap: https://github.com/o-reo/push_swap_visualizer
- Illustrative video on push swap: 
  - https://www.youtube.com/watch?v=wRvipSG4Mmk
  - https://www.youtube.com/watch?v=OaG81sDEpVk&t=2945s
- Video on linked list: https://www.youtube.com/watch?v=uBZHMkpsTfg&list=PLfqABt5AS4FmXeWuuNDS3XGENJO1VYGxl
- Video on data structure cs50: https://www.youtube.com/watch?v=0euvEdPwQnQ
# File structure
# Modules
1. Argument handling
  - av_split.c
  - error.c
2. Create the stack
  - stack_init.c
3. Command implementation
4. Sorting algo implementation
5. Testing
# Related files & Notes
- Algo: Turk Algo
  - link: https://medium.com/@ayogun/push-swap-c1f5d2d41e97
  - push nodes into stack B until there are only 3 nodes left in A
  - when pushing to stack B, the nodes are sorted in descending order
  - Step
    - push first 2 nodes from A to B
    - find the target node in B
    - cost analysis: find the cheapest node to push in B
      - push cost = # of operations to bring A on top + # of oper to bring A's target node on top
    - sort three algo in A
    - push nodes from B to A
    - choose rotate or reverse rotate
      - if target node above median -> rotate
      - if target node below median -> reverse rotate