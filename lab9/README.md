# Lab9: Threads

## Name
Haotian Shen

## Hours spent
1 hour

## Collaborator
None

## External resources
None

## How to run the code
```
gcc dining_philosophers.c -o dining -pthread
./dining
```

## Tradeoff
- Not using semaphore will create a deadlock
- Using single semaphore may prone to errors if that semaphore fails
- Using one semaphore per fork increases availability at the cost of overhead