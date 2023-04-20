# C - Strace

## General

- What is strace, and what is its purpose
- What is ptrace, and what possibilties it offers
- What are the differences between PTRACE_SINGLESTEP and PTRACE_SYSCALL
- How to read from and/or write to the memory of a process being traced

# More Info

## Data Structure

This project requires you to parse the files /usr/include/asm/unistd_64.h and /usr/include/asm/unistd_32.h, in order to get the number corresponding to each syscall. It also requires you to do some man-scraping to get information about syscalls prototypes, in order to know the return type of each syscall, as well as its number of arguments and their type.

Since this is a very time-consuming task, you are given a header file, containing all these informations, allowing you to focus on the ptrace part of this project.

Please note that you are completely allowed to use your own data structure(s) and/or to modify the one provided to you, which is only here to help you getting started with strace, it does not contain everything you need for a complete strace.
