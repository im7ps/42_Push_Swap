/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:31:08 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/11 20:49:26 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_moves_a_helper(int size_a, int b_content, t_list **stack_a)
{
	int	counter;
	int	*tmpa;

	counter = 0;
	tmpa = to_array(stack_a, 0, size_a);
	while (size_a > 0)
	{
		if (tmpa[counter] < b_content && tmpa[counter + 1] > b_content)
		{
			counter++;
			break ;
		}
		counter++;
		size_a--;
	}
	free(tmpa);
	tmpa = NULL;
	return (counter);
}

int	ft_find_a_moves(int b_content, int size_a, t_list	**stack_a)
{
	int	counter;

	if (ft_is_the_lowest(stack_a, b_content) == 1 || \
		ft_is_the_highest(stack_a, b_content) == 1)
	{
		counter = ft_handle_lowest_highest(stack_a, b_content, size_a);
		return (counter);
	}
	counter = ft_moves_a_helper(size_a, b_content, stack_a);
	if (counter > ft_lstsize(*stack_a) / 2 + (ft_lstsize(*stack_a) % 2))
		return (counter - ft_lstsize(*stack_a));
	else
		return (counter);
}

int	ft_find_b_moves(int b_content, int size_b, t_list	**stack_b)
{
	t_list	*tmpb;
	int		counter;

	tmpb = *stack_b;
	counter = 0;
	while (tmpb)
	{
		if (tmpb->content == b_content)
			break ;
		counter++;
		tmpb = tmpb->next;
	}
	if (counter > (size_b / 2 + size_b % 2))
		return (counter - size_b);
	else
		return (counter);
	free(tmpb);
	tmpb = NULL;
}

int	ft_find_total(int n_moves_a, int n_moves_b)
{
	int	t_moves;
	int	max;

	if (ft_abs_value(n_moves_a) > ft_abs_value(n_moves_b))
		max = ft_abs_value(n_moves_a);
	else
		max = ft_abs_value(n_moves_b);
	if ((n_moves_a < 0 && n_moves_b < 0) || (n_moves_a > 0 && n_moves_b > 0))
		return (max);
	else
		t_moves = ft_abs_value(n_moves_b) + ft_abs_value(n_moves_a);
	return (t_moves);
}

int	ft_calculate_moves(t_list **stack_a, t_list **stack_b, int b_content)
{
	int	n_moves_a;
	int	n_moves_b;
	int	t_moves;

	n_moves_b = ft_find_b_moves(b_content, ft_lstsize(*stack_b), stack_b);
	n_moves_a = ft_find_a_moves(b_content, ft_lstsize(*stack_a), stack_a);
	t_moves = ft_find_total(n_moves_a, n_moves_b);
	return (t_moves);
}
