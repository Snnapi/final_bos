#include "so_long_bonus.h"

int	render(t_sl *sl)
{
	draw_map(sl);
	draw_player(sl);
	draw_enemy(sl);
	draw_data(sl);
	if ((sl->px == sl->ex) && (sl->py == sl->ey))
		free_so_long(sl);
	return (0);
}
