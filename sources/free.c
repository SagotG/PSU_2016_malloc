/*
** free.c for  in /root/rendu/PSU_2016_malloc/sources/
**
** Made by Guillaume Sagot
** Login   <guillaume.sagot@epitech.eu>
**
** Started on  Thu Feb  2 10:42:05 2017 Guillaume Sagot
** Last update Mar Feb 7 09:37:51 2017 Guillaume Sagot
*/

#include "malloc.h"

void		get_block_to_free(t_header *tmp, t_header *head)
{
  tmp = head;
  while (tmp)
    {
      if(tmp->next == tail)
	{
	  tmp->next = NULL;
	  tail = tmp;
	}
      tmp = tmp->next;
    }
}

void		free(void *block)
{
  t_header 	*header;
  t_header 	*tmp;
  void		*_break;

  if (!block)
    return;
  tmp = NULL;
  header = (t_header*)block - 1;
  _break = sbrk(0);
  if ((char*)block + header->size == _break)
    {
      if (head == tail)
	{
	  head = tail;
	  tail = NULL;
	}
      else
	get_block_to_free(tmp, head);
      sbrk(0 - sizeof(t_header) - header->size);
      return;
    }
  header->is_free = 1;
}
