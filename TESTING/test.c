#include <limits.h>
#include <unistd.h>

int	ft_putchar(int c)
{
	ssize_t	check;
	
	check = write(1, &c, 1);
	if (check == -1)
		return (-1);
	else
		return (1);
}

int	ft_putnbr(int num)
{
	static int	length;

	length = 0;
	if (num == INT_MIN)
	{
		length += ft_putchar("-");
		length += ft_putchar("2");
		num = 147483648;
	}
	if (num < 0)
	{
		length += ft_putchar("-");
		num *= -1;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		length += ft_putchar(num + '0');
	return (length);
}

int	ft_puthex(unsigned int num)
{
	char		*hexdigits;
	static int	length;
	char		digit;

	hexdigits = "0123456789abcdef";
	length = 0;
	if (num >= 16)
		ft_puthex(num / 16);
	digit = hexdigits[num % 16];
	length += ft_putchar(digit);
	return (length);
}
