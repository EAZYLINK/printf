# _printf

Hello, welcome to our first group project, we're replicating the printf() fucntion from the C Standard Library.


## Introduction to the project

printf (print formatted) in C, writes out a cstring to stdout (standard output). The provided cstring may contain format specifiers( beginning with % in the cstring).

### Syntax

`` int printf (const char* c-string, ...);``

- Return Value: If the function successfully executes, it returns the total number of characters written to the standard output. If an error occurs, a negative number is returned.

- Arguments: c-string is the string passed to the function. There can be additional arguments following c-string, if there exist format specifiers in the c-string, as discussed above.



## <h3>Specifiers </h3>
Specifier characters at the end define the type and the interpretation of its corresponding argument:

| Specifier  | Output          |
|------------|-----------------|
| `c`        | character       |
| `s`        | string          |
| `d` or `i` | Signed integers |
| `%`        | %               |

## Requirements

### General  

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You are not allowed to use global variables
- No more than 5 functions per file
- In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called main.h
- Don’t forget to push your header file
- All your header files should be include guarded
- Note that we will not provide the _putchar function for this project

