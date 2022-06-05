/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:53:21 by vismaily          #+#    #+#             */
/*   Updated: 2022/06/05 16:11:13 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft.h"

void	send_bit_by_bit(int pid, char *argv)
{
	size_t	len;
	size_t	i;
	int		shift;

	len = ft_strlen(argv);
	i = 0;
	while (i < len)
	{
		shift = 0;
		while (shift < 8)
		{
			if ((argv[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_bit_by_bit(pid, argv[2]);
	}
	else
		write(1, "./client pid message\n", 21);
	return (0);
}
