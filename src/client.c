/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:01:01 by thessena          #+#    #+#             */
/*   Updated: 2025/01/09 15:00:29 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	acknowledge_signal(int bit)
{
	if (bit == 1)
		write(1, "Server got 1\n", 13);
	else if (bit == 0)
		write(1, "Server got 0\n", 13);
}

void	send_char(pid_t pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		acknowledge_signal(bit);
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		write(2, "Usage: ./client <PID> <message>\n", 32);
		return (1);
	}
	pid = atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i] != '\0')
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
