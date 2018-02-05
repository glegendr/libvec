/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_reverse_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 00:16:14 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/06 00:20:41 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"

void	v_reverse_rotate(t_vec *vec)
{
	t_vec v;

	v = v_new(vec->private_elem_size);
	v_append_raw(&v, v_get(vec, 1), v_size(vec) - 1);
	v_push(&v, v_get(vec, 0));
	v_del(vec);
	*vec = v;
}
