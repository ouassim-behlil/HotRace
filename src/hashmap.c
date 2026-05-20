#include "include/hotrace.h"

t_hashmap	*create_map(void)
{
	t_hashmap		*map;

	map = malloc(sizeof(t_hashmap));
	if (!map)
	{
		return (NULL);
	}
	ft_memset(map, 0, sizeof(t_hashmap));
	map->capacity = 1000003;
	return (map);
}

void	delete_map(t_hashmap *map)
{
	int		i;
	if (!map)
	{
		return;
	}
	i = 0;
	while (i < map->capacity)
	{
		delete_entry(map->buckets[i]);
		i ++;
	}
	free(map);
}