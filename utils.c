/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:36:24 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/13 16:00:16 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_identity_test(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->content < tmp->next->content)
			tmp = tmp->next;
		else
		{
			return (0);
		}
	}
	return (1);
}

int	*to_array(t_list **stack, int start, int end)
{
	t_list	*tmp;
	int		i;
	int		*array;

	tmp = *stack;
	if (tmp == NULL)
		return (0);
	i = 0;
	array = (int *) malloc (sizeof(int) * (end - start) + 1);
	while (i < start)
	{
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while (i < end)
	{
		array[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	array[i] = '\0';
	return (array);
}

int	ft_is_digit(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] > 47 && s[i] < 58)
			i++;
		else if (s[i] == '-' || s[i] == '+' || s[i] == ' ')
		{
			if (i < len)
			{
				if (s[i + 1] > 47 && s[i + 1] < 58)
					i++;
				else
					return (1);
			}
			else
				return (1);
		}
		else
			return (1);
	}
	return (0);
}
