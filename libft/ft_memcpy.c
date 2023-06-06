#include "libft.h"

//	Copies n bytes from src to dst. If they overlap behavior is undefined .
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstbuff;
	char const	*srcbuff;

	dstbuff = dst;
	srcbuff = src;
	if ((dst == NULL) && (src == NULL))
		return (0);
	while (n)
	{
		*dstbuff = *srcbuff;
		dstbuff++;
		srcbuff++;
		n--;
	}
	return (dst);
}
