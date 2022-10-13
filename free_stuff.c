/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:35:56 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/11 20:46:21 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_stuff(t_list *node, char **matrix)
{
	int	i;

	i = 0;
	if (node != NULL)
	{
		free(node);
		node = NULL;
	}
	if (matrix != NULL)
	{
		while (matrix[i])
		{
			free(matrix[i++]);
		}
		free(matrix);
		matrix = NULL;
	}
	return (0);
}

void	ft_lst_delete(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free (*stack);
		*stack = tmp;
	}
}
