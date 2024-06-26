#include "push_swap.h"

void free_n_exit(t_pusw pusw)
{
	if (pusw.s_a.arr)
		free (pusw.s_a.arr);
	if (pusw.s_b.arr)
		free (pusw.s_b.arr);
	exit (1);
}
