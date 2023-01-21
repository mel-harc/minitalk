#include "minitalk.h"

void    signl_handler(int signum, siginfo_t *info, void *context)
{
    static int bits = 0;
    static char c = 0xff;
    static  int client_pid;

    (void)context;
    if (client_pid != info->si_pid)
    {
        c = 0xff;
        bits = 0;
    }
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
        if (c == '\0')
            kill(client_pid, SIGUSR1);
        ft_printf("%c", c);
        c = 0xff;
        bits = 0;
    }
    client_pid = info->si_pid;
}

int main(int ac, char **av)
{
    struct sigaction action;
    pid_t   pid;

    (void)ac;
    (void)av;
    action.sa_sigaction = &signl_handler;
    action.sa_flags = SA_SIGINFO;

    pid = getpid();
    ft_printf("PID : %d\n", pid);
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    while(1)
        pause();
}