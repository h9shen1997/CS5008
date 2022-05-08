## A5: K-SEA Shell (ksesh) Build your own unix shell
### Name
Haotian Shen

### Hours
6 hours

### Collaborators
None

### External resources
- https://stackoverflow.com/questions/5769734/what-are-the-different-versions-of-exec-used-for-in-c-and-c
- https://linux.die.net/man/3/exec

### Files included
- pwd.c
- shell.c
- shell.h
- readme.md
- Makefile

### How to run the program
*Important!* This only applies to running in the khoury virtual environment as I will use Makefile to create a bin directory at your ```$HOME``` directory to copy the pwd external file to this folder. 
```make all```

### Sample output
```
k-sea-shell> help
cd
help
exit
game
k-sea-shell> pwd
/home/h9shen/H9shen_CS5008SPRING2022/a5
k-sea-shell> cd ..
k-sea-shell> pwd
/home/h9shen/H9shen_CS5008SPRING2022
k-sea-shell> game
Enter the lower bound: 1
Enter the upper bound: 4
Enter the guess: 2
Guess lower.
Enter the guess: 1
Congrats, you got it right!
k-sea-shell> exit 1
exit does not take any argument.
k-sea-shell> exit
bash-4.2$ 
```

### Builtin command names
- ```help```
- ```cd```
- ```exit```
- ```game```

### External command names
- ```pwd```

### Command Synopsis and Usage
- ```help```
    - synopsis: prints out all the available builtin commands.
    - usage: help does not take in any argument.
- ```cd```
    - synopsis: changes directory to the provided path.
    - usage: cd takes in one argument, which is the directory to be changed to.
- ```exit```
    - synopsis: exits the current shell process.
    - usage: exit does not take in any argument.
- ```game```
    - synopsis: starts a guessing game in the terminal.
    - usage: after the game starts, it will ask for two bounds, and check if the guess is within the bound
- ```pwd```
    - synopsis: prints out the current working directory.
    - usage: pwd does not take in any argument.

### Command longer description
- ```help```
    - ```help``` command will simply output all the available builtin commands, which are ```cd```, ```help```, ```exit```, and ```game```. If any argument is passed with ```help```, it will simply return without doing anything and wait for the next command from user.
- ```cd```
    - ```cd``` command will change the directory to the provided directory. If no argument is passed in or trailing spaces are passed in, it will change directory to the ```$HOME``` directory. If only one directory is passed in, it will change to that directory if it exists. If more than one directory is passed in, it will return without doing anything and wait for the next command from user.
- ```exit```
    - ```exit``` command will exit the current shell process. If executed in the parent process, it will exit the k-sea-shell process. If executed in the child process, it will only exit that shell process. If any argument is passed with ```exit```, it will simply return without doing anything and wait for the next command from user.
- ```game```
    - ```game``` command will start a builtin guessing game. The guessing game will start by asking the user for a lower and upper bound to generate a random integer value between these two bounds. The lower and upper bound can only be single integer number without any leading and trailing spaces. If the user incorrectly input other things, the program will continue asking for user's input until a valid input has been gathered. Then, it will ask for user to input a guess and compare the guess with the randomly generated value. If the guess is too low, it will ask the user to guess higher, vice versa for too high. If the user guesses the correct result, it will print out a congrats message and exit the game program. If any argument is passed with ```game```, it will simply return without doing anything and wait for the next command from user.

### How I implemented pwd command
- ```pwd```
    - ```pwd``` commands does not take any argument and will print out the current working directory. It is an external command where its shell executable file is in the ```$PATH``` of the user. When the shell sees the user input ```pwd``` in the command line, it will create a child process from the parent process using the ```fork()``` function. This will create a copy of the current environment. Then if ```fork() == 0```, it means we are in the child process, so I use ```execvp(argv[0], argv)``` and pass in the command name ```pwd``` and its arguments, which should be empty. This function will search in the ```$PATH``` and see if there is any executable file called pwd. If this executable file is found, it will execute and return to the parent process after finishing. Otherwise, it will output command not found info message.
