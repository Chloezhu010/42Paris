# Project description
- Description
    - the [dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- Rules
    - each philosopher should be a thread, with 3 state: eat, think, sleep
    - # of fork = # of philosophers
    - to prevent philosophers from duplicating forks, should protect the fork state with a mutex for each
    - philosophers should avoid dying
    - must not have any data races
- Arguments
    - number_of_philosophers
    - time_to_die (in ms)
    - time_to_eat (in ms)
    - time_to_sleep (in ms)
    - number_of_times_each_philosopher_must_eat (optional arg)
- Displayed state message
    - display state change: taken a fork, is eating, is sleeping, is thinking, died
- Allowed function
    - NO libft
    - memset
    - printf
    - malloc, free
    - write
    - usleep
    - gettimeofday
    - pthread_create
    - pthread_detach
    - pthread_join
    - pthread_mutex_init
    - pthread_mutex_destroy
    - pthread_mutex_lock
    - pthread_mutex_unlock

# Resource
- Video
  - Video by Oceano: https://www.youtube.com/watch?v=zOpzGHwJ3MU
  - Video list on Unix threads in C by CodeVault: https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2
  - Vidoe list on Unix processes in C by CodeVault: https://www.youtube.com/watch?v=cex9XrZCU14&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY
- Article
  - https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2
  - https://42-cursus.gitbook.io/guide/rank-03/philosophers
- Github
  - https://github.com/mcombeau/philosophers

# Key concept
- thread vs process
  - process: 1 process can contain multiple threads
  - address space: process when forking, parent and child have separate variables, which can both be modified individually. While threads are sharing memroy.
- race condition
- mutex



# Modules

# Notes