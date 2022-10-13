/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:22:19 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/13 14:48:30 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/includes/libft.h"
# include "./libft/includes/ft_printf.h"

typedef struct s_triplet
{
	int	i;
	int	j;
	int	k;
}	t_triplet;
int		check_argv(int argc, char **argv);
int		upload_list(int argc, char **argv, t_list **stack_a);
void	upload_case_1(char **argv, t_list	**stack_a, int i);
void	upload_case_2(int argc, char **argv, t_list	**stack_a, int i);
int		ft_identity_test(t_list **stack);

int		ft_is_digit(char *s);
int		ft_double_check(t_list **stack_a, int size, int i, int *tmp);
int		ft_limits_check(int argc, char **argv);

int		*to_array(t_list **stack, int start, int end);

void	ft_sort_a(t_list **stack_a, t_list **stack_b, int *lis, int len);
void	ft_sort_b(t_list **stack_a, t_list **stack_b);
void	ft_sort(t_list **stack_a, t_list **stack_b, int	*array);
void	ft_sort_a_b(t_list **stack_a, t_list **stack_b, int *lis, int len);

void	ft_sort_three(t_list **stack_a, t_list **stack_b, char stack);
void	ft_sort_three_1a(t_list **stack_a, t_triplet triplet);
void	ft_sort_three_2a(t_list **stack_a, t_triplet triplet);
void	ft_sort_three_1b(t_list **stack_a, t_list **stack_b, t_triplet triplet);
void	ft_sort_three_2b(t_list **stack_a, t_list **stack_b, t_triplet triplet);

int		*ft_lis(int	*array, int size, int *len);
int		*ft_lis_final(int lis_length, int *index, int *array, int size);
int		ft_search_replace(int size, int *array, int *index, int *lis);
void	ft_initialize_lis(int *lis, int size, int *array);
int		search_replace(int *lis, int left, int right, int key);

void	ft_rotate(t_list **stack);
void	ft_rrotate(t_list **stack);
void	swap_nodes(t_list **head_ref, t_list *curr, t_list *second);
int		ft_sa(t_list **stack_a);
int		ft_sb(t_list **stack_b);
int		ft_ss(t_list **stack_a, t_list **stack_b);
int		ft_pa(t_list **stack_a, t_list **stack_b);
int		ft_pb(t_list **stack_a, t_list **stack_b);
int		ft_ra(t_list **stack_a);
int		ft_rb(t_list **stack_b);
int		ft_rr(t_list **stack_a, t_list **stack_b);
int		ft_rra(t_list **stack_a);
int		ft_rrb(t_list **stack_b);
int		ft_rrr(t_list **stack_a, t_list **stack_b);

int		free_stuff(t_list *node, char **matrix);
void	ft_lst_delete(t_list **stack);

int		ft_find_best(t_list	**stack_a, t_list	**stack_b);
int		ft_find_a_moves(int b_content, int size_a, t_list	**stack_a);
int		ft_find_b_moves(int b_content, int size_b, t_list	**stack_b);
int		ft_is_the_lowest(t_list **stack_a, int content);
int		ft_is_the_highest(t_list **stack_a, int content);
int		ft_handle_lowest_highest(t_list	**stack_a, int b_content, int size_a);

void	ft_double_rotate(t_list **stack_a, t_list **stack_b, int n_a, int n_b);
void	ft_simple_moves(t_list **stack_a, t_list **stack_b, int n_a, int n_b);
int		ft_calculate_moves(t_list **stack_a, t_list **stack_b, int b_content);
int		ft_find_total(int n_moves_a, int n_moves_b);
int		ft_find_b_moves(int b_content, int size_b, t_list	**stack_b);
int		ft_find_a_moves(int b_content, int size_a, t_list	**stack_a);
int		ft_find_lowest(t_list **stack);
int		ft_find_higher(t_list **stack);
int		ft_are_all_lower(t_list **stack_a, t_list **stack_b);
#endif