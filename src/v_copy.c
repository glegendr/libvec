/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_copy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 03:20:25 by glegendr          #+#    #+#             */
/*   Updated: 2018/05/29 23:26:43 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec		v_copy(t_vec *vec)
{
	t_vec cpy;

	cpy.private_content = malloc(sizeof(vec->private_elem_size)
			* vec->private_elem_cap);
	cpy.private_elem_nb = vec->private_elem_nb;
	cpy.private_elem_size = vec->private_elem_size;
	cpy.private_elem_cap = vec->private_elem_cap;
	v_memcpy(cpy.private_content, vec->private_content,
			vec->private_elem_nb * vec->private_elem_size);
	return (cpy);
}
