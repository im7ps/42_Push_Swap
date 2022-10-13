/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:19:17 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/13 14:20:37 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_double_check(t_list **stack_a, int size, int i, int *tmp)
{
	int	num;
	int	j;

	while (i < size)
	{
		if (i < size)
		{
			j = i + 1;
			num = tmp[i];
			while (j < size)
			{
				if (num == tmp[j])
				{
					ft_lst_delete(stack_a);
					return (1);
				}
				j++;
			}
		}
		i++;
	}
	free(tmp);
	tmp = NULL;
	return (0);
}

int	ft_limits_check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
	}
	while (argv[i])
	{
		if (ft_int_max_min_check(argv[i]) == 1)
		{
			if (argc == 2)
				free_stuff(NULL, argv);
			return (1);
		}
		i++;
	}
	if (argc == 2)
		free_stuff(NULL, argv);
	return (0);
}

int	check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
	}
	else
	{
		i = 1;
	}
	while (argv[i])
	{
		if (ft_is_digit(argv[i]) == 1)
			return (1);
		i++;
	}
	if (argc == 2)
		free_stuff(NULL, argv);
	return (0);
}
