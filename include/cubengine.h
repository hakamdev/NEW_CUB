/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubengine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:53:13 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/28 17:53:15 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUBENGINE_H
# define CUBENGINE_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

// Test
# include <stdio.h>
# include <string.h>
//

# define POW(a)			 ((a) * (a))
# define RAD(a)			 ((float)((a) * M_PI / 180))
# define DEG(a)			 ((float)((a) * 180) / M_PI)
# define IS_ERROR(f)	 ((f) == ERROR)
# define IS_SUCESS(f)	 ((f) == SUCCESS)
# define TILE_SIZE		 64
# define FOV			 RAD(60.0F)
# define CUBTITLE		 "Cub3D"
# define ERROR			 -1
# define SUCCESS		 0
# define MAX_READ_CONFIG 9
# define WIN_WIDTH		 cub->cnvs.width
# define WIN_HEIGHT		 cub->cnvs.height
# define MAX_WIDTH		 2256
# define MAX_HEIGHT		 1300

# define NORTH	0
# define SOUTH	1
# define WEST	2
# define EAST	3
# define SPR	4
# define CIEL  	0
# define FLOOR 	1
# define X 		0
# define Y 		1

# define EV_KEY_PRESSED		2
# define EV_KEY_RELEASED	3

//
# define BITSPERPIXEL 24
# define PLANES 1
# define COMPRESSION 0
# define PIXELBYTESIZE (WIN_WIDTH * WIN_HEIGHT * BITSPERPIXEL / 8)
# define FILESIZE (PIXELBYTESIZE + sizeof(bmp))
# define XPIXELPERMETER 0X130B
# define YPIXELPERMETER 0X130B
# define PIXEL 0XFF
//

typedef char	*t_str;
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef enum	s_bool
{
	true = 1,
	false = 0
}				t_bool;
typedef struct	s_header
{
	char 	type[2];
	uint32_t filesize;
	uint32_t reserved;
	uint32_t offset;
} t_header;
typedef struct	s_bmpinfo
{
	uint32_t headersize;
	uint32_t width;
	uint32_t height;
	uint16_t  planes;
	uint16_t  bpp;
	uint32_t compression;
	uint32_t imgsize;
	uint32_t xpixelpmeter;
	uint32_t ypixelpmeter;
	uint32_t numclrpalette;
	uint32_t mostimpclr;
} t_bmpinfo;
typedef struct	s_bmp
{
	t_header	header;
	t_bmpinfo	info;
}				t_bmp;
typedef struct	s_sprite
{
	float	x;
	float	y;
	float	offx;
	float	offy;
	int		p[2];
	float	off[2];
	float	dist;
	float	ang;
	float	scale;
}				t_sprite;
typedef struct	s_color
{
	int r;
	int g;
	int b;
} t_color;
typedef struct	s_camera
{
	float		x;
	float		y;
	int			p[2];
	float		ang;
	float		side_ang;
	float		mov_spd;
	float		rot_spd;
	int			mov_dir;
	int			rot_dir;
}				t_camera;
typedef struct	s_rdata
{
	float		hit[2];
	float		inter[2];
	float		step[2];
	float		dist;
}				t_rdata;
typedef struct	s_wdata
{
	float		top;
	float		bttm;
	float		height;
}				t_wdata;
typedef struct	s_ray
{
	float		dist;
	float		ang;
	float		hit[2];
	t_bool		dir[4];
	t_bool		hitver;
}				t_ray;
typedef struct	s_img
{
	t_str path;
	void *img;
	int	*data;
	float hratio;
	float vratio;
	int	width;
	int	height;
	int bpp;
	int sl;
	int end;
}				t_img;
typedef struct	s_map
{
	t_str	row;
	int		columns;
}				t_map;
typedef struct	s_read_check
{
	t_bool	resolution;
	t_bool	txt_north;
	t_bool	txt_south;
	t_bool	txt_west;
	t_bool	txt_east;
	t_bool	txt_sprite;
	t_bool	clr_ceiling;
	t_bool	clr_floor;
	t_bool	is_map;
}				t_read_check;
typedef struct	s_cub
{
	void			*window;
	void			*mlx;
	int				rows_nb;
	int				sprs_nb;
	int				read_nb;
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
	// int			cp_nb;
	// int			level_nb;
	//  int			currlvl;
	// int			currcp;
	//  char		lastcpn;
	// t_str		fname;
	// t_str		errno;
}				t_cub;

t_bool			g_end_splsh;
int				g_indx_splsh;

int		get_color_from_txt(t_cub *cub, t_wdata *stripe, int pos[2], int img);
int		color_rgb_to_hex(t_color clr);
t_color	color_hex_to_rgb(unsigned int color);
float	get_distance(t_cub *cub, float x, float y);
float	normalize_rad(float angle);
char	value_at(t_cub *cub, int x, int y);
void	draw(t_img *canvas, int x, int y, int color);
int		exit_error(t_cub *cub, t_str error_msg);
int		ft_strlen_2d(t_str *str);
int		free_2d(t_str *str);
t_bool	is_wall(t_cub *cub, float x, float y);
t_bool	is_sprite(t_cub *cub, float x, float y);
t_str	to_lowercase(t_str str);

int		ft_atoi(const char *str);
void	ft_free(char *s);
int		get_next_line(int fd, char **line);
void	ft_putnbr(int n);
char	**ft_split(const char *ss, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
t_bool	ft_strnchar(const char *str, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strsub(char **s, unsigned int start, size_t n);
int		ft_perror(t_str msg, int return_code);
int		ft_clean(t_cub *cub, int return_code);


char		value_at_pos(t_cub *cub, int x, int y);
void		check_filename(t_cub *cub, t_str fname, t_str ext, t_bool case_s);
void		check_arguments(t_cub *cub, int ac, t_str *av);
void		read_file(t_cub *cub, t_str fname);
void		check_map(t_cub *cub);
void		init_cub(t_cub *cub);
void		check_camera(t_cub *cub);
void		check_all(t_cub *cub);
void		init_game(t_cub *cub, int ac, t_str *av);

void		init_ray(t_ray *ray);
void		init_rays(t_cub *cub);
void		init_sprites(t_cub *cub);
void		update_ray(t_cub *cub, t_ray *ray);

float		normalize_spr(t_cub *cub, float angle);
void		sort_sprites(t_cub *cub);

#endif