#include "ft_printf.h"

static	unsigned int	uint_length(unsigned int n);

int	ft_uitoa(unsigned int n)
{
	int				int_len;
	char			*ret;
	unsigned long	n_long;
	int				ret_val;

	int_len = uint_length(n);
	n_long = n;
	ret = (char *) malloc(sizeof (char) * int_len + 1);
	if (!ret)
		return (0);
	if (n == 0)
		ret[0] = '0';
	ret[int_len] = '\0';
	while (n_long > 0)
	{
		int_len--;
		ret[int_len] = n_long % 10 + 48;
		n_long /= 10;
	}
	ret_val = write_str(ret);
	free(ret);
	return (ret_val);
}

static	unsigned int	uint_length(unsigned int n)
{
	int				len;
	unsigned long	n_long;

	n_long = n;
	len = 0;
	if (n == 0)
		len++;
	while (n_long > 0)
	{
		n_long /= 10;
		len++;
	}
	return (len);
}
