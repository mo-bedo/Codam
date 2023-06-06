#include "ft_printf.h"

static	int	int_length(int n);
static void	ft_bzero(void *s, size_t n);
static void	*ft_calloc(size_t count, size_t size);

int	ft_itoa(int n)
{
	int		len_ret;
	char	*ret;
	long	n_long;

	len_ret = int_length(n);
	n_long = n;
	ret = (char *) ft_calloc(1, sizeof (char) * len_ret + 1);
	if (!ret)
		return (0);
	if (n == 0)
		ret[0] = '0';
	if (n_long < 0)
	{
		ret[0] = '-';
		n_long *= -1;
	}
	while (n_long > 0)
	{
		len_ret--;
		ret[len_ret] = n_long % 10 + 48;
		n_long /= 10;
	}
	len_ret = write_str(ret);
	free(ret);
	return (len_ret);
}

static	int	int_length(int n)
{
	int		len;
	long	n_long;

	n_long = n;
	len = 0;
	if (n < 0)
	{
		len++;
		n_long *= -1;
	}
	if (n == 0)
		len++;
	while (n_long > 0)
	{
		n_long /= 10;
		len++;
	}
	return (len);
}

static void	*ft_calloc(size_t count, size_t size)
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

static void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = s;
	while (n)
	{
		temp[n - 1] = '\0';
		n--;
	}
	return ;
}
