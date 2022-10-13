/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:43:28 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/11 15:18:55 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three_1a(t_list **stack_a, t_triplet triplet)
{
	if (triplet.j > triplet.k)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (triplet.i > triplet.k)
	{
		ft_ra(stack_a);
	}
	else if (triplet.i < triplet.k)
	{
		ft_sa(stack_a);
	}
}

void	ft_sort_three_2a(t_list **stack_a, t_triplet triplet)
{
	if (triplet.i > triplet.k)
	{
		ft_rra(stack_a);
	}
	else if (triplet.j > triplet.k)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
}

void	ft_sort_three_1b(t_list **stack_a, t_list **stack_b, t_triplet triplet)
{
	if (triplet.j < triplet.k)
	{
		ft_sb(stack_b);
		ft_rrb(stack_b);
	}
	else if (triplet.i < triplet.k)
	{
		ft_rb(stack_b);
	}
	else if (triplet.i > triplet.k)
	{
		ft_sb(stack_b);
	}
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_three_2b(t_list **stack_a, t_list **stack_b, t_triplet triplet)
{
	if (triplet.i < triplet.k)
	{
		ft_rrb(stack_b);
	}
	else if (triplet.j < triplet.k)
	{
		ft_sb(stack_b);
		ft_rb(stack_b);
	}
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_three(t_list **stack_a, t_list **stack_b, char stack)
{
	t_list		*tmp;
	t_triplet	triplet;

	tmp = NULL;
	if (stack == 'a')
		tmp = *stack_a;
	else if (stack == 'b')
		tmp = *stack_b;
	triplet.i = tmp->content;
	triplet.j = tmp->next->content;
	triplet.k = tmp->next->next->content;
	if (stack == 'b')
	{
		if (triplet.i < triplet.j)
			ft_sort_three_1b(stack_a, stack_b, triplet);
		else if (triplet.i > triplet.j)
			ft_sort_three_2b(stack_a, stack_b, triplet);
	}
	else if (stack == 'a')
	{
		if (triplet.i > triplet.j)
			ft_sort_three_1a(stack_a, triplet);
		else if (triplet.i < triplet.j)
			ft_sort_three_2a(stack_a, triplet);
	}
}
