/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:36:15 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/19 20:58:31 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (write(1, s, 1) == -1)
			return (0);
		s++;
	}
	return (1);
}
