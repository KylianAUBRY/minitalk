/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:34:34 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/11 12:06:35 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniltalk.h"

char	*ft_join_char(char *chaine, char c)
{
	int		i;
	char	*dest;

	if (!chaine)
	{
		dest = malloc(sizeof(char) * 2);
		if (!dest)
			return (NULL);
		dest[0] = c;
		dest[1] = '\0';
		return (dest);
	}
	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(chaine) + 2));
	while (chaine[i])
	{
		dest[i] = chaine[i];
		i++;
	}
	dest[i] = c;
	dest[i + 1] = '\0';
	free(chaine);
	return (dest);
}

void	ft_action(int sig, siginfo_t *info, void *pgen)
{
	static int				i = 0;
	static unsigned char	c = 0;
	static char				*chaine = NULL;

	c |= (sig == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			ft_putstr(chaine);
			free(chaine);
			chaine = NULL;
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		chaine = ft_join_char(chaine, c);
		kill(info->si_pid, SIGUSR1);
		c = 0;
	}
	else
		c = c << 1;
	(void)pgen;
}

int	main(void)
{
	struct sigaction	signal;

	ft_putstr("PID server : ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	signal.sa_sigaction = ft_action;
	signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal, 0);
	sigaction(SIGUSR2, &signal, 0);
	while (1)
		pause();
	return (0);
}
