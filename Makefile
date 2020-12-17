#@clang $(SRC) -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -lbsd -lm -o $(name)
SRC  =	engine/*.c utils/*.c
name =	Cub3D
ARG	 =	map.cub
FLGS =	-Wall -Wextra -Werror
DBUG =	-g3 -fsanitize=undefined
OPT  =	-Ofast

all: $(name)

$(name):
	@echo "Compiling..."
	@clang $(SRC) -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -lbsd -lm -o $(name) $(DBUG)
	@#gcc -I minilibx -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(name) $(OPT)
clean:
	@echo "Cleaning..."
	@rm -rf $(name)

fclean: clean

re: clean all