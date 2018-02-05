/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:59:04 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/05 23:17:43 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec		v_swap(t_vec *vec, size_t first, size_t second)
{
	t_vec	v;
	int		swap;

	v = v_new(vec->private_elem_size);
	if (first > second)
	{
		swap = second;
		second = first;
		first = swap;
	}
	v_append_raw(&v, v_get(vec, 0), first - 1);
	v_push(&v, v_get(vec, second - 1));
	v_append_raw(&v, v_get(vec, first), second - first - 1);
	v_push(&v, v_get(vec, first - 1));
	v_append_raw(&v, v_get(vec, second), v_size(vec) - second);
	v_del(vec);
	return (v);
}
