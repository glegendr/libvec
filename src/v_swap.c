/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:59:04 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/15 00:15:40 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		v_swap(t_vec *vec, size_t first, size_t second)
{
	int		swap;
	void	*tmp;

	tmp = malloc(vec->private_elem_size);
	if (first == second)
		return ;
	if (first > second)
	{
		swap = second;
		second = first;
		first = swap;
	}
	ft_memcpy(tmp, v_get(vec, first), vec->private_elem_size);
	ft_memcpy(v_get(vec, first), v_get(vec, second), vec->private_elem_size);
	ft_memcpy(v_get(vec, second), tmp, vec->private_elem_size);
	free(tmp);
}
