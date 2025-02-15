# Project description
- Rewrite a simple shell
- Allowed functions
    - Libft
    - readline
    - rl_clear_history
    - rl_on_new_line
    - rl_replace_line
    - rl_redisplay
    - add_history
    - printf
    - malloc, free
    - write
    - access
    - open, read, close
    - fork
    - wait, waitpid, wait3, wait4
    - signal
    - sigaction, sigemptyset, sigaddset
    - kill, exit
    - getcwd
    - chdir
    - stat, lstat, fstat
    - unlink
    - execve
    - dup, dup2
    - pipe
    - opendir, readdir, closedir
    - strerror, perror
    - isatty
    - ttyname, ttyslot
    - ioctl
    - getenv
    - tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs

# Resource
- Architecture
    - https://github.com/zstenger93/minishell/blob/master/mindmap.png
    

# Module


# Notes
- What's Shell?
    - a user interface, that provides access to an OS service
    - act as the intermediary btw user and the OS's kernel
- What problem does Shell solve?
    - interactivity: instead of waiting for batch procssing, user can type commands and get immediate feedback
    - efficiency: user can nagivate files, execute programs, and manage process quickly without needing low-level machine code
    - automation: shell scripting allows repetitive tasks to be automated
    - multi-user access: multiple users can interact with the system without interfering with each other
    - abstraction over system calls: instead of writing complex system calls in C/ assembly, users can perform tasks using simple commands
- How a Shell works?
    - high level: interpret user commands, execute them, return the result
    - Steps
        - Read-Evaluate-Print loop (REPL)
            - read: read input from user (eg. ls, or echo "hello")
            - evaluate: parse the input, interpret it, and execute the system calls or programs
            - print: display the output (if any) to the user
            - loop: repeat the process until the user exits (by typing exit, or press ctl+D)
        - Command parsing
            - break down user's input into tokens (eg. command name, arg, options)
        - Command execution
            - use system calls (eg. fork(), exec(), wait() to execute commands)
            - fork(): create a child process to run the command
            - exec(): replace the child process's memory with the program to be executed
            - wait(): wait for the child process to complete and retrieve its exit status
        - Build-in commands
            - commands eg. cd, exit, are build into the shell itself and don't require spawning a new process
        - Input/Output redirection and piping
            - handle special operators eg.
                - > : redirect output to a file
                - < : redirect input from a file
                - | : pipe the output of one command to the input of another
        - Envirnment mgmt
            - manage env variables (eg. PATH, HOME) that affect how commands are executed
