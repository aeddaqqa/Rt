/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:14:56 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/21 22:20:37 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/*
**-----------------------------{structers}---------------------
*/

typedef struct	s_name_tags
{
	char *elements_o[6];
	char *elements_c[6];
	char *components_c[9];
	char *components_o[9];
}				t_tags;

typedef struct	s_ocomponent
{
	bool	position;
	bool	color;
	bool	orientation;
	bool	radius;
	bool	ambient;
}				t_ocomponent;

typedef struct	s_lcomponent
{
	bool	position;
	bool	color;
	bool	intensity;
}				t_lcomponent;

typedef struct	s_ccomponent
{
	bool	origin;
	bool	look_at;
	bool	fov;
}				t_ccomponent;

typedef struct	s_node
{
	int				type;
	t_ocomponent		cmp;
	t_ccomponent		cam;
	t_lcomponent		lit;
}				t_node;

/*
** ------------------------------{Stock}-------------------------
*/
char			*load_file(char *path);
char			*get_tag(char *s, int *i);
char			*inner_text(char *s, int *j);
int				white_space(char *s, int *i);
int				stock_elements_cmp(char *s, t_tags tags, t_node n, int *i, void *obje);
int				parse(char *file, t_rt *rt);
int				stock_cmp(void **object, char *str, int r, int type);
int				stock_elements(char *str, t_tags tags, int *i, t_rt *rt);
int				get_point(char *s, t_point *p);
int				get_ori_vect(char *s, t_vect3 *ori);
int				get_color(char *s, t_color *color);
int				get_raduis_a(char *s, int type, double *r_a);
/*
** ------------------------------{Init}-------------------------
*/

t_rt			*init_rt(bool save);
t_tags			init_tab_tags(void);
t_node			init_node(void);

/*
** ------------------------------{Free}-------------------------
*/

void			free_rt(t_rt **rt);
void			destroy(t_error type);

/*
** ------------------------------{Check}-------------------------
*/

int				check_openning_elem(char *s, char **tab);
int				check_closing_elem(char *s, int n, char **tab, int *i);
int				check_components_exist(t_node n, int type);

/*
** ------------------------------{Util}-------------------------
*/

void			add_front(t_rt **head, void *new, int type);
void			*new_object(int type);

/*
**{--------------------------------------------------------------}
*/
#endif
