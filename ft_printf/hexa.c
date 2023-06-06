#include "ft_printf.h"

static int	hex_length(unsigned long long nb);
static char	convert_remainder(int conv, int up);

int	hexa(long long nb, int up)
{
	char	*print;
	int		hex_l;
	int		ret;

	hex_l = hex_length(nb);
	print = malloc (hex_l + 1);
	if (!print)
		return (0);
	print[hex_l] = 0;
	while (hex_l)
	{
		hex_l--;
		print[hex_l] = convert_remainder(nb % 16, up);
		nb /= 16;
	}
	ret = write_str(print);
	free(print);
	return (ret);
}

int	hexa_p(unsigned long long nb)
{
	char	*print;
	int		hex_l;
	int		ret;

	hex_l = hex_length(nb);
	print = malloc (hex_l + 3);
	if (!print)
		return (0);
	print[hex_l + 2] = 0;
	print[0] = '0';
	print[1] = 'x';
	while (hex_l)
	{
		hex_l--;
		print[hex_l + 2] = convert_remainder(nb % 16, 0);
		nb /= 16;
	}
	ret = write_str(print);
	free(print);
	return (ret);
}

static char	convert_remainder(int conv, int up)
{
	char	ret;

	if (conv < 10)
		return (conv + '0');
	if (up)
		ret = (conv % 10) + 'A';
	else
		ret = (conv % 10) + 'a';
	return (ret);
}

int	hex_length(unsigned long long nb)
{
	int	length;

	length = 0;
	if (nb == 0)
		return (1);
	else
	{
		while (nb)
		{
			nb /= 16;
			length++;
		}
	}
	return (length);
}
