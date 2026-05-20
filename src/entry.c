#include "include/hotrace.h"


t_entry	*create_entry(const char *key, const char *value, unsigned int hash)
{
	t_entry			*entry;

	entry = malloc(sizeof(t_entry));
	if (!entry)
	{
		return (NULL);
	}
	ft_memset(entry, 0, sizeof(t_entry));
	ft_strcpy(entry->key, key);
	ft_strcpy(entry->value, value);
	entry->hash = hash;
	return (entry);
}

void	delete_entry(t_entry *entry)
{
	if (entry)
	{
		free(entry);
	}
}