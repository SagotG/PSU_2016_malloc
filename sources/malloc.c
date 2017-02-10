/*
** main.c for  in /root/rendu/PSU_2016_malloc/sources/
**
** Made by Guillaume Sagot
** Login   <guillaume.sagot@epitech.eu>
**
** Started on  Mon Jan 23 19:17:15 2017 Guillaume Sagot
** Last update	Mon Jan 30 10:56:41 2017 Guillaume SAGOT
*/

#include <unistd.h>
#include "malloc.h"

pthread_mutex_t g_malloc_lock;

t_header	*get_free_block(size_t size)
{
  t_header	*curr;

  curr = head;
  while(curr)
    {
      if (curr->is_free && curr->size >= size)
	return curr;
      curr = curr->next;
    }
  return (NULL);
}

void		*malloc(size_t size)
{
  void		*block;
  t_header	*header;

  if (!size)
    return (NULL);
  pthread_mutex_lock(&g_malloc_lock);
  header = get_free_block(size);
  if (header)
    {
      pthread_mutex_unlock(&g_malloc_lock);
      header->is_free = 0;
      return ((void*)(header + 1));
    }
  block = sbrk(sizeof(t_header) + size);
  if (block == (void*) -1)
    return (NULL);
  header = block;
  header->size = size;
  header->is_free = 0;
  header->next = NULL;
  if (!head)
    head = header;
  if (tail)
    tail->next = header;
 	tail = header;
  pthread_mutex_unlock(&g_malloc_lock);
  return ((void*)(header + 1));
}
