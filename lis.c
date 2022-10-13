/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:29:02 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/11 15:44:46 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_replace(int *lis, int left, int right, int key)
{
	int	mid;

	mid = (left + right) / 2;
	while (left <= right)
	{
		if (lis[mid] > key)
			right = mid - 1;
		else if (lis[mid] == key)
			return (mid);
		else if (mid + 1 <= right && lis[mid + 1] >= key)
		{
			lis[mid + 1] = key;
			return (mid + 1);
		}
		else
			left = mid + 1;
		mid = (left + right) / 2;
	}
	if (mid == left)
	{
		lis[mid] = key;
		return (mid);
	}
	lis[mid + 1] = key;
	return (mid + 1);
}

void	ft_initialize_lis(int *lis, int size, int *array)
{
	int	i;

	i = 0;
	lis[0] = array[0];
	while (i < size)
	{
		lis[i] = 2147483647;
		i++;
	}
}

int	ft_search_replace(int size, int *array, int *index, int *lis)
{
	int	i;
	int	lis_length;

	i = 0;
	lis_length = -1;
	while (i < size)
	{
		index[i] = search_replace(lis, 0, i, array[i]);
		if (lis_length < index[i])
			lis_length = index[i];
		i++;
	}
	return (lis_length);
}

int	*ft_lis_final(int lis_length, int *index, int *array, int size)
{
	int	i;
	int	tmp;
	int	*lis_final;

	tmp = lis_length;
	lis_final = (int *) malloc ((lis_length + 1) * sizeof (int));
	i = size - 1;
	while (i >= 0)
	{
		if (index[i] == lis_length)
		{
			lis_final[lis_length] = array[i];
			--lis_length;
		}
		i--;
	}
	lis_final[tmp + 1] = '\0';
	return (lis_final);
}

int	*ft_lis(int	*array, int size, int *len)
{
	int	lis_length;
	int	*lis_final;
	int	*lis;
	int	*index;

	lis = malloc(sizeof(int) * size);
	index = malloc(sizeof(int) * size);
	ft_initialize_lis(lis, size, array);
	lis_length = ft_search_replace(size, array, index, lis);
	*len = lis_length + 1;
	lis_final = ft_lis_final(lis_length, index, array, size);
	free(lis);
	free(index);
	return (lis_final);
}
