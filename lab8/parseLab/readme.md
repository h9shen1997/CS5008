## Lab8: Parser Lab

### Directory
All the files are in the lab8/parseLab folder.

### Name
Haotian Shen

### Hours taken
30 minutes

### Collaborator
None

### External resources
None

### Files included
- Makefile
- parse.c
- readme.md

### How to run the program
```
make all
./parse args*
```
*Important!* args* is the argument string to be passed with the program. You need to pass this by yourself.

### Sample output
Output1:
```
bash-4.2$ ./parse "ls -l"
ls
-l
```

Output2:
```
bash-4.2$ ./parse "cd ."
cd
.
```

Output3:
```
bash-4.2$ ./parse "cat compile.py | head 2"
cat
compile.py
|
head
2
```





