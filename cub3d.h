/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-harc <mel-harc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:23:34 by efarhat           #+#    #+#             */
/*   Updated: 2023/09/13 22:54:05 by mel-harc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <string.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_element
{
	char	*id;
	char	*info;
	int		color[3];
}			t_element;

typedef struct s_pmap
{
	char		*file;
	int			fd;
	t_element	*elem;
	char		**map;
	char		pos;
	int			x;
	int			y;
}			t_pmap;

//	LIBFT
// char		*ft_strrchr(const char *s, int c);
// int			ft_strncmp(const char *s1, const char *s2, size_t n);
// char		**ft_split(char const *s, char c);
// char		*ft_substr(char const *s, unsigned int start, size_t len);
// int			ft_isalpha(int c);
// char		*ft_strdup(const char *s1);
// size_t		ft_strlen(const char *s);
// void		*ft_memcpy(void *dst, const void *src, size_t n);
// void		*ft_memset(void *b, int c, size_t len);
// int			ft_isdigit(int c);
// int			is_empty(int c);
// int			ft_atoi(const char *str);
// int			ft_strcmp(const char *s1, const char *s2);
// // char		*ft_strchr(const char *s, int c);
// char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

typedef struct s_map
{
	size_t		weight;
	size_t		height;
	mlx_t		*ptr_mlx;
	mlx_image_t	*img;
	int			window;
	t_pmap		*tmap;
	float		px;
	float		py;
	float		xv;
	float		yv;
	double		ongl;
	int			lr_walk;
	int			ud_walk;
	int			lr_view;
	double		rotation_angle;
	double		move_speed;
	double		rotation_speed;	
	double		fov;
	float		distance;
	unsigned int	color;
}	t_map;

typedef struct s_point
{
	int		x2;
	int		y2;
	int		dx;
	int		dy;
	float	xinc;
	float	yinc;
	int		steps;
	float	X;
	float	Y;
}	t_point;

typedef struct s_ray
{
	float		cxh;
	float		cyh;
	float		cyv;
	float		cxv;
	double	ray_angle;
} t_ray;

// main
void	get_space(t_map *map);
void	draw_map(t_map *map);
void	drawing_img(t_map *map);
void	put_image(char c, t_map *map);
void	put_pixel_in_img(t_map *map, int x, int y, char c);
void	pixels_player(t_map *map, float x, float y);
void	pixels_wall(t_map *map, int x, int y);
void	handler_moves(void *param);
void	player_pos(t_map *map);
void	init_value(t_map *s);
void	walk_move(t_map *map);
void	move_left_right(t_map *map);
void	put_rays(t_map *s, float angle, double distance);
double	_abs(double c);
void	check_wall(t_map *map, float x, float y);
void	hook(t_map *map);
void	cast_rays(t_map *s);
double	first_cray(t_map *s, t_ray *r);
void	cast_rays(t_map *s);
void	raycating_horizontal(t_map *s, t_ray *r);
void	raycating_vertical(t_map *s, t_ray *r);
int		is_wall(t_map *s ,float x, float y);
void    normalize_angle(t_ray *r);
void	init_angle(t_map *s);
void	handler_move_view(t_map *s);
void	direction_player(t_map *s, float distance);

//	UTILS MAP
char	*ft_read_file(int fd);
char	*remove_empty(char *s);
void	init_tmap(t_pmap *tmap);
void	check_empty_lines(char *s);
int		num_lines(char **arr);
char	*get_iden(char *s);
char	*get_info(char *s);

int		ft_error(char *str, int ex, int ret);
void	clean_arr2d(char **arr2d);

int		check_map(t_pmap *tmap);
int		closed_map(t_pmap tmap);

#endif