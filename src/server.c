/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:00:44 by thessena          #+#    #+#             */
/*   Updated: 2025/01/09 14:51:30 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 0;

	(void)context;
	(void)info;
	if (signal == SIGUSR1)
		c |= (1 << (7 - i));
	else if (signal == SIGUSR2)
		c &= ~(1 << (7 - i));
	i++;
	if (i == 8)
	{
		if (c == '\0')
			write(1, "\nMessage received.\n", 18);
		else
			write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        perror("Fehler beim Registrieren von SIGUSR1");
        exit(EXIT_FAILURE);
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        perror("Fehler beim Registrieren von SIGUSR2");
        exit(EXIT_FAILURE);
    }
    printf("Server läuft. PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
