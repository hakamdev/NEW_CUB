#@clang $(SRC) -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -lbsd -lm -o $(name)
SRC  =	engine/*.c utils/*.c
OBJ  =  *.o
name =	Cub3D
ARG	 =	map.cub
FLGS =	-Wall -Wextra -Werror
DBUG =	-g3 -fsanitize=undefined
OPT  =	-O3

all: $(name)

$(name): $(OBJ)
	@echo "Compiling..."
	@gcc $(OBJ) -o $(name) -lmlx -framework OpenGL -framework AppKit
	@#clang $(SRC) -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -lbsd -lm -o $(name) $(DBUG)
	@#gcc -I minilibx -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(name) $(OPT)

$(OBJ) : $(SRC)
	@gcc -I minilibx $(SRC) -c $(OPT)

clean:
	@echo "Cleaning..."
	@rm -rf $(OBJ)

fclean: clean
	@echo "Full Cleaning..."
	@rm -rf $(name)

re: clean all