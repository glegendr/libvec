/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:26:53 by glegendr          #+#    #+#             */
/*   Updated: 2018/02/05 23:17:22 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <stddef.h>
# include <stdlib.h>
# define NB_ELEM_INI 32

typedef struct	s_vec
{
	void			*private_content;
	int				private_elem_nb;
	int				private_elem_size;
	int				private_elem_cap;
}				t_vec;

/*
** Swap 2 params of vec.
**
** Params:
**    vec: the current vector.
**    first: the first elem to Swap.
**    second: the second elem to Swap.
**
** Return value:
**    t_vec: the new vector.
*/
t_vec			v_swap(t_vec *vec, size_t first, size_t second);

/*
** Copy a memory into an other one.
**
** Params:
**    dst: the destination (non malloced).
**    src: the memory to Copy.
**    n: size of the memory src.
*/
void			*ft_memcpy(void *dst, const void *src, size_t n);

/*
** Copy a memory and malloc to the new size.
**
** Params:
**    dst: the memory to Copy.
**    mem_size: the size of memory dst.
**    new_size: the size you want for your new memory (new_size >= mem_size).
*/
void			*ft_realloc(void *dst, int mem_size, int new_size);

/*
** Create a new vector.
**
** Param:
**    elem_size: the size of each element of the vector.
*/
t_vec			v_new(int elem_size);

/*
** Copy a new element at the end of the vector.
**
** Params:
**    vec: the current vector.
**    elem: the element to add at the end of vector.
*/
void			v_push(t_vec *vec, void *elem);

/*
** Copy a new element at the start of the vector.
**
** Params:
**    vec: the current vector.
**    elem: the element to add at the end of vector.
*/
void			v_push_first(t_vec *vec, void *elem);

/*
** Copy raw at the end of the vector.
**
** Params:
**    vec: the current vector.
**    raw: the raw to add at the end of vector.
**    nb: the numbers of elems content in the raw.
*/
void			v_append_raw(t_vec *vec, void *raw, int nb);

/*
** Get the pointer of element pointed by index.
**
** Params:
**    vec: the current vector.
**    index: the index.
*/
void			*v_get(t_vec *vec, int index);

/*
** Return the element number in the vector.
**
** Param:
**    vec: the current vector.
*/
int				v_size(t_vec *vec);

/*
** Free the vector.
**
** Param:
**    vec: the vector to delete.
*/
void			v_del(t_vec *vec);

/*
** Del the last Param.
**
** Param:
**    vec: the vector to delete.
*/
void			v_del_last(t_vec *vec);

/*
** Add the second vector at the end of the first.
**
** Params:
**    vec1: first vector.
**    vec2: second vector.
*/
void			v_join(t_vec *vec1, t_vec *vec2);

/*
** Split a vector into two vector at the inex.
**
** Pararms:
**     vec: the current vector.
**     index: the index where you have to cut.
*/
t_vec			v_split(t_vec *vec, int index);

/*
** Give the raw.
**
** Param:
**    vec: the current vector.
*/
void			*v_raw(t_vec *vec);

/*
** Print a vector by using char.
**
** Params:
**    vec: the current vector.
**    fd: the file descriptor.
*/
void			v_print(t_vec *vec, int fd);
#endif
