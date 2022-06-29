#include "so_long_bonus.h"

int	render(t_sl *sl)
{
	draw_map(sl);
	draw_player(sl);
	draw_data(sl);
	return (0);
}
