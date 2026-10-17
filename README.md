# Copy-on-Write Memory Demonstrator

## 1. Project Overview

The Copy-on-Write (COW) Memory Demonstrator is an Operating Systems project that demonstrates how Linux manages memory when a parent process creates a child process using `fork()`.

Initially, both processes see the same memory contents. When the child modifies its memory, Copy-on-Write allows the child to modify a private copy while the parent's value remains unchanged.

## 2. Objectives

- Understand the Copy-on-Write memory management technique.
- Demonstrate process creation using `fork()`.
- Observe memory isolation between parent and child processes.
- Understand private memory mappings using `mmap()`.
- Verify that changes made by the child do not affect the parent.

## 3. Technologies Used

- **Programming Language:** C
- **Operating System:** Ubuntu 24.04 LTS on WSL2
- **Compiler:** GCC
- **System Calls:** `fork()`, `mmap()`, `waitpid()`, `munmap()`

## 4. Project Structure

```text
cow-memory-demo/
├── cow_demo.c
└── README.md
```

## 5. Prerequisites

- Windows Subsystem for Linux (WSL2)
- Ubuntu Linux
- GCC compiler
- Basic knowledge of C programming and Linux commands

## 6. Installation and Setup

Update the package list:

```bash
sudo apt update
```

Install the C compiler:

```bash
sudo apt install build-essential -y
```

Create the project directory:

```bash
mkdir -p ~/cow-memory-demo
cd ~/cow-memory-demo
```

Create the source file:

```bash
nano cow_demo.c
```

Paste the project source code into the file and save it using `Ctrl + O`, `Enter`, and `Ctrl + X`.

## 7. Compilation

Compile the program using GCC:

```bash
gcc -Wall -Wextra cow_demo.c -o cow_demo
```

If compilation succeeds without errors, the executable named `cow_demo` will be created.

## 8. Execution

Run the program:

```bash
./cow_demo
```

## 9. Expected Output

```text
Initial value: 100
Child before write: 100
Child after write: 200
Parent after child write: 100
```

The exact output ordering may vary slightly depending on process scheduling.

## 10. Working Principle

1. The program allocates a private anonymous memory mapping using `mmap()`.
2. The initial memory value is set to `100`.
3. The `fork()` system call creates a child process.
4. The child changes its memory value from `100` to `200`.
5. The parent waits for the child to finish using `waitpid()`.
6. The parent reads its memory and finds that the value is still `100`.

Linux implements Copy-on-Write by allowing memory pages to be shared until a write requires a private copy.

## 11. Testing and Validation

| Test Case | Expected Result | Status |
|---|---|---|
| Initialize memory | Value is 100 | Passed |
| Create child process | Child process is created | Passed |
| Modify child memory | Child value becomes 200 | Passed |
| Check parent memory | Parent value remains 100 | Passed |

## 12. Advantages

- Demonstrates efficient memory management.
- Helps explain process isolation in Linux.
- Uses standard Linux system calls.
- Provides a simple, repeatable experiment for OS laboratory evaluation.

## 13. Limitations

- The program demonstrates COW behavior but does not directly inspect physical page frames.
- Exact memory-copy timing is handled internally by the Linux kernel.
- The output demonstrates the values observed by each process rather than measuring memory-performance improvements.

## 14. Conclusion

The Copy-on-Write Memory Demonstrator successfully illustrates how Linux allows parent and child processes to begin with the same memory contents while keeping their subsequent modifications isolated. The project provides a practical understanding of process creation, virtual memory, and operating-system memory management.

## 15. Author and Repository

**Project Title:** Copy-on-Write Memory Demonstrator

**GitHub Repository:** Add your repository URL after publishing the project.

**Execution Environment:** Ubuntu 24.04 LTS on WSL2.
# OPERATING-SYSTEM-FINAL-HACKATHON-
