#include "minitalk.h"

void    signl_handler(int signum)
{
    static int bits = 0;
    static char c = 0xff;

    if (signum == SIGUSR1)
    {
        c ^= 0x80 >> bits;
    }
    else if (signum == SIGUSR2)
    {
        c |= 0x80 >> bits;
    }
    bits++;
    if (bits == 8)
    {
        ft_printf("%c", c);
        c = 0xff;
        bits = 0;
    }
}

int main()
{
    pid_t   pid;

    pid = getpid();
    ft_printf("PID : %d\n", pid);
    signal(SIGUSR1, signl_handler);
    signal(SIGUSR2, signl_handler);
    while(1)
        pause();
}