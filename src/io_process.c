#include "include/hotrace.h"

static int	read_line(char *str)
{
	char		c;
	int			i;
	char		*s;

	s = str;
	i = 0;
	while (read(0, &c, 1) > 0)
	{
		if (c == '\n')
		{
			*s = '\0';
			return (i);
		}
		*s = c;
		s++;
		i++;
	}
	*s = '\0';
	return (i);
}

void	store_data(t_hashmap *map)
{
	char		key[256];
	char		value[256];

	while (1)
	{
		if (read_line(key) == 0)
		{
			return ;
		}
		if (read_line(value) == 0)
		{
			return ;
		}
		insert(key, value, map);
	}
}

void	fetch_data(t_hashmap *map)
{
	char		key[256];
	char		*value;

	while (1)
	{
		if (read_line(key) == 0)
		{
			return ;
		}
		value = lookup(key, map);
		if (!value)
		{
			ft_putstr(key);
			ft_putstr(": Not found.\n");
		}
		else
		{
			ft_putstr(value);
			ft_putstr("\n");
		}
	}
}
