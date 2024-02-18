/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:04:41 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/18 22:03:22 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server_bonus.h"

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

void my_handler(int sig, siginfo_t *info, void	*context)
{
	static int	bit;
	static char	tmp;
	pid_t		pid;

	pid = info->si_pid;
	(void)context;
	if (sig == SIGUSR1)
		tmp |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (tmp != '\0')
			ft_printf("%c", tmp);
		else
			kill(pid, SIGUSR1);
		bit = 0;
		tmp = 0;
	}
}

int main(int argc, char **argv) 
{
    struct sigaction act;

	(void)argv;
	if (argc != 1)
		print_error(1);

	// 시그널이 호출되었을 때 블록될 시그널 설정
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGUSR1); //block SIGUSR1
    sigaddset(&act.sa_mask, SIGUSR2); //block SIGUSR2

	// 시그널 처리를 위한 핸들러 설정 
    act.sa_flags = SA_SIGINFO | SA_RESTART;
    act.sa_sigaction = my_handler; // SA_SIGINFO가 지정된 경우에 사용되는 핸들러
    // act.sa_handler = NULL;         // SA_SIGINFO가 지정되지 않은 경우 사용되는 기본 핸들러

	print_pid();
	
	// 시그널 호출되었을 때 수행될 시그널 정보 등록 (커널에 등록됨)
    if (sigaction(SIGUSR1, &act, NULL) != 0)
		print_error(3);
    if (sigaction(SIGUSR2, &act, NULL) != 0)
		print_error(4);

	// 시그널 호출까지 대기
	while (1)
		pause();
    return (0);
}
