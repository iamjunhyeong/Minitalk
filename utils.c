/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:17:55 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/17 23:02:17 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_error(int type)
{
	if (type == 1)
		ft_print_fd("Argument Error\n", 2);
	else if (type == 2)
		ft_print_fd("pid Error\n", 2);
	exit(1);
}
