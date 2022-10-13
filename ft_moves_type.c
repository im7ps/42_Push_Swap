/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:42:12 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/11 14:42:38 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_simple_moves(t_list **stack_a, t_list **stack_b, int n_a, int n_b)
{
	while (n_a > 0)
	{
		ft_ra(stack_a);
		n_a--;
	}
	while (n_a < 0)
	{
		ft_rra(stack_a);
		n_a++;
	}
	while (n_b > 0)
	{
		ft_rb(stack_b);
		n_b--;
	}
	while (n_b < 0)
	{
		ft_rrb(stack_b);
		n_b++;
	}
}

void	ft_double_rotate(t_list **stack_a, t_list **stack_b, int n_a, int n_b)
{
	if (n_a < 0)
	{
		while (n_a < 0 || n_b < 0)
		{
			ft_rrr(stack_a, stack_b);
			n_a++;
			n_b++;
		}
	}
	else
	{
		while (n_a > 0 || n_b > 0)
		{
			ft_rr(stack_a, stack_b);
			n_a--;
			n_b--;
		}
	}
	ft_simple_moves(stack_a, stack_b, n_a, n_b);
}
