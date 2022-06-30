SRC = src/main.c src/init.c \
	 src/map_validation.c src/map_constraction.c \
	 src/utils.c src/free.c \
	 src/event.c src/draw.c \
	 src/render.c src/utils2.c \
	 
BSRC = src_bonus/bmain.c src_bonus/binit.c \
	 src_bonus/bmap_validation.c src_bonus/bmap_constraction.c \
	 src_bonus/butils.c src_bonus/bfree.c \
	 src_bonus/bevent.c src_bonus/bdraw.c \
	 src_bonus/brender.c src_bonus/butils2.c \
	 src_bonus/bsprite.c src_bonus/benemy.c

INC = inc
NAME = so_long
BNAME = so_long_bonus
CFLAGS = -Wall -Werror -Wextra
FRAMEWORKS = -framework OpenGL -framework AppKit
MLX = mlx/libmlx.a

all: $(NAME)

$(NAME): $(SRC)
	@make -C mlx
	@gcc -o $@ $^ $(CFLAGS) $(FRAMEWORKS) $(MLX) -I $(INC)

bonus: $(BNAME)

$(BNAME): $(BSRC)
	@make -C mlx
	@gcc -o $@ $^ $(CFLAGS) $(FRAMEWORKS) $(MLX) -I $(INC)

clean:
	@rm -rf $(NAME)
	@rm -rf $(BNAME)

fclean: clean
	@make -C mlx clean

re: fclean all

.PHONY: clean fclean re all