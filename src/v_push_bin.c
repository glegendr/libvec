/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_push_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:51:07 by glegendr          #+#    #+#             */
/*   Updated: 2020/02/12 16:06:44 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>
#include <stdbool.h>

void		v_Lsh(t_vec *vec, int nb)
{
	while (nb-- > 0)
		v_push_int(vec, 0);
}

void		v_Rsh(t_vec *vec, int nb)
{
	while (nb-- > 0)
		v_push_first_int(vec, 0);
}

uint64_t	v_get_bin_nb(t_vec *vec)
{
	int i;
	uint64_t ret;
	char *raw;

	if (v_size(vec) > 64)
		return (-1);
	i = 0;
	ret = 0;
	raw = v_raw(vec);
	while (i < v_size(vec))
	{
		ret <<= 1;
		ret |= *(int *)v_get(vec, i);
		++i;
	}
	return (ret);
}

t_vec		u64_to_bin(uint64_t nb)
{
	t_vec ret;

	ret = v_new(sizeof(int));
	if (nb == 0)
	{
		v_push_int(&ret, 0);
		return (ret);
	}
	while (nb >= 2)
	{
		v_push_first_int(&ret, nb % 2);
		nb /= 2;
	}
	if (nb > 0)
		v_push_first_int(&ret, nb);
	return (ret);
}

void		v_add(t_vec *vec, t_vec *add)
{
	int i = 0;
	int ret = 0;

	while (i < v_size(vec) && i < v_size(add))
	{
		int *nb1 = (int *)v_get(vec, v_size(vec) - 1 - i);
		int nb2 = *(int *)v_get(add, v_size(add) - 1 - i);
		if (ret == 1 && *nb1 == 1)
			*nb1 = 0;
		else if (ret == 1 && *nb1 == 0)
		{
			*nb1 = 1;
			ret = 0;
		}
		if (nb2 == 1 && *nb1 == 1)
		{
			*nb1 = 0;
			ret = 1;
		}
		else if (nb2 == 1 && *nb1 == 0)
			*nb1 = 1;
		++i;
	}
	while (i < v_size(add))
	{
		int nb2 = *(int *)v_get(add, v_size(add) - 1 - i);
		if (ret == 1 && nb2 == 1)
			v_push_first_int(vec, 0);
		else if (ret == 1 && nb2 == 0)
		{
			v_push_first_int(vec, 1);
			ret = 0;
		}
		else
			v_push_first_int(vec, nb2);
		++i;
	}
	while (i < v_size(vec) || ret == 1)
	{
		if (i >= v_size(vec))
		{
			v_push_first_int(vec, ret);
			return ;
		}
		int *nb1 = (int *)v_get(vec, v_size(vec) - 1 - i);
		if (ret == 1 && *nb1 == 0)
		{
			*nb1 = 1;
			ret = 0;
		}
		else if (ret == 1 && *nb1 == 1)
			*nb1 = 0;
	}
}

t_vec		v_mult(t_vec *vec, t_vec *mult)
{
	t_vec ret = v_new_null(sizeof(int));
	int i = 0;
	while (i < v_size(mult))
	{
		int nb = *(int *)v_get(mult, v_size(mult) - 1 - i);
		if (nb == 1)
		{
			if (!v_raw(&ret))
			{
				ret = v_copy(vec);
				v_Lsh(&ret, i);
			}
			else
			{
				t_vec tmp = v_copy(vec);
				v_Lsh(&tmp, i);
				v_add(&ret, &tmp);
				v_del(&tmp);
			}
		}
		++i;
	}
	return (ret);
}

t_vec		v_pow(t_vec *vec, int p)
{
	t_vec ret;
	t_vec tmp;

	if (p <= 0)
	{
		t_vec ret = v_new(sizeof(int));
		v_push_int(&ret, 1);
		return (ret);
	}
	ret = v_copy(vec);
	while (p > 1)
	{
		tmp = v_mult(&ret, vec);
		v_del(&ret);
		ret = tmp;
		--p;
	}
	return (ret);
}

bool		v_sup(t_vec *v1, t_vec *v2)
{
	int i = 0;
	int nb1;
	int nb2;

	if (v_size(v1) > v_size(v2))
		return (true);
	else if (v_size(v1) < v_size(v2))
		return (false);
	while (i < v_size(v1))
	{
		nb1 = *(int *)v_get(v1, i);
		nb2 = *(int *)v_get(v2, i);
		if (nb1 > nb2)
			return (true);
		if (nb1 < nb2)
			return (false);
		++i;
	}
	return (false);
}

void		v_sub(t_vec *vec, t_vec *sub)
{
	int i = 0;
	int ret = 0;

	while (i < v_size(vec) && i < v_size(sub))
	{
		int *nb1 = (int *)v_get(vec, v_size(vec) - 1 - i);
		int nb2 = *(int *)v_get(sub, v_size(sub) - 1 - i);
		if (ret == 1 && *nb1 == 1)
		{
			*nb1 = 0;
			ret = 0;
		}
		else if (ret == 1 && *nb1 == 0)
		{
			*nb1 = 1;
			ret = 0;
		}
		if (nb2 == 1 && *nb1 == 1)
			*nb1 = 0;
		else if (nb2 == 1 && *nb1 == 0)
		{
			*nb1 = 1;
			ret = 1;
		}
		++i;
	}
	if (i < v_size(sub))
		return ;
	while (i < v_size(vec) || ret == 1)
	{
		if (i >= v_size(vec))
			return ;
		int *nb1 = (int *)v_get(vec, v_size(vec) - 1 - i);
		if (ret == 1 && *nb1 == 0)
			*nb1 = 1;
		else if (ret == 1 && *nb1 == 1)
		{
			*nb1 = 0;
			ret = 0;
		}
	}

}

void		v_mod(t_vec *vec, t_vec *mod)
{
	int i = 0;
	t_vec tmp;
	t_vec mult;

	while (42)
	{
		mult = u64_to_bin(i);
		tmp = v_mult(mod, &mult);
		if (v_sup(&tmp, vec))
		{
			mult = u64_to_bin(i - 1);
			tmp = v_mult(mod, &mult);
			return (v_sub(vec, &tmp));
		}
		v_del(&tmp);
		v_del(&mult);
		++i;
	}
}
