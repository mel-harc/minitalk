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

# 🖥️ Example of Usage in Terminal

Run `make` to compile mandatory part.

```bash
$ make
Server And Client Are Ready Now!
```

Run `make bonus` to compile bonus part.

```bash
$ make bonus
server_bonus And client_bonus Are Ready Now!
```

### 1. Start the server


To begin, first start the server. The server will display its **PID** when launched. the server still running for waiting comming messages from the clinets.

```bash
$ ./server
💳 THIS IS PID : 11345


```

### 2. Send a message from the client

After starting the server, you can run the client by passing the server's PID and the string you want to send as arguments.

```bash
$ ./client 11345 "Hello, Server!"
```

### 3. Server receiving and displaying the message

Once the message is sent by the client, the server will display the message:
```bash
$ ./server
💳 THIS IS PID : 11345
Hello, Server!


```
### 4. Send multiple messages from different clients

The server can handle messages from multiple clients without restarting. For example:
```bash
$ ./client 11345 "Message from Client 1"
$ ./client 11345 "Message from Client 2"
```


```bash
$ ./server
💳 THIS IS PID : 11345
Hello, Server!Message from Client 1Message from Client 2


```

### 5. Example of using Unicode characters (Bonus)

If the bonus feature for Unicode support is implemented, the client can also send Unicode characters:

```bash
$ ./server_bonus
💳 THIS IS PID : 9953


```

```bash
$ ./client 9953 "Hello, 🌍!"
```

The server will display the Unicode message:

```bash
$ ./server_bonus
💳 THIS IS PID : 9953
Hello, 🌍!

```

## ⚠️ The server each in mandatory or bonus still running until press ctl-C (^C signal) to stop him.

### mel-harc
