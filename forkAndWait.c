#include <stdio.h>      // For standard input and output functions
#include <sys/wait.h>   // For the wait() system call
#include <unistd.h>     // For fork(), getpid(), and getppid() functions

int main() {
    pid_t pid = fork(); // Create a new process using fork()

    // Check if fork() succeeded and determine whether this is the parent or child process
    if (pid == 0) { 
        // This block executes in the child process
        printf("Child process created\n");
        printf("This is the child process. Process ID (PID) = %d\n", getpid());
        printf("Parent process ID (PPID) from the child's perspective = %d\n", getppid());
    } 
    else if (pid > 0) { 
        // This block executes in the parent process
        wait(NULL); // Parent waits for the child process to finish
        printf("This is the parent process\n");
        printf("Parent process ID (PID) from the parent's perspective = %d\n", getpid());
        printf("Child process ID (PID) from the parent's perspective = %d\n", pid);
    } 
    else { 
        // This block executes if fork() fails
        printf("Failed to create a new process\n");
    }

    return 0; // Exit the program
}
