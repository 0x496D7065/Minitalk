*This project has been created as part of the 42 curriculum*

# Minitalk

## Description

Minitalk is a small client-server program that exchanges messages between two processes using only UNIX signals. The server starts and displays its PID. The client takes that PID and a string, then sends the string to the server, which prints it.

Only `SIGUSR1` and `SIGUSR2` are used to carry the data.

## How it works

Signals carry no data by themselves, so each character is sent bit by bit:

- `SIGUSR1` represents a bit set to `0`.
- `SIGUSR2` represents a bit set to `1`.
- The client converts each character of the message into its 8 bits and sends them one signal at a time.
- The server rebuilds each character from the received bits and prints it once it has all 8.

## Instructions

### Build

```bash
make          # builds server and client
make clean    # removes object files
make fclean   # removes object files and executables
make re       # rebuilds everything
```

### Usage

In a first terminal, start the server. It prints its PID:

```bash
./server
```

In a second terminal, send a message to it:

```bash
./client <server_pid> "Hello, Minitalk!"
```

The server prints the message.

## Project structure

```
.
├── Makefile
├── server.c        # receives signals and rebuilds the message
├── client.c        # sends the message as signals
├── char_to_bin.c   # converts a character to its bits
└── includes/       # header files
```

## Resources

- `man 2 signal`, `man 2 sigaction`, `man 2 kill`, `man 2 pause`
- [GNU C Library: Signal Handling](https://www.gnu.org/software/libc/manual/html_node/Signal-Handling.html)
