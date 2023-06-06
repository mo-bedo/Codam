#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (count == 0)
		count = 1;
	if (size == 0)
		size = 1;
	ret = malloc (size * count);
	if (!ret)
		return (0);
	ft_bzero(ret, size * count);
	return (ret);
}
