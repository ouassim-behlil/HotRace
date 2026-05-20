#include "include/hotrace.h"

t_hashmap	*create_map(void)
{
	t_hashmap		*map;

	map = malloc(sizeof(t_hashmap));
	if (!map)
	{
		return (NULL);
	}
	memset(map, 0, sizeof(t_hashmap));
	return (map);
}

void	delete_map(t_hashmap *map)
{
	if (map)
	{
		free(map);
	}
}