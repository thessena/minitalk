/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:03:13 by thessena          #+#    #+#             */
/*   Updated: 2024/12/13 10:03:45 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# define BIT_COUNT 8

void    send_message(int server_pid, const char *message);

void    handle_signal(int signal);

void    error_exit(const char *error_message);

#endif
