#ifndef HEADER_H
# define HEADER_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include <math.h>

#define W 800
#define H 800
#define COLOR_1 0x192a56
#define COLOR_2 0xfbc531
#define COLOR_3 0xf5f6fa
#define COLOR_4 0x2f3640
#define FONT_P {0xea, 0xb5, 0x43}
#define FONT_S {0xF8, 0xEF, 0xBA}


typedef struct		s_sdl
{
	SDL_Window		*win_ptr;
	SDL_Renderer	*ren_ptr;
	SDL_Texture		*tex_ptr;
	int				*tex;
	int				*data;
}					t_sdl;

typedef struct	s_vect3
{
	double	x;
	double	y;
	double	z;
}				t_vect3;

typedef t_vect3	t_point;
typedef t_vect3	t_color;

typedef struct	s_light
{
	t_vect3			direction;
	t_point			position;
	double			intensity;
	double			distance;
	t_color			color;
	double			d;
	t_vect3			light_reflected;
	struct s_light	*next;
}				t_light;

typedef struct	s_cords
{
	t_vect3	u;
	t_vect3	v;
	t_vect3	w;
}				t_cords;

typedef struct	s_cam
{
	t_point			o;
	t_vect3			l;
	t_vect3			up;
	t_cords			cords;
	double			fov;
	double			ratio;
	double			plan_h;
	double			plan_w;
	struct s_cam	*next;
	struct s_cam	*prev;
}				t_cam;

typedef struct	s_ray
{
	t_vect3	origin;
	t_vect3	direction;
	t_point	hit_point;
	int		reflect_nb;
	double	reflexion_index;
	double	t;
	int		ret;
}				t_ray;

typedef struct	s_intersect
{
	double	k;
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t;
	double	t1;
	double	t2;
}				t_intersect;

typedef struct	s_object
{
	t_vect3			position;
	t_vect3			translation;
	t_vect3			rotation;
	t_color			color;
	t_point			point_a;
	t_point			point_b;
	t_point			point_c;
	t_point			point_d;
	t_point			corner[2];
	t_vect3			orientation;
	t_vect3			normal;
	double			height;
	double			radius;
	double			radius1;
	double			radius2;
	double			distance;
	double			angle;
	int				is_ref;
	int				is_transp;
	t_intersect		cyl;
	struct s_object	*next;
}				t_object;

typedef struct		s_delta
{
	double	a;
	double	b;
	double	c;
	double	disc;
	double	delta;
}					t_delta;

typedef struct	s_cone
{
	t_delta	d;
	t_vect3	pa;
	t_vect3	va;
	t_vect3	x;
	t_vect3	a;
	t_vect3	b;
	float	anglesin;
	float	t1;
	float	t2;
	float	anglecos;
}				t_cone;

typedef struct	s_rt
{
	int				number_id;
	t_sdl			*sdl;
	t_object		*objects;
	t_cam			*cameras;
	t_light			*lights;
}				t_rt;
void draw(t_rt *rt);
double  deg_to_rad(double angle);
t_vect3		cross(t_vect3 a, t_vect3 b);
double		dot(t_vect3 a, t_vect3 b);
double		ft_magnitude(t_vect3 v);
t_vect3		ft_negative(t_vect3 v);
t_vect3	normalize(t_vect3 vec);
t_vect3	v_c_add(t_vect3 u, double v);
t_vect3		v_c_prod(t_vect3 c, double scalar);
t_vect3		vect_add(t_vect3 a, t_vect3 b);
t_vect3		vect_sub(t_vect3 a, t_vect3 b);
t_vect3	vect_prod(t_vect3 u, t_vect3 v);
t_vect3		sphere_normal(t_object *obj, t_ray *ray);
int				light(t_object *close_obj, t_ray *ray, t_rt *rt, double t);
t_vect3		cylinder_normal(t_object *object, t_ray *ray);
#endif
