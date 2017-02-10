/*
** show_alloc_mem.c for  in /root/rendu/PSU_2016_malloc/sources/
**
** Made by Guillaume Sagot
** Login   <guillaume.sagot@epitech.eu>
**
** Started on  Tue Jan 24 21:13:44 2017 Guillaume Sagot
** Last update	Mon Jan 30 11:22:22 2017 Guillaume SAGOT
*/

#include "malloc.h"

void				show_alloc_mem()
{
  t_header	*stack;

  stack = sbrk(sizeof(t_header));
  printf ("Break : %p\n", sbrk(0));
  if (!stack)
    printf("Nothing in memory\n");
  while (stack)
    {
      if (stack->is_free == 1)
	{
	  printf("%p - %p : %zu",(void*)stack, &stack->next, stack->size);
	  stack = stack->next;
	}
    }
}
