
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_push_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:40:07 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/13 19:41:17 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		v_push_first_int(t_vec *vec, int elem)
{
	v_push_first(vec, &elem);
}
