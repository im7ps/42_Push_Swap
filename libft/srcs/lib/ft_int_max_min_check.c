/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_max_min_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:40:51 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/11 21:00:58 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

int	ft_int_max_min_check(char *elem)
{
	if (ft_strlen(elem) > 11)
		return (1);
	if (ft_strlen(elem) == 10)
	{
		if (elem[0] > 50 || elem[1] > 49 || elem[2] > 52 || elem[3] > 55 \
		|| elem[4] > 52 || elem[5] > 56 || elem[6] > 51 || elem[7] > 54 \
		|| elem[8] > 52 || elem[9] > 55)
			return (1);
	}
	else if (ft_strlen(elem) == 11)
	{
		if (elem[0] != '-')
			return (1);
		if (elem[1] > 50 || elem[2] > 49 || elem[3] > 52 || elem[4] > 55 \
		|| elem[5] > 52 || elem[6] > 56 || elem[7] > 51 || elem[8] > 54 \
		|| elem[9] > 52 || elem[10] > 56)
			return (1);
	}
	return (0);
}
