#include "minitalk.h"

void    signl_handler(int signum, siginfo_t *info)
{
    static int bits = 0;
    static char c = 0xff;
    static  int client_pid;

    if (client_pid != info->si_pid || !client_pid)
    {
        c = 0xff;
        bits = 0;
    }
    client_pid = info->si_pid;
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
    struct sigaction *action;
    pid_t   pid;


    action->sa_handler = (void *)signl_handler;
    pid = getpid();
    ft_printf("PID : %d\n", pid);
    sigaction(SIGUSR1, action, NULL);
    sigaction(SIGUSR2, action, NULL);
    while(1)
        pause();
}