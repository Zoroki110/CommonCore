/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toikirouillard <toikirouillard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:58:43 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/10 22:19:27 by toikirouill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../Libft/include/ft_printf.h"
# include "../Libft/include/get_next_line.h"
# include "../Libft/include/libft.h"

typedef struct s_stack_node
{
	int	nbr;
	int index;
	int	cost_to_push;
	bool	median_sup;
	bool	cheapest;
	struct s_stack_node *target_node;
	struct s_stack_node *next;
	struct s_stack_node *prev;
}	t_stack_node;

void    		sa(t_stack_node **a, bool show);
void    		sb(t_stack_node **b, bool show);
void    		ss(t_stack_node **a, t_stack_node **b, bool show);
void    		pa(t_stack_node **a, t_stack_node **b, bool done);
void    		pb(t_stack_node **b, t_stack_node **a, bool done);
void    		ra(t_stack_node **a, bool show);
void    		rb(t_stack_node **b, bool show);
void    		rr(t_stack_node **a, t_stack_node **b, bool show);
void 			rra(t_stack_node **a, bool show);
void 			rrb(t_stack_node **b, bool show);
void			rrr(t_stack_node **a, t_stack_node **b, bool show);

t_stack_node	*ft_last_node(t_stack_node *stack);
t_stack_node	*min_stack(t_stack_node *stack);
t_stack_node	*max_stack(t_stack_node *stack);
int				stack_size(t_stack_node *stack);
bool			is_stack_sorted(t_stack_node *stack);

char			**split(char *str, char charset);

int 			syntax_error(char *c);
void    		ft_free_stack(t_stack_node **stack);
void    		ft_free(t_stack_node **a);
int				duplicate_error(t_stack_node *a, int n);

void			sort_three(t_stack_node **a);
void			rotate_both(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest_node);
void			reverse_rotate_both(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest_node);	
void			rotate_stack(t_stack_node **stack, t_stack_node *top_node,
						char name_of_stack);					 

void    		current_index(t_stack_node *stack);
void    		set_cheapest(t_stack_node *stack);
void    		define_node_a(t_stack_node *a, t_stack_node *b);
void    		define_node_b(t_stack_node *a, t_stack_node *b);
t_stack_node	*cheapest_is(t_stack_node *stack);

void			define_stack_a(t_stack_node **a, char **av);
void			sort_stack(t_stack_node **a, t_stack_node **b);

#endif