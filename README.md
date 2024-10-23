# 📡 Small Data Exchange Program using UNIX Signals

## Project Overview

The purpose of this project is to develop a **client-server communication program** using **UNIX signals**. The program will be written in **C** and adhere to specific coding standards. It will enable a client to send a string to a server, and the server will print the received message. This exchange will occur using only two UNIX signals: **SIGUSR1** and **SIGUSR2**. Additionally, the server will be able to handle multiple clients sequentially without requiring a restart.

## Program Requirements

### General Guidelines

- The project must be written in **C**, following the **Norm** (coding standards).
- Programs must be robust and handle errors gracefully, avoiding unexpected behaviors such as segmentation faults, bus errors, or memory leaks.
- The project must include a **Makefile** to compile the source files. This Makefile should not relink unnecessary files and must contain the following rules:
  - `$(NAME)`
  - `all`
  - `clean`
  - `fclean`
  - `re`
- Any **bonus functionality** must be compiled with a separate `bonus` rule in the Makefile, with code located in specific bonus files (`_bonus.c` / `_bonus.h`).
- If the project uses **libft**, it must be included in a **libft folder** with its own Makefile, and the project’s Makefile should handle compiling both the library and the main project.
- The program must not have **memory leaks**, and proper memory management is required, including freeing any allocated memory when necessary.

### Functional Requirements

The project must create two executable programs: **client** and **server**.

#### Server:

- The server must be launched first and print its **PID** (Process ID) upon starting.
- It must be capable of receiving strings sent from clients without needing to be restarted between requests.
- Upon receiving a string, the server should display it **promptly**.

#### Client:

- The client takes two arguments:
  - The **PID of the server**.
  - The **string to send**.
- It must send the provided string to the server using only the signals **SIGUSR1** and **SIGUSR2**.
- The communication between the client and server must use only **UNIX signals**.

### Allowed Functions

You are allowed to use the following functions in the project:

- `write`, `signal`, `sigemptyset`, `sigaddset`, `sigaction`, `kill`, `getpid`
- `malloc`, `free`, `pause`, `sleep`, `usleep`, `exit`
- You can use `ft_printf` or any equivalent that you have coded yourself.

## Bonus Features

- **Acknowledgment Mechanism**: The server will acknowledge every message received by sending a signal back to the client.
- **Unicode Support**: Extend the program to support **Unicode characters** in the messages sent from the client to the server.


