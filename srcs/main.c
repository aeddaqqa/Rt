/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:41:44 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/11/17 12:14:36 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"

int		main(int ac, char **av)
{
	FILE *file;
	int size;
	char *source;
	
	if (ac == 2 && av[1])
	{
		file = fopen(av[1], "r");
		if (!file)
			printf("OK BANANA\n");
		else
		{
			fseek(file, 0, SEEK_END);
			size = ftell(file);
			source = malloc(sizeof(char) * size + 1);
			fseek(file, 0, SEEK_SET);
			fread(source, 1, size, file);
			source[size] = '\0';
			printf("%s\n wa l9lawi %d\n", source, size);
		}
	}
	return (0);
}
