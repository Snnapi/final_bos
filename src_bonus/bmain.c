#include "so_long_bonus.h"

int	filename_check(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'r' && str[i - 1] == 'e'
		&& str[i - 2] == 'b' && str[i - 3] == '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_sl	*sl;

	if (argc == 2 && filename_check(argv[1]))
	{
		sl = sl_init(argv[1]);
		mlx_loop(sl->mlx);
	}
	else
		write(1, "USAGE_ERROR\n", 12);
	return (0);
}
