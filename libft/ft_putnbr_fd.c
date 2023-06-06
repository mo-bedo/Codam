#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		out;
	long	numb;

	numb = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		numb *= -1;
	}
	out = numb % 10 + 48;
	numb /= 10;
	if (numb > 0)
		ft_putnbr_fd(numb, fd);
	write(fd, &out, 1);
}
