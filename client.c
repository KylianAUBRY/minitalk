/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:34:24 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/11 12:07:10 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniltalk.h"

char	*g_chaine;

void	verifsing(int sig, siginfo_t *info, void *pgen)
{
	static int	nbchar = 0;

	if (sig == SIGUSR1)
		nbchar++;
	else
	{
		if (nbchar != ft_strlen(g_chaine))
		{
			ft_putstr("Error\nLe nombre de caractères reçus est différent du");
			ft_putstr(" nombre envoyé. (perte de données)\n");
			exit(1);
		}
		else
			exit(0);
	}
	(void)info;
	(void)pgen;
}

void	ft_putbit(int pid, char *str)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (str[++i])
	{
		j = 7;
		c = str[i];
		while (j >= 0)
		{
			if (c >> j & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j--;
			usleep(50);
		}
	}
	j = 7;
	while (j-- >= 0)
	{
		kill(pid, SIGUSR2);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	signal;

	if (argc != 3 || ft_strlen(argv[2]) == 0)
		return (0);
	pid = ft_atoi(argv[1]);
	g_chaine = argv[2];
	signal.sa_sigaction = verifsing;
	signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal, 0);
	sigaction(SIGUSR2, &signal, 0);
	ft_putbit(pid, argv[2]);
	return (0);
}
