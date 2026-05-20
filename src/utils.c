#include "include/hotrace.h"

void	*ft_memset(void *ptr, int value, size_t n)
{
	unsigned char	*uptr;

	uptr = (unsigned char *)ptr;
	while (n--)
	{
		*uptr = (unsigned char)value;
		uptr++;
	}
	return (ptr);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char		*start;

	start = dest;
	while (*src)
	{
		*dest = *src;
		dest ++;
		src ++;
	}
	*dest = '\0';
	return (start);
}
