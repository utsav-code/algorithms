#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid > 0) {
        // Parent process
        sleep(10);  // Parent process sleeps for 10 seconds
        printf("Parent process exiting.\n");
    } else if (child_pid == 0) {
        // Child process
        printf("Child process executing.\n");
        printf("Child process exiting.\n");
        exit(0);
    } else {
        // Fork failed
        printf("Fork failed. Exiting.\n");
        return 1;
    }

    return 0;
}
