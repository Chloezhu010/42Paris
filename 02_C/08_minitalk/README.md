# Project description
- Code a small data exchange program using UNIX signals, specifically SIGUSR1 and SIGUSR2
- Allowed function:
    - write, ft_printf, signal, sigemptyset, sigaddset, sigaction, kill, getpid, malloc, free, pause, sleep, usleep, exit
    - libft
- Mandatory
    - produce server / client executables
    - client must communicate a string passed as a parameter to server, which then display it
    - use SIGUSR1 & SIGUSR2 signals only
- Bonus
    - the server acknowledges every message received by sending back a signal to the client
    - unicode char support
# Resource
- Video list on Unix process: https://www.youtube.com/watch?v=cex9XrZCU14&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY
- Article:
    - https://42-cursus.gitbook.io/guide/rank-02/minitalk/understand-minitalk
- Role of server
    - run & listen for signals
    - process of decoding the bits into signal
    - send acknowledgement after receiving each bit
- Role of client
    - take a server PID and a message
    - send the message via signals
    - process of encoding the signal into bits
    - wait for the acknowledgement before sending the next bit
# File structure
```
minitalk/
├── incl/
│   └── minitalk.h
├── src/
│   ├── server.c
│   ├── client.c
│   └── libft/ ft_printf.c
└── Makefile
```

# Key process
- Setup the server to handle signals
    - display its PID
        - so that the client knows where to send signals
        - getpid()
    - handle incoming signals
        - setup signal handlers using sigaction
        - the server needs to collect 8 bits to reconstruct each char
        - after each bit, the client waits for a confirmation signal from the server before sending the next bit, to avoid singal congestion & loss
        - let SIGUSR1 -> 0 SIGUSR2 -> 1
- Setup the client
    - take the server's PID and the input message
    - for each message, convert it to its ASCII value (8 bits)
    - for each bit in the char, send SIGUSR1 or SIGUSR2 depending on 0 or 1
    - wait for the ACK from the server before sending the next bit
    - once all char sent, send a null terminator indicator
# Modules
1. Server Setup
    - Objective: Create a server that listens for signals and displays received messages.
    - Display PID: Use getpid() to obtain and print the server's PID.
    - Signal Configuration:
        - Set up sigaction for SIGUSR1 and SIGUSR2 with SA_SIGINFO to capture sender's PID.
        - Use a handler function to process incoming signals.
        - Infinite Loop: Keep the server running with pause() or a custom loop.
2. Signal handling (Server)
    - Objective: Decode received signals into char
    - Capture client PID: use siginfo_t->si_pid to identify the sender
    - Track client state
        - maintain a global array or linked list to store each client's process
    - Bit processing
        - append the bit sent from the client
        - after 8 bits, print the char & reset the staste
    - Send ACK 
        - after each bit, send SIGUSR1 back to the client using kill()
3. Client setup
    - Objective: send a message to the server using signals
    - Parse argument
    - Singal hanlder: config a handler for SIGUSR1 (ack siganl)
    - Bit sending
        - convert each char to 8 bits
        - send SIGUSR1 or SIGUSR2 for 0/1 bits using kill()
        - wait for ACK after each bit using sigsuspend() to avoid race conditions
4. Sync
    - Objective: ensure reliablie signal transmission
    - Client side
        - block SIGUSR1 during bit transmission
        - use sigsuspend() to wait for ACK atomically
    - Server side
        - immediately send ACK when receiving a bit

# Related Notes