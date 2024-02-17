/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:11:23 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/17 22:59:36 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"


void	ft_putstr_fd(char *s, int fd);
void	print_error(int type);

int		ft_atoi(const char *str);
int		is_space(char c);


#endif
