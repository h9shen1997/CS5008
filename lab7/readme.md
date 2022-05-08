# LAB7: Bash Lab

## Files included
1. myreport.sh
2. helloworld.sh
3. myscript.sh
4. readme.md
5. Makefile

## How to run the program
1. To run myreport.sh, simply call ```make report```
2. To run helloworld.sh, simply call ```make hello```
3. To run myscript.sh, simply call ```make script```

## Features of myscript.sh
1. Ask the user which assignment they want to get the starter code.
2. The user's input will be used to copy specific folders after git pull.
3. If the user does not enter anything, the default lab7 folder will be created and used as the destination folder for copying.
4. Every functionality is separated into function with a printout to show what has been done in the program.

## Sample output
1. Running myscript.sh
* When the user enter nothing:
```
Please enter the assignment of which starter code you want:
Changed to resource directory '/home/h9shen/Course_Resources'.
Make a new github directory '/home/h9shen/H9shen_CS5008SPRING2022/lab7' if it does not exist.
Git pull
Already up-to-date.
Copied changed files from resource directory '/home/h9shen/Course_Resources/lab7' to my github directory '/home/h9shen/H9shen_CS5008SPRING2022/lab7'.
```

* When the user enter something, for example, lab6:
```
Please enter the assignment of which starter code you want:lab6
Changed to resource directory '/home/h9shen/Course_Resources'.
Make a new github directory '/home/h9shen/H9shen_CS5008SPRING2022/lab6' if it does not exist.
Git pull
Already up-to-date.
Copied changed files from resource folder '/home/h9shen/Course_Resources/lab6' to my github directory '/home/h9shen/H9shen_CS5008SPRING2022/lab6'.
```

2. Running helloworld.sh
```
Hello, CS5008!
```

3. Running myreport.sh
The output will be redirected into the file report.txt.

## Who did I work with
Myself

## How long did this take you?
2 hours