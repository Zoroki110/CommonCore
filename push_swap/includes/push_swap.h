/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:58:43 by trouilla          #+#    #+#             */
/*   Updated: 2024/12/09 11:20:55 by trouilla         ###   ########.fr       */
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
	bool	sup_median;
	bool	cheapest;
	struct s_stack_node *target_node;
	struct s_stack_node *next;
	struct s_stack_node *prev;
}	t_stack_node;

void    sa(t_stack_node **a, bool show);
void    sb(t_stack_node **b, bool show);
void    ss(t_stack_node **a, t_stack_node **b, bool show);
void    pa(t_stack_node **a, t_stack_node **b, bool done);
void    pb(t_stack_node **b, t_stack_node **a, bool done);
void    ra(t_stack_node **a, bool show);
void    rb(t_stack_node **b, bool show);
void    rr(t_stack_node **a, t_stack_node **b, bool show);
void 	rra(t_stack_node **a, bool show);
void 	rrb(t_stack_node **b, bool show);
void	rrr(t_stack_node **a, t_stack_node **b, bool show);

t_stack_node	*ft_last_node(t_stack_node *stack);
t_stack_node	*min_stack(t_stack_node *stack);
t_stack_node	*max_stack(t_stack_node *stack);
int				stack_size(t_stack_node *stack);
bool			is_stack_sorted(t_stack_node *stack);

#endif