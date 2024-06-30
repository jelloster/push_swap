#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// --- INCLUDES ---

# include "libft/inc/libft.h"
# include <stdlib.h>

// --- TYPEDEFS ---

typedef enum	s_code
{
	A,
	B
}		t_code;

typedef struct	s_stack
{
	int	top;
	int	*arr;
	int	max;
	int	max_i; // used?
	int	min;
	int	min_i; // used?
	t_code	code;
}		t_stack;

typedef struct	s_pusw
{
	t_stack s_a;
	t_stack	s_b;
	int		n;
}		t_pusw;

// --- FUNCTION PROTOTYPES ---

//	push_swap.c
void	push_swap(t_stack *s_a, t_stack *s_b);

//	push_swap_op.c
void	swap(t_stack *s);
void	push(t_stack *s_1, t_stack *s_2);
void	rotate(t_stack *s, int print);
void	reverse_rotate(t_stack *s, int print);

void	rr(t_stack *s_a, t_stack *s_b);
void	rrr(t_stack *s_a, t_stack *s_b);

//	rotation_counters.c
int	d_rot_c(t_stack s_f, t_stack s_t, int n, int (*f)(t_stack, int, int));
int	rf_rrt_c(t_stack s_f, t_stack s_t, int n);
int	rrf_rt_c(t_stack s_f, t_stack s_t, int n);
int	r_move(t_stack s, int start_i, int end_i);
int	rr_move(t_stack s, int start_i, int end_i);

//	rotation_execution.c
void	d_rot(t_stack *s_f, t_stack *s_t, int n);
void	d_rev_rot(t_stack *s_f, t_stack *s_t, int n);
void	rf_rrt(t_stack *s_f, t_stack *s_t, int n);
void	rrf_rt(t_stack *s_f, t_stack *s_t, int n);

//	index_functions.c
int	indx(t_stack s, int n);
int	nh_indx(t_stack s, int n);
int	nl_indx(t_stack s, int n);

//	av_handling.c
int	get_nums(int ac, char *av[], t_pusw *pusw);

//	stack_utils.c;
void	max_n_min(t_stack *s);
void	n2top(t_stack *s, int n);

void	print_stacks(t_pusw *p);
void	print_stack(t_stack *s);

#endif
