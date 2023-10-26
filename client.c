/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasserar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:43:17 by yasserar          #+#    #+#             */
/*   Updated: 2023/10/26 08:51:53 by yasserar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	convert_and_send(int pid, char c)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (i < 8)
	{
		if (c & 128)
			err = kill(pid, SIGUSR1);
		else
			err = kill(pid, SIGUSR2);
		if (err == -1)
		{
			ft_printf("Failure transmating !");
			exit(EXIT_FAILURE);
		}
		c <<= 1;
		i++;
		usleep(500);
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*string;
	int		i;

	pid = ft_atoi(argv[1]);
	string = argv[2];
	i = 0;
	if (argc == 3)
	{
		while (string[i])
			convert_and_send(pid, string[i++]);
	}
	else
		ft_printf("input should be formatted as './client <pid> <string>'");
	return (0);
}
