#include <stdio.h>
#include <signal.h>
#include <unistd.h>


static void signal_handler(int signal)
{
    static int i;
    static char c;

    c |= (signal == SIGUSR1);

    if (++i == 8) {
        write(1, &c, 1);
        i = 0;
        c = 0;
    }
    else
        c <<= 1;
}

int main() {

    printf("pid: %i\n", getpid());

    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    while (1) {
        pause();
    }

    return 0;
}
