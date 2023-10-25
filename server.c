#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signal)
{
    printf("recieved signal\n");
    if (signal == SIGUSR1)
        printf("1");
    else if (signal == SIGUSR2)
        printf("0");
    printf("\n");
}

int main() {
    pid_t pid = getpid();
    printf("Process ID (PID): %d\n", pid);
    
    int i = 0;
    while (i < 8)
    {
        if (signal(SIGUSR1, signal_handler))
            printf("Recieved signal handler 1\n");
        else if (signal(SIGUSR2, signal_handler))
            printf("Recieved signal handler 2\n");
        //pause();
        i++;
    }

    sleep(10); // Sleep for 10 seconds to keep the program running

    while (1) {};

    return 0;
}
