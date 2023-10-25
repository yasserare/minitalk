#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void convert_and_send(int pid, char c)
{
    printf("pid => %i\n", pid);
    int i = 0;
    while(i < 8)
    {
        if (c & 128)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        c <<= 1;
        i++;
        sleep(1);
    }
}

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        int pid = atoi(argv[1]);
        char *string = argv[2];
        printf("The string is %s and the pid is %i\n", string, pid);
        //send string to that pid
            //convert each byte into binary and send 
        int i = 0;
        while (string[i])
            convert_and_send(pid, string[i++]);
    }
    else
        printf("Be sure that the input is formatted as './client <pid> <string>'");
    return (0);
}