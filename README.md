# Collatz conjecture
The Collatz conjecture concerns what happens when we take any positive integer n and apply the following algorithm:
  
  The conjecture states that when this algorithm is continually applied, all positive integers will eventually reach 1. For example, if n = 19, the sequence is 
    
    19, 58, 29, 88, 44, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1
    
# Requirements
## Description
Write a program using the fork() system call that generates this sequence in the child process.
The starting number will be provided from the command line. For example, if 19 is passed as
a parameter on the command line, the child process will output the above sequence. Because
the parent and child process has their own copies of the data, it will be necessary for the child
to output the sequence. Have the parent invoke the wait() call to wait for the child process to
complete before existing program. Perform necessary error checking to ensure that a positive
integer is passed on the command line.

Whenever we enter a number, the program should create a child process, which will generate
the sequence. Therefore, while it is running to make the sequence, the parent process should
wait and then will continue after the child process completes.

## Execution
The program begins when we enter “collatz” without any parameters. And the collatz
sequence will be generated upon the number that we enter. It will continue to receive a
number until “q” (meaning quit) is entered. See the example below.

```
user_account> collatz
what is your number? 19
19, 58, 29, 88, 44, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1
what is your number? 35
35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1
what is your number? q
user_account>
```

## Handling Exceptions
The program must catch errors in execution. The errors may occur when user enters wrong
input (character, multiple numbers, etc.). When the program detects any error cases, it
should handle properly by giving some error messages to the user, and still be runnable.
**The program which fails to catch and handle such errors will be taken off penalty points**.
