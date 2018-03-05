#include "vector.h"

void		*v_pop(t_vec *vec)
{
	v_del_last(vec);
	return(v_get(vec, v_size(vec)));
}
