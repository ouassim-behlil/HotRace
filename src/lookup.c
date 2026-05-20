#include "include/hotrace.h"

static char	*search_colisions(unsigned int hash, t_entry *head)
{
	t_entry		*curr;

	curr = head;
	while (curr)
	{
		if (curr->hash == hash)
		{
			return (curr->value);
		}
		curr = curr->next;
	}
	return (NULL);
}

char	*lookup(char *key, t_hashmap *map)
{
	int				index;
	unsigned int	hash;

	if (!key || !map || map->size == 0)
	{
		return (NULL);
	}
	hash = fnv1a_32(key);
	index = hash % map->capacity;
	if (!map->buckets[index])
	{
		return (NULL);
	}
	if (map->buckets[index]->hash == hash)
	{
		return (map->buckets[index]->value);
	}
	else
	{
		return (search_colisions(hash, map->buckets[index]));
	}
}
