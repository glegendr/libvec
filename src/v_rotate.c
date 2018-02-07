/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 00:04:44 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/07 01:08:49 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"

void		v_rotate(t_vec *vec)
{
	t_vec v;

	v = v_new(vec->private_elem_size);
	v_push(&v, v_get(vec, v_size(vec) - 1));
	v_append_raw(&v, v_get(vec, 0), v_size(vec) - 1);
	v_del(vec);
	*vec = v;
}
