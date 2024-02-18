/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:17:55 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/18 18:13:21 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
