#include "include/hotrace.h"
#include <stdio.h>

int	main(void)
{
	t_hashmap		*map;

	map = create_map();
	store_data(map);
	fetch_data(map);
	delete_map(map);
	return (0);
}