# Lab11: Client/Server

## Author:
Haotian Shen

## Files included:
- echo_client.c
- echo_server.c
- kk_client.c
- kk_server.c
- Makefile
- README.md

## Sample output
* Running modified echo_client and echo_server:
- echo_client side
```
> make run_echo_client
gcc echo_client.c -o echo_client
./echo_client
Enter your message: hello
SENDING: hello

Enter how many times to repeat: 3
SENDING: 3

FROM SERVER: hello

FROM SERVER: hello

FROM SERVER: hello

Enter your message: blue
SENDING: blue

Enter how many times to repeat: 5
SENDING: 5

FROM SERVER: blue

FROM SERVER: blue

FROM SERVER: blue

FROM SERVER: blue

FROM SERVER: blue

Enter your message: understand
SENDING: understand

Enter how many times to repeat: 10
SENDING: 10

FROM SERVER: understand

FROM SERVER: understand

FROM SERVER: understand

FROM SERVER: understand

FROM SERVER: understand

FROM SERVER: understand

FROM SERVER: understand

FROM SERVER: understand

FROM SERVER: understand

FROM SERVER: understand

Enter your message
```

- echo_server side:
```
> make run_echo_server
./echo_server
Listening on file descriptor 3, port 1234
Waiting for connection...
Connection made: client_fd=4
Read 6 chars
===
hello

Read 5 chars
===
blue

Read 11 chars
===
understand
```

## 3 things interested/surprised
1. I am very surprised that in C, even terminating the program using CTRL_C would not free the port from being used by the server. Thus, I need to actually set the socket option to be able to reuse to fix this issue.
2. I am very interested to learn more about the "addrinfo" struct. 
3. I am very surprised that the server and client is a one-on-one relationship for this program in C. I thought I can spring another client and the server would be able to receive input from two clients at the same time. Seemed like the server can only accept one thread sending message at a time.

## Who did I work with?
None

## How long did I spend on this lab?
1 hour

## External resource:
https://beej.us/guide/bgnet/html/

