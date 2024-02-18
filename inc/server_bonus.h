/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:50:19 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/18 22:01:58 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"

void	my_handler(int sig, siginfo_t *info, void	*context);
void	print_error(int type);
void	print_pid(void);

#endif