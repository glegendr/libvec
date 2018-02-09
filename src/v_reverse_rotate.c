/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_reverse_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 00:16:14 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/09 02:59:55 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"

void	v_reverse_rotate(t_vec *vec)
{
	void *tmp;
	void *tmp2;

	tmp = malloc(vec->private_elem_size);
	tmp2 = malloc((vec->private_elem_nb - 1) * vec->private_elem_size);
	ft_memcpy(tmp, v_get(vec, v_size(vec) - 1), vec->private_elem_size);
	ft_memcpy(tmp2, v_get(vec, 0), (vec->private_elem_nb - 1) * vec->private_elem_size);
	ft_memcpy(v_get(vec, 1), tmp2, (vec->private_elem_nb - 1) * vec->private_elem_size);
	ft_memcpy(v_get(vec, 0), tmp, vec->private_elem_size);
	free(tmp);
	free(tmp2);
}
