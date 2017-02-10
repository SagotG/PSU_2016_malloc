/*
** realloc.c for  in /root/rendu/PSU_2016_malloc/sources/
**
** Made by Guillaume Sagot
** Login   <guillaume.sagot@epitech.eu>
**
** Started on  Thu Feb  2 10:42:40 2017 Guillaume Sagot
** Last update Mar Feb 7 09:44:42 2017 Guillaume Sagot
*/

#include "malloc.h"

void				*realloc(void *block, size_t size)
{
	t_header	*header;
	void			*ret;

	header = (t_header*)block - 1;
	ret = malloc(size);
  if (!block || !size)
    return (malloc(size));
  if (header->size >= size)
    return (block);
  if (ret)
    {
      memcpy(ret, block, header->size);
      free(block);
    }
  return (ret);
}
