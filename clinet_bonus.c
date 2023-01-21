#include "minitalk.h"

void    trait_message(char data, int pid, int x)
{
    int count;

    count = -1;
    while (++count < 8)
    {
        if (data & (0x80 >> count))
        {
            if (kill(pid, SIGUSR2) == -1)
                exit(1);
        }
        else
        {    
            if (kill(pid, SIGUSR1) == -1)
                exit(1);
        }
        usleep(x);
    }
}

static  int    ft_check_args(int argc, char **argv)
{
    int i;

    i = -1;
    if (argc != 3)
        return (1);
    while (argv[1][++i])
    {
        if (!ft_strchr("0123456789", argv[1][i]))
            return (1);
    }
    return (0);  
}

static size_t   ft_counter(char *av)
{
    int		x;

	x = ft_strlen(av);
	if (x >= 10000)
		return (1500);
	else
		return (500);
}

void    finaly_function(int n)
{
    if (n == SIGUSR1)
        ft_printf("recieve\n");
}

int     main(int ac, char *av[])
{
    int   pid;
    int   x;
    int    i;

    i = -1;
    signal(SIGUSR1, finaly_function);
    if (ft_check_args(ac, av))
        return (-1);
    pid = ft_atoi(av[1]);
    if (pid <= 0)
        return (0);
    pid = ft_atoi(av[1]);
    x = ft_counter(av[2]);
    while(av[2][++i])
        trait_message(av[2][i], pid, x);
    trait_message('\0', pid, 100);
    return(0);
}