#include "minitalk.h"

void    trait_message(char *data, int pid, int x)
{
    int i;
    int count;
    

    i = 0;

    while(data[i])
    {
        count = -1;
        while (++count < 8)
        {
            if (data[i] & (0x80 >> count))
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
    i++;
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
    ft_printf("%d", x);
	if (x >= 10000)
		return (700);
	else
		return (100);
}

int     main(int ac, char *av[])
{
    int   pid;
    int   x;

    
    if (ft_check_args(ac, av))
        return (-1);
    pid = ft_atoi(av[1]);
    if (pid <= 0)
        return (0);
    pid = ft_atoi(av[1]);
    x = ft_counter(av[2]);
    trait_message(av[2], pid, x);

}
