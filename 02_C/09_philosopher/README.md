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
- What's thread
  - a thread is a basic unit of CPU utilization
  - componenet: a thread ID, a program counter, a register set, and a stack
- **thread vs process**
  - process: 1 process can contain multiple threads
  - address space: process when forking, parent and child have separate variables, which can both be modified individually. While threads are sharing memroy.
- **race condition**
  - A race condition in C (or any multithreaded/multiprocess program) occurs when multiple threads or processes access and modify shared data concurrently, leading to unpredictable behavior.
  - How It Happens
    - Multiple threads/processes access shared data simultaneously.
    - Execution order is unpredictable due to scheduling by the operating system.
    - Final result depends on timing, causing unexpected or inconsistent behavior.
- **mutex**
  - short for mutual exclusion, mutex is a synchronization mechanism used in multithreaded programming to prevent race conditions by ensuring that only one thread can access a shared resource at a time.
  - How it works
    - A mutex lock is placed before accessing a shared resource.
    - When a thread locks the mutex, other threads must wait until it is unlocked.
    - After finishing the operation, the thread unlocks the mutex, allowing others to proceed.
- parallelism vs concurrency
  - parallelism: execute multiple tasks simultaneously, typically on multiple processors or cores. In parallelism, tasks are literally running at the same time in different computational resources.
  - concurrency: the ability of a system to handle multiple tasks at once, but not necessarily at the same exact time. It allows tasks to be in progress at the same time (often through context switching), but only one task is executing at any given moment.

# Modules

# Notes