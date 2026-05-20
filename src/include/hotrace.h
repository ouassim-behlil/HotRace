#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_entry
{
	char			key[256];
	char			value[256];
	unsigned int	hash;
	struct s_entry	*next;
}	t_entry;

typedef struct	s_hashmap
{
	t_entry			*buckets[1000003];
	int				size;
	int				capacity;
}	t_hashmap;

// entry.c
t_entry			*create_entry(char *key, char *value, unsigned int hash);
void			delete_entry(t_entry *entry);

// hash.c
unsigned int	fnv1a_32(const char *s);

// hashmap.c
t_hashmap		*create_map(void);
void			delete_map(t_hashmap *map);

// insert.c
int				insert(const char *key, const char *value, t_hashmap *map);

#endif