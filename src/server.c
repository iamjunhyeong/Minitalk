/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:04:41 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/19 20:41:56 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

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

void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID->[%d]\n", pid);
	ft_printf("wating a massage....\n");
}

void	my_handler(int sig, siginfo_t *info, void	*context)
{
	static int	bit;
	static char	tmp;

	(void)info;
	(void)context;
	if (sig == SIGUSR1)
		tmp |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", tmp);
		bit = 0;
		tmp = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
		print_error(1);
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_flags = SA_SIGINFO | SA_RESTART;
	act.sa_sigaction = my_handler;
	print_pid();
	if (sigaction(SIGUSR1, &act, NULL) != 0)
		print_error(3);
	if (sigaction(SIGUSR2, &act, NULL) != 0)
		print_error(4);
	while (1)
		pause();
	return (0);
}
