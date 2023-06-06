#include "libft.h"

//	Writes len bytes of value c (in unsigned char) to b.
void	*ft_memset(void *b, int c, size_t len)
{
	while (len)
	{
		((unsigned char *)b)[len - 1] = (unsigned char) c;
		len--;
	}
	return (b);
}
