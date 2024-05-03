# Minitalk
Welcome to the repository of "minitalk" project for 42 School!

## Project Description
The objective of this project is to establish a client-server framework for data communication using UNIX signals.

## How to Use

1. Install and enter in the directory

```sh
git clone git@github.com:furunoluiza/minitalk.git && cd minitalk
```

2. Compilation

```bash
make
```

3. Start the server

```bash
./server
```
Copy the Process ID (PID) provided in the output.

4. Send message with client

```bash
./client [server_pid] ["MESSAGE"]
```
Replace [SERVER_PID] with the PID. Replace [MESSAGE] with the data you want to send to the server.
