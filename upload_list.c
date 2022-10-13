/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:19:50 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/13 14:16:22 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	upload_case_1(char **argv, t_list	**stack_a, int i)
{
	t_list	*tmp;

	while (argv[i])
	{
		tmp = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, tmp);
		i++;
	}
	return ;
}

void	upload_case_2(int argc, char **argv, t_list	**stack_a, int i)
{
	t_list	*tmp;

	while (++i < argc)
	{
		tmp = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, tmp);
	}
	return ;
}

int	upload_list(int argc, char **argv, t_list	**stack_a)
{
	int	*tmp;

	if (check_argv(argc, argv) == 1)
		return (1);
	if (ft_limits_check(argc, argv) == 1)
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		upload_case_1(argv, stack_a, 0);
		free_stuff(NULL, argv);
	}
	else if (argc > 2)
	{
		upload_case_2(argc, argv, stack_a, 0);
	}
	tmp = to_array(stack_a, 0, ft_lstsize(*stack_a));
	if (ft_double_check(stack_a, ft_lstsize(*stack_a), 0, tmp) == 1)
	{
		free(tmp);
		tmp = NULL;
		return (1);
	}
	return (0);
}
