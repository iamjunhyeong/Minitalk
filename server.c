/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:04:41 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/17 23:09:17 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t g_pid;
static volatile sig_atomic_t g_signal;

void	print_pid(pid_t pid)
{
	ft_printf("PID->[%d]\n", pid);
	ft_printf("wating a massage....\n");
}

void ft_handler(int sig, siginfo_t *info, void	*ua)
{
	
	ua = NULL;
	g_pid = info->si_pid;
	g_signal = sig;
}

int main(int argc, char **argv) 
{
    struct sigaction act;

	(void)argv;
	if (argc != 2)
		print_error(1);

	// 시그널이 호출되었을 때 블록될 시그널 설정
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGUSR1); //block SIGUSR1
    sigaddset(&act.sa_mask, SIGUSR2); //block SIGUSR2

	// 시그널 처리를 위한 핸들러 설정 
    act.sa_flags = SA_SIGINFO | SA_RESTART;
    act.sa_sigaction = &ft_handler; // SA_SIGINFO가 지정된 경우에 사용되는 핸들러
    act.sa_handler = NULL;         // SA_SIGINFO가 지정되지 않은 경우 사용되는 기본 핸들러

	// 시그널 호출되었을 때 수행될 시그널 정보 등록 (커널에 등록됨)
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);

	print_pid(g_pid);
	// 시그널 호출까지 대기
	while (g_signal == 0)
		pause();
    return (0);
}
