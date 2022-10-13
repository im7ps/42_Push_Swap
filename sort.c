/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:19:50 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/13 14:40:22 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_real_sort(t_list **stack_a, t_list **stack_b, int best_number)
{
	int	n_moves_a;
	int	n_moves_b;

	n_moves_a = ft_find_a_moves(best_number, ft_lstsize(*stack_a), stack_a);
	n_moves_b = ft_find_b_moves(best_number, ft_lstsize(*stack_b), stack_b);
	if ((n_moves_a < 0 && n_moves_b < 0) || (n_moves_a > 0 && n_moves_b > 0))
		ft_double_rotate(stack_a, stack_b, n_moves_a, n_moves_b);
	else
		ft_simple_moves(stack_a, stack_b, n_moves_a, n_moves_b);
	ft_pa(stack_a, stack_b);
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_ra(stack_a);
}

void	ft_sort_b(t_list **stack_a, t_list **stack_b)
{
	int		best_number;

	while (ft_lstsize(*stack_b) > 0)
	{
		{
			best_number = ft_find_best(stack_a, stack_b);
			ft_real_sort(stack_a, stack_b, best_number);
		}
	}
	return ;
}

void	ft_sort(t_list **stack_a, t_list **stack_b, int	*array)
{
	int		*lis;
	int		len;

	if (ft_lstsize(*stack_a) == 3)
	{
		ft_sort_three(stack_a, stack_b, 'a');
		if (ft_lstsize(*stack_b) == 0)
			return ;
	}
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 3)
		ft_sort_three(stack_a, stack_b, 'a');
	lis = ft_lis(array, ft_lstsize(*stack_a), &len);
	ft_sort_a(stack_a, stack_b, lis, len);
	ft_sort_b(stack_a, stack_b);
	while (ft_identity_test(stack_a) == 0)
	{
		ft_rra(stack_a);
	}
	free(lis);
	lis = NULL;
	return ;
}
