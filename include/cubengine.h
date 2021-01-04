/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubengine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:53:13 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/04 17:54:55 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBENGINE_H
# define CUBENGINE_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define TL_SIZE			100
# define CUBTITLE			"Cub3D"
# define ERR				-1
# define SUCCESS			0
# define MAX_READ_CONFIG	9
# define MAX_WIDTH			2256
# define MAX_HEIGHT			1300

# define EV_KEY_PRESSED		2
# define EV_KEY_RELEASED	3
# define EV_KEY_EXIT		17

# define NORTH				0
# define SOUTH				1
# define WEST				2
# define EAST				3
# define SPR				4
# define CIEL  				0
# define FLOOR 				1
# define X 					0
# define Y 					1

typedef char		*t_str;
typedef enum		e_bool
{
	true = 1,
	false = 0
}					t_bool;
typedef struct		s_sprite
{
	float			x;
	float			y;
	float			offx;
	float			offy;
	int				p[2];
	float			off[2];
	float			dist;
	float			ang;
	float			scale;
}					t_sprite;
typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;
typedef struct		s_camera
{
	float			x;
	float			y;
	int				p[2];
	float			ang;
	float			side_ang;
	float			mov_spd;
	float			rot_spd;
	int				mov_dir;
	int				rot_dir;
}					t_camera;
typedef struct		s_rdata
{
	float			hit[2];
	float			inter[2];
	float			step[2];
	float			dist;
}					t_rdata;
typedef struct		s_wdata
{
	float			top;
	float			bttm;
	float			height;
}					t_wdata;
typedef struct		s_ray
{
	float			dist;
	float			ang;
	float			hit[2];
	t_bool			dir[4];
	t_bool			hitver;
}					t_ray;
typedef struct		s_img
{
	t_str			path;
	void			*img;
	int				*data;
	float			hratio;
	float			vratio;
	int				width;
	int				height;
	int				bpp;
	int				sl;
	int				end;
}					t_img;
typedef struct		s_map
{
	t_str			row;
	int				columns;
}					t_map;
typedef struct		s_read_check
{
	t_bool			resolution;
	t_bool			txt_north;
	t_bool			txt_south;
	t_bool			txt_west;
	t_bool			txt_east;
	t_bool			txt_sprite;
	t_bool			clr_ceiling;
	t_bool			clr_floor;
	t_bool			is_map;
}					t_read_check;
typedef struct		s_cub
{
	void			*window;
	void			*mlx;
	float			fov;
	int				rows_nb;
	int				sprs_nb;
	t_str			line;
	t_str			*parts;
	t_map			*map;
	t_sprite		*spr;
	t_ray			*ray;
	t_camera		cam;
	t_img			cnvs;
	t_img			txt[6];
	t_color			color[2];
	t_bool			screenshot;
	t_read_check	checker;
}					t_cub;

int					get_color_from_txt(t_cub *cub, t_wdata *stripe, int pos[2],
					int img);
int					color_rgb_to_hex(t_color clr);
t_color				color_hex_to_rgb(unsigned int color);
t_color				color_hex_to_rgb(unsigned int color);
float				ft_distance(t_cub *cub, float x, float y);
float				normalize_rad(float angle);
char				value_at(t_cub *cub, int x, int y);
void				draw(t_img *canvas, int x, int y, int color);
t_bool				is_err(int val);
t_bool				is_succ(int val);
t_bool				is_wall(t_cub *cub, float x, float y);
t_bool				is_sprite(t_cub *cub, float x, float y);
t_bool				is_read_complete(t_cub *cub);
t_str				ft_lowercase(t_str str);
t_str				extract_value(t_str line);
int					ft_countchar(const t_str str, char c);
float				ft_rad(float a);
float				ft_deg(float a);
void				ft_perror(t_str msg, int return_code);
int					ft_clean(t_cub *cub, int return_code);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
size_t				ft_strlen_2d(t_str *str);
void				ft_free_2d(t_str **str);
void				ft_free(char **s);
void				ft_putnbr(int n);
t_bool				ft_strnchar(const char *str, char c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				**ft_split(const char *ss, char c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strsub(char **s, unsigned int start, size_t n);

int					get_next_line(int fd, char **line);
float				normalize_spr(t_cub *cub, float angle);
void				sort_sprites(t_cub *cub);
void				read_file(t_cub *cub, t_str fname);

void				check_filename(t_cub *cub, t_str fname, t_str ext,
					t_bool case_s);
void				check_arguments(t_cub *cub, int ac, t_str *av);
void				check_map(t_cub *cub);
void				check_camera(t_cub *cub);
void				check_all(t_cub *cub);

void				init_cub(t_cub *cub);
void				init_game(t_cub *cub, int ac, t_str *av);
void				init_ray(t_ray *ray);
void				init_rays(t_cub *cub);
void				init_sprites(t_cub *cub);
void				init_images(t_cub *cub);
void				init_read_check(t_cub *cub);

int					event_key_pressed(int key, t_cub *cub);
int					event_key_released(int key, t_cub *cub);
int					event_game_loop(t_cub *cub);
int					event_exit(t_cub *cub);

void				update_camera(t_cub *cub);
void				update_ray(t_cub *cub, t_ray *ray);
void				update_rays(t_cub *cub);
void				update_rendering_walls(t_cub *cub);
void				update_rendering_sprites(t_cub *cub);

void				render_sprite(t_cub *cub, int id, int off[2]);
void				render_wall_stripe(t_cub *cub, t_wdata *stripe, int x);
void				render_ciel_stripe(t_cub *cub, int ystart, int yend, int x);
void				render_flor_stripe(t_cub *cub, int ystart, int yend, int x);

void				read_file(t_cub *cub, t_str filename);
void				read_ceiling_color(t_cub *cub);
void				read_floor_color(t_cub *cub);
void				read_map(t_cub *cub);
void				read_resolution(t_cub *cub);
void				read_north_texture(t_cub *cub);
void				read_south_texture(t_cub *cub);
void				read_west_texture(t_cub *cub);
void				read_east_texture(t_cub *cub);
void				read_sprite(t_cub *cub);

void				save(t_cub *cub);

#endif
