#include "include/hotrace.h"


static void	insert_at_end(t_entry *entry, t_entry *head)
{
	t_entry		curr;

	curr = head;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = entry;
}

int	insert(const char *key, const char *value, t_hashmap *map)
{
	int				index;
	unsigned int	hash;
	t_entry			*entry;

	hash = fnv1a_32(key);
	entry = create_entry(key, value, hash);
	if (!entry)
	{
		return (0);
	}
	index = hash % map->size;
	if (!map[index])
	{
		map[index] = entry;
	}
	else
	{
		insert_at_end(entry, map[index]);
	}
	return (1);
}