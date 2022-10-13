/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:19:50 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/13 14:44:26 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a == NULL)
		return (1);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	ft_printf("pb\n");
	return (0);
}

void	swap_nodes(t_list	**head_ref, t_list *curr, t_list *second)
{
	t_list	*tmp;

	if (curr == NULL || curr->next == NULL)
		return ;
	*head_ref = second;
	tmp = second->next;
	second->next = curr;
	curr->next = tmp;
}

int	ft_sa(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (tmp == NULL || tmp->next == NULL)
		return (1);
	swap_nodes(stack_a, tmp, tmp->next);
	ft_printf("sa\n");
	return (0);
}

int	ft_sb(t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	if (tmp == NULL || tmp->next == NULL)
		return (1);
	swap_nodes(stack_b, tmp, tmp->next);
	ft_printf("sb\n");
	return (0);
}

int	ft_ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	if (tmp_a == NULL || tmp_a->next == NULL || \
	tmp_b == NULL || tmp_b->next == NULL)
		return (1);
	swap_nodes(stack_a, tmp_a, tmp_a->next);
	swap_nodes(stack_b, tmp_b, tmp_b->next);
	ft_printf("ss\n");
	return (0);
}
