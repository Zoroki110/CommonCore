/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:14:12 by trouilla          #+#    #+#             */
/*   Updated: 2025/06/14 11:02:50 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/include/ft_printf.h"
# include "../Libft/include/get_next_line.h"
# include "../Libft/include/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				size_a;
	int				size_b;
}					t_data;

// atoi.c
int					handle_sign(const char *str, int *i);
int					convert_digits(const char *str, int *i, long *result,
						int *error);
int					ft_atoi_safe(const char *str, int *error);

// error.c
void				ft_error(void);
void				free_data(t_data *data);

// operation_utils_2.c
void				rb(t_data *data, int print);
void				rr(t_data *data, int print);
void				rra(t_data *data, int print);
void				rrb(t_data *data, int print);
void				rrr(t_data *data, int print);

// operation_utils.c
void				swap_stack(t_stack **stack);
void				push_stack(t_stack **src, t_stack **dest);
void				rotate_stack(t_stack **stack);
void				reverse_rotate_stack(t_stack **stack);
void				ra(t_data *data, int print);

// operation.c
void				sa(t_data *data, int print);
void				sb(t_data *data, int print);
void				ss(t_data *data, int print);
void				pa(t_data *data, int print);
void				pb(t_data *data, int print);

// parse_args.c
t_data				*init_data(void);
int					process_argument(t_data *data, char *arg);
t_data				*parse_args(int argc, char **argv);

// parsing.c
int					is_valid_number(const char *str);
int					has_duplicates(t_stack *stack);
void				assign_indices(t_stack *stack);

// sort_large.c
int					get_max_bits(int max_num);
void				radix_sort_optimized(t_data *data);

// sort_small.c
void				push_min_to_b(t_data *data);
void				sort_four(t_data *data);
void				sort_five_optimized(t_data *data);

// sorting.c
void				sort_stack(t_data *data);
void				sort_three(t_data *data);
void				sort_five(t_data *data);
void				radix_sort(t_data *data);

// stack_2.c
void				ft_stackclear(t_stack **stack);

// stack.c
t_stack				*ft_stacknew(int value);
void				ft_stackadd_front(t_stack **stack, t_stack *new);
void				ft_stackadd_back(t_stack **stack, t_stack *new);
int					ft_stacksize(t_stack *stack);
t_stack				*ft_stacklast(t_stack *stack);

// utils.c
int					is_sorted(t_stack *stack);
int					get_min_index(t_stack *stack);
int					get_max_index(t_stack *stack);
int					find_position(t_stack *stack, int index);
void				print_stacks(t_data *data);

#endif