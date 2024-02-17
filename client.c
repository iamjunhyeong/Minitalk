/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:13:48 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/17 22:44:17 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(pid_t pid, char c)
{
	int	b;

	b = 0;
	while (b < 8)
	{
		if (c & (1 << b))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		b++;
	}
}

void	send_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_bit(str[i]);
		i++;
	}
	send_bit(pid, '\n');
	send_bit(pid, '\0');
}

void ft_handler(int sig, siginfo_t *info, void *uap)
{
	uap = NULL;
	g_pid = info->si_pid;
	g_signal = sig;
}

int main(int argc, char **argv) 
{
	pid_t	pid;

	if (argc != 3 || argv[2][0] == '\0')
		print_error(1);
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 9999)
		print_error(2);
	send_str(pid, argv[2]);
    return 0;
}
