/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:13:48 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/19 20:44:08 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

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
	pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);
	return (0);
}
