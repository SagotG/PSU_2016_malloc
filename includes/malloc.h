/*
** malloc.h for  in /root/rendu/PSU_2016_malloc/includes/
**
** Made by Guillaume Sagot
** Login   <guillaume.sagot@epitech.eu>
**
** Started on  Mon Jan 23 19:19:12 2017 Guillaume Sagot
** Last update	Mon Jan 30 11:02:54 2017 Guillaume SAGOT
*/

#ifndef __MALLOC_H__
# define __MALLOC_H__

#ifndef _BSD_SOURCE
# define _BSD_SOURCE
#endif

#ifndef _DEFAULT_SOURCE
# define _DEFAULT_SOURCE
#endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>

typedef struct 	__attribute__((__packed__))	s_header
{
  size_t					size;
  unsigned					is_free;
  struct s_header				*next;
  struct s_header				*head;
  struct s_header				*tail;
}						t_header;

t_header					*head;
t_header					*tail;

t_header					*get_free_block(size_t size);
void						*malloc(size_t size);

#endif	/* _MALLOC_H_ */
