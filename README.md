# Client-Server Application with Two-Way Connection

This repository contains a simple client-server application implemented in C, using sockets to establish a two-way connection between a client and a server.

## Purpose

The purpose of this application is to demonstrate how to create a basic client-server architecture where both the client and server can send and receive messages from each other.

## Prerequisites

Before building and running the application, ensure you have the following:

- Linux environment (the code is written for Linux)
- Basic knowledge of C programming
- GCC compiler installed

## Build Instructions

To build the client and server applications, follow these steps:

1. Open a terminal window.
2. Navigate to the directory containing the source code (`client.c` and `server.c`).
3. Compile the client application:
```bash
gcc client.c -o client
```
4. Compile the server application:
```bash
gcc server.c -o server
```

## Running the Application

Follow these steps to run the client-server application:

1. Open two terminal windows.
2. In the first terminal, navigate to the directory containing the compiled server binary.
Run the server:
```bash
./server
```
3. In the second terminal, navigate to the directory containing the compiled client binary.
Run the client:
```bash
./client
```
4. Once both the client and server are running, they will establish a connection, and you can start sending messages between them. The client and server will alternate sending and receiving messages until one of them closes the connection.

## Note
By default, the server listens on port 9999. You can change this port number by modifying the htons(9999) line in both client.c and server.c to the desired port number.
This application is designed for educational purposes and does not include error handling or robust features expected in production-grade code.
