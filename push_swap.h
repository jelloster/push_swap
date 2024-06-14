/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:36:27 by motuomin          #+#    #+#             */
/*   Updated: 2024/06/14 14:47:49 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/inc/libft.h"
# include <stdlib.h>

// --- TYPEDEFS ---

typedef struct	s_stack
{
	int	top;
	int	*arr;
	int	max;
	int	max_i;
	int	min;
	int	min_i;
}				t_stack;

typedef struct	s_pusw
{
	t_stack s_a;
	t_stack	s_b;
	int		n;
}				t_pusw;


// --- FUNCTON PROTOTYPES ---

//		push_swap.c
void	push_swap(t_pusw *pusw);

//		push_swap_utils.c
void	n2top(t_stack *s, void (*r)(t_stack *), void (*rr)(t_stack *), int n);

//		av_handling.c
int		get_nums(int ac, char *av[], t_pusw *pusw);

//		stack_utils.c
int		find_num_i(t_stack s, int num);
int		high_i(t_stack s);
int		n_high_i(t_stack s, int h_i);
int		low_i(t_stack s);


//		counting_functions.c
int		n2top_c(t_stack *s, void (*r)(t_stack *), void (*rr)(t_stack *), int n);

void	max_n_min(t_stack *s);
void	maxs_n_mins(t_pusw *pusw);
void	print_stack(t_stack *s);
void	print_stacks(t_pusw *p);

// --- OPERATIONS ---

//		push_swap_op.c
void	swap(t_stack *s);
void	push(t_stack *s_a, t_stack *s_b);
void	rotate(t_stack *s);
void	reverse_rotate(t_stack *s);

//		op_a.c
void	sa(t_stack *s_a);
void	pa(t_stack *s_b, t_stack *s_a);
void	ra(t_stack *s_a);
void	rra(t_stack *s_a);

//		op_b.c
void	sb(t_stack *s_b);
void	pb(t_stack *s_a, t_stack *s_b);
void	rb(t_stack *s_b);
void	rrb(t_stack *s_b);

//		op_ab.c
void	ss(t_stack *s_a, t_stack *s_b);
void	rr(t_stack *s_a, t_stack *s_b);
void	rrr(t_stack *s_a, t_stack *s_b);

#endif
