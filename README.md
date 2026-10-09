# Operating Systems — C Programs using `fork()`

This folder contains all 16 C source files represented in the assignment list you pasted, covering processes, `fork()`, `wait()`, exit status, orphan/zombie processes, Fibonacci, factorial, prime numbers, pipes, and file communication. The pasted numbering skips item 6, so no missing program has been invented.

## Run on Linux / WSL / Ubuntu

Open a terminal in this folder and compile a program:

```bash
gcc q1_pid_ppid.c -o q1_pid_ppid
./q1_pid_ppid
```

Replace the filename and output name for other programs. For example:

```bash
gcc Prime.c -o Prime
./Prime
```

To compile every C file:

```bash
for f in *.c; do gcc -Wall -Wextra "$f" -o "${f%.c}" || exit 1; done
```

These programs use POSIX APIs such as `fork()`, `pipe()`, and `wait()`, so run them in Linux or WSL rather than a native Windows compiler.

## Files

1. `q1_pid_ppid.c` — PID and PPID
2. `q2_parent_child.c` — Parent and child
3. `q3_wait.c` — `wait()`
4. `q4_fibonacci_factorial.c` — Fibonacci in child, factorial in parent
5. `q5_fibonacci_factorial_sum.c` — Fibonacci and factorial in child, sum in parent
6. `parent_even_child_odd.c` — Even and odd numbers
7. `three_child_processes.c` — Three child processes
8. `child_exit_status_wait.c` — Exit status using `wait()`
9. `orphan_process_demo.c` — Orphan process demonstration
10. `zombie_process_demo.c` — Zombie process demonstration
11. `prime_factorial_fork.c` — Prime check and factorial
12. `fibonacci_armstrong_fork.c` — Fibonacci and Armstrong numbers
13. `permutation_child.c` — Array sum and prime check (as specified in the supplied task)
14. `sum_prime_child.c` — Array sum and prime check
15. `Prime.c` — Pipe communication
16. `input.c` — File communication using `input.txt`

The pasted list has a numbering gap at item 6 and contains 16 named program tasks. The two array tasks share essentially the same description. Review each program against your instructor's exact requirements before submission.

## GitHub

From the parent folder, you can commit the folder using:

```bash
git add os_fork_programs
git commit -m "Add Operating Systems fork and process programs"
git push
```
