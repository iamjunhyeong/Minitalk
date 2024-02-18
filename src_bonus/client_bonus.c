/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:13:48 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/18 22:42:51 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client_bonus.h"

void	success_msg(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("[SERVER RECEIPT SECCESSFULLY]\n");
	exit(0);
}

void	print_error(int type)
{
	if (type == 1)
		ft_putstr_fd("Argument Error\n", 2);
	else if (type == 2)
		ft_putstr_fd("pid Error\n", 2);
	else if (type == 3)
		ft_putstr_fd("Sigaction1 Error\n", 2);
	else if (type == 4)
		ft_putstr_fd("Sigaction2 Error\n", 2);
	exit(1);
}

void	send_bit(pid_t pid, char c)
{
	int	b;

	b = 0;
	while (b < 8)
	{
		if ((c & (1 << b)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		b++;
	}
}

void	send_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_bit(pid, str[i]);
		i++;
	}
	send_bit(pid, '\n');
	send_bit(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3 || argv[2][0] == '\0')
		print_error(1);
	if (signal(SIGUSR1, success_msg) != 0)
		print_error(3);
	pid = ft_atoi(argv[1]);
	// if (pid < 100 || pid > 9999)
	// 	print_error(2);
	send_str(pid, argv[2]);
	while (1)
		pause();
		
	return (0);
}
