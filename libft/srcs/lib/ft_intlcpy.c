/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:58:48 by sgerace           #+#    #+#             */
/*   Updated: 2022/09/23 17:14:41 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

int	*ft_intlcpy(int *dst, const int *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	dst = malloc (sizeof(int) * (dstsize + 1));
	while (*src && i < dstsize)
	{
		dst[i] = *src++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
