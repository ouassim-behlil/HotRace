#include "include/hotrace.h"


unsigned int	fnv1a_32(const char *s)
{
	unsigned int	h;

	h = 2166136261u;
	while (*s)
	{
		h ^= (unsigned char)*s;
		h *= 16777619u;
		s ++;
	}
	return (h);
}
