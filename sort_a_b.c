/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:54:15 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/11 21:38:31 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_num(int num, int *lis, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (lis[i] == num)
			return (1);
		i++;
	}
	return (0);
}	

void	ft_sort_a_b(t_list **stack_a, t_list **stack_b, int *lis, int len)
{
	int	i;
	int	len_a;

	len_a = ft_lstsize(*stack_a);
	i = 0;
	while (i < len_a)
	{
		if (ft_find_num((*stack_a)->content, lis, len) == 0)
		{
			ft_pb(stack_a, stack_b);
		}
		else
			ft_ra(stack_a);
		i++;
	}
	return ;
}

void	ft_sort_a(t_list **stack_a, t_list **stack_b, int *lis, int len)
{
	if (ft_lstsize(*stack_a) == 1)
		return ;
	else if (ft_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			ft_sa(stack_a);
	}
	else if (ft_lstsize(*stack_a) == 3)
		ft_sort_three(stack_a, stack_b, 'a');
	else if (ft_lstsize(*stack_a) > 3)
	{
		ft_sort_a_b(stack_a, stack_b, lis, len);
	}
	return ;
}
