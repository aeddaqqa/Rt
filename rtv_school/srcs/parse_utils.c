/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:12:21 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/10/28 12:57:05 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char  *strcmptable(const char *str, char **tab)
{
    while(*tab && !ft_strequ(str,*tab))
    {
        tab++;
    }
    return (*tab);
}

void ft_strsplit_free(char ***tab)
{
    int     i;

    i = -1;
    while ((*tab)[i++])
        free((*tab)[i]);
    free((*tab));
}

int      ft_strsplit_len(char **tab)
{
    int     i;

    i = -1;
    while (tab[++i])
        ;
    return (i);
}

void      ft_strsplit_print(char **tab)
{
    int     i;

    i = -1;
    while (tab[++i])
        ft_putstr(tab[i]);
}

int     ft_camera_existance_check(char **tab)
{
    int     i;
    int     j;

    i = -1;
    j = 0;
    while (tab[++i])
    {
        if (ft_strequ(tab[i], "camera"))
            j += 1;
    }
    if (j == 1)
        return (1);
    else if (j == 0)
        ft_putstr("No camera was found in the file !\n");
    return (0);
}

int     ft_check_vec_cor(char **tab)
{
    int     i;

    i = -1;
    while (tab[++i])
    {
        if (tab[i] && !ft_str_is_numeric(tab[i]))
            return (0);
    }
    return (1);
}

int     ft_check_positive_floats(char *str)
{
    double   to_check;

    if (str && !ft_str_is_numeric(str))
        return (0);
    to_check = ft_atof(str);
    if (to_check <= 0.0)
        return (0);
    return (1);   
}

int     ft_check_floats(char *str)
{
    if (str && !ft_str_is_numeric(str))
        return (0);
    return (1);
}

int     ft_check_camera_fov(char *str)
{
    double  fov;

    fov = 0.0;
    if (str && ft_check_floats(str))
        {
            fov = ft_atof(str);
            if (fov <= 120.0 && fov >= 30.0)
                return (1);
        }
    return (0);
}

int     ft_check_vectors(char *str)
{
    int     i;
    char    **tab;

    if (!(tab = ft_strsplit(str, ' ')))
        return (0);
    i = ft_strsplit_len(tab);
    if (i != 3)
        return (0);
    if (!ft_check_vec_cor(tab))
        return (0);
    ft_strsplit_free(&tab);
    return (1);
}

int     ft_check_semicolon(char *line)
{
    int     i;

    if (line[0] == ';')
        return (0);
    i = -1;
    while (line[++i])
    {
        if (line[i] && line[i] == ';')
        {
            if (!line[i + 1] || line[i + 1] != '\n')
                return (0);
        }
    }
    return (1);
}

int     ft_check_whitespaces(char *line)
{
    int     i;

    if (line[0] == ' ' || line[0] == '\t')
        return (0);
    i = -1;
    while (line[++i])
    {
        if (line[i] && line[i] == ' ')
        {
            if (!line[i + 1] || line[i + 1] == ' '
            || line[i + 1] == '\t' || line[i + 1] == '\n' )
                return (0);
        }
    }
    return (1);
}

int     ft_check_empty_lines(char *line)
{
    int     i;

    if (line[0] == '\n')
        return (0);
    i = -1;
    while (line[++i])
    {
        if (line[i] && line[i] == '\n')
        {
            if (!line[i + 1] || line[i + 1] == '\n')
                return (0);
        }
    }
    if (!ft_check_semicolon(line))
        return (0);
    if (!ft_check_whitespaces(line))
        return (0);
    return (1);
}

int     ft_split_check(char *line)
{
    char    **tab;
    int     i;
    
    if (!ft_check_empty_lines(line))
        return (0);
    if(!(tab = ft_strsplit(line, '\n')))
        return (0);
    if (!ft_camera_existance_check(tab))
        return (0);
    if (!strcmptable(tab[0],(char *[]){ELEMENTS, NULL}))
        return (0);
    i = -1;
    while (tab[++i])
    {
        if (tab[i] && ft_strequ(tab[i], ";"))
        {
            if (!tab[i + 1] || !strcmptable(tab[i + 1],(char *[]){ELEMENTS, NULL}))
                return (0);
            else
                continue ;
        }
    }
    ft_strsplit_free(&tab);
    return (1);
}

static void	converting_base(char *str, t_base *v)
{
	if (str[v->i + 1] >= 48 && str[v->i + 1] <= 57)
		v->somme = v->somme + (str[v->i + 1] - 48) * pow(16, v->n);
	else if (str[v->i + 1] >= 97 && str[v->i + 1] <= 102)
		v->somme = v->somme + (str[v->i + 1] - 87) * pow(16, v->n);
	else if (str[v->i + 1] >= 65 && str[v->i + 1] <= 70)
		v->somme = v->somme + (str[v->i + 1] - 55) * pow(16, v->n);
}

int		ft_special_atoi_base(char *str)
{
	t_base		v;

	v.i = 0;
	v.n = 0;
	v.somme = 0;
	v.p = 0;
	v.rt = 0;
	while (str[v.i] != 'x' && str[v.i])
		v.i++;
	if (str[v.i] != '\0')
		v.rt = ft_strlen(str);
	while (str[v.rt - 1] != 'x' && str[v.rt - 1])
	{
		v.p++;
		v.rt--;
	}
	v.n = v.p - 1;
	while (str[v.i + 1] != '\0' && v.n >= 0)
	{
		converting_base(str, &v);
		v.i++;
		v.n--;
	}
	return (v.somme);
}

t_vec   vect_from_hexa(int rgb)
{
    t_vec v;

    int red = (rgb >> 16) & 0xFF;
    int green = (rgb >> 8) & 0xFF;
    int blue = rgb & 0xFF;

    v.x = (float)red / 255.0f;
    v.y = (float)green / 255.0f;
    v.z = (float)blue / 255.0f;
    return (v);
}

t_vec   string_to_vect(char *str)
{
    t_vec   v;
    char    **split;

    ft_bzero(&v, sizeof(t_vec));
    if ((split = ft_strsplit(str, ' ')) && ft_strsplit_len(split) == 3)
    {
        v.x = ft_atof(split[0]);
        v.y = ft_atof(split[1]);
        v.z = ft_atof(split[2]);
        ft_strsplit_free(&split);
    }
    return v;
}