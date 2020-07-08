/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartin- <gmartin-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:07:03 by gmartin-          #+#    #+#             */
/*   Updated: 2020/07/08 20:04:06 by gmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "includes/minilibx/mlx.h"
# include "includes/printf/ft_printf.h"
# include <math.h>

/*----------TAMAÑOS TEXTURAS PREDEF---------*/

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

/*----------TECLAS_KEYCODE---------*/
#ifdef __linux__
#  define KEY_ESC 65307
#  define KEY_C 99
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_LEFT 65361
#  define KEY_UP 65362
#  define KEY_RIGHT 65363
#  define KEY_DOWN 65364
# else
#  define KEY_ESC 53
#  define KEY_C 8
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_P 35
#  define KEY_LEFT 123
#  define KEY_UP 126
#  define KEY_RIGHT 124
#  define KEY_DOWN 125

# endif



typedef struct s_vector
{
	double x;
	double y;
} 				t_vector;

typedef struct 		s_moves
{
	t_vector	dir;	// dirección inicial del vector
	t_vector 	plane; 	// plano de camara
	t_vector	rayDir;
	t_vector	sideDist;			// distancia desde el punto inicial al siguiente lado
	t_vector	deltaDist;	 		//  distancia hasta siguiene lado
	double		time;
	double		oldTime;
	double		cameraX;
	int			mapX;				//  posición inicial del jugador
	int			mapY;
	int			side;				// lado	
	int			stepX;
	int			stepY;
	double		perpWallDist;		// distancia desde nuestra posición a la pared.
	int			lineHeight;			// tamaño de la linea que vamos a dibujar.
	int			drawStart;
	int			drawEnd;
	int			color;
	double		moveSpeed;
	double		rotSpeed;
	int			W;
	int			S;
	int			A;
	int			D;
	int			L;
	int			R;
	int			textX;
	int			textY;	
	double		textpos;
	double		wallX;
	double		textstep;
	int			textside;
}					t_moves;

/*typedef struct		s_textures
{
	void	*img;
	int		*data_img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		w;
	int		h;
	int		x;
	int		y;
}					t_textures;*/

typedef struct		s_readfile
{
	void	*mlx;
	void	*win;
	int		fd;					//  FD del Mapa.
	int		w;					//  Ancho de Pantalla.
	int		h;					//  Alto de pantalla.
	int		texture[4];			//  Array de FD de Texturas.
								//   [0] NO ./north_texture [1] SO ./south_texture[2]
								//   WE ./west_texture [3] EA ./east_textur
	int		sprite;				//  FD de Spritex.
	char	*line;				//  Linea leida por el GNL.
	char	*c_f;				//  Colores suelo hex
	int		cf[3];				//  colores del suelo en formato rgb.
	char	*c_c;				//  colores del techo en formato hex.
	int		cc[3];
	int		**map;				//  Matriz de mapa
	char	dir;				//  orientacion del jugador
	int		pos[2];				// 	posicion incial del jugador
	int		mapreaded;			//  -1 si no se ha leido 0 si se termino de leer
	int		nColMax;			//  Numero de columnas MAX
	int		nFil;				//  Numero de filas
	char	*buff;				//  Buff auxiliar para guardar el mapa;
	int		rtn;				//  retorno para funciones, -1 = ERROR;
	void	*img;
	int		*data_img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_vector	currentpos;
	t_moves	m;
	void 	*textures[5];
	int		*tdata[5];
}					t_file;

/*
** ft_read_src_file(); utils
*/
int					ft_read(t_file *f);
int					ft_read_src_file(t_file *f);
int					ft_handle_resolution(t_file *f);
void				ft_handle_error(char *str);
int					ft_handle_textures(t_file *f);
int					ft_check_extension(char *str);
int					ft_handle_spritex(t_file *f);
void				ft_handle_colors(t_file *f);
int					ft_handle_rgb(t_file *f, int i);
int					alloc_map(t_file *f);
int					map_check(int row, int col, t_file *f);
int					ft_draw(t_file *m);
int 				ft_key_press(int key, t_file *f);
int 				ft_key_release(int key, t_file *f);
int 				ft_calcdir(t_file *f);
int 				ft_movement(t_file *f);
int 				ft_move_draw(t_file *f);

#endif
