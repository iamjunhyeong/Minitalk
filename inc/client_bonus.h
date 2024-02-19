/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:51:55 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/19 20:44:31 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"

void	print_error(int type);
void	send_bit(pid_t pid, char c);
void	send_str(pid_t pid, char *str);
void	success_msg(int sig);

#endif