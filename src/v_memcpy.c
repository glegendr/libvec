/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 20:54:36 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/01 20:38:31 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void			*v_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;
	size_t z;

	i = 0;
	z = n / 8;
	while (i < z)
	{
		if (((uint64_t *)dst)[i] != ((uint64_t *)src)[i])
			((uint64_t *)dst)[i] = ((uint64_t *)src)[i];
		++i;
	}
	z = 0;
	n %= 8;
	while (z < n)
	{
		if (((uint8_t *)dst)[z + 8 * i] != ((uint8_t *)src)[z + 8 * i])
			((uint8_t *)dst)[z + 8 * i] = ((uint8_t *)src)[z + 8 * i];
		++z;
	}
	return (dst);
}
//
//void	*v_memcpy(void *dst, const void *src, size_t n)
//{
//	size_t i;
//
//	i = 0;
//	while (i < n)
//	{
//		((char*)dst)[i] = ((char *)src)[i];
//		++i;
//	}
//	return (dst);
//}
//