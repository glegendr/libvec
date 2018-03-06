#include "vector.h"

void	v_sort_size(t_vec *vec)
{
	int i;
	int y;

	if ((y = v_size(vec)) < 2)
		return ;
	while (y > 0)
	{
		i = 0;
		while (i < v_size(vec) - 1)
		{
			if (v_size((t_vec *)v_get(vec, i)) <
			v_size((t_vec *)v_get(vec, i + 1)))
			{
				v_swap(vec, i, i + 1);
			}
			++i;
		}
		--y;
	}
}
