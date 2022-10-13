/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_int_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:27:49 by sgerace           #+#    #+#             */
/*   Updated: 2022/09/23 17:17:21 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

int	*ft_join_int_array(int *s1, int *s2)
{
	size_t	i;
	size_t	c;
	int		*str;

	if (!s1)
	{
		s1 = (int *)malloc(1 * sizeof(int));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_array_lenght(s1) + ft_array_lenght(s2) + 1) * sizeof(int));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_array_lenght(s1) + ft_array_lenght(s2)] = '\0';
	free(s1);
	return (str);
}
