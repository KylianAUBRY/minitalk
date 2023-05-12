/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniltalk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:06:44 by kyaubry           #+#    #+#             */
/*   Updated: 2023/05/06 12:46:51 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILTALK_H
# define MINILTALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_putchar(char c);
int		ft_atoi(const char *nptr);
int		ft_strlen(char *chaine);

#endif