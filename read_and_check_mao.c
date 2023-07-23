/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check_mao.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:29:21 by afanti            #+#    #+#             */
/*   Updated: 2023/07/20 16:43:05 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	cheeck_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] && str[i] == ',' && str[i + 1] == ',')
		{
			printf("%s\n", str);
			printf_error("check yout color number");
		}
		if (ft_isdigit_or(str[i]) == 0)
		{
			printf("%s\n", str);
			printf_error("check yout color number");
		}
		i++;
	}
}

void	check_map_ide_if_clear(t_datta *data, int i)
{
	char	**str;

	i = -1;
	if (data->f[0] == ',' || data->f[ft_strlen(data->f) - 1] == ',')
		printf_error("there is error in color number in F");
	cheeck_error(data->f);
	str = ft_split(data->f, ',');
	while (str[++i])
	{
		if (i == 3 || ft_atoi(str[i]) < 0 || ft_atoi(str[i]) > 255)
			printf_error("there is error in your color number in map");
	}
	free_it(str);
	if (data->c[0] == ',' || data->c[ft_strlen(data->c) - 1] == ',')
		printf_error("there is error in color number in F");
	cheeck_error(data->c);
	str = ft_split(data->c, ',');
	i = -1;
	while (str[++i])
	{
		if (i == 3 || ft_atoi(str[i]) < 0 || ft_atoi(str[i]) > 255)
			printf_error("there is error in your color number in map");
	}
	free_it(str);
	check_texture_valid(data);
}

void	next_splite_ide(t_datta *data, char **string)
{
	if (ft_strncmp(string[0], "NO") == 0)
		data->no = ft_strdup(string[1]);
	else if (ft_strncmp(string[0], "SO") == 0)
		data->so = ft_strdup(string[1]);
	else if (ft_strncmp(string[0], "WE") == 0)
		data->we = ft_strdup(string[1]);
	else if (ft_strncmp(string[0], "EA") == 0)
		data->ea = ft_strdup(string[1]);
	else if (ft_strncmp(string[0], "F") == 0)
		data->f = ft_strdup(string[1]);
	else if (ft_strncmp(string[0], "C") == 0)
		data->c = ft_strdup(string[1]);
	else
		printf_error("your map not valid check it");
}

void	split_ide(t_datta *data)
{
	int		j;
	int		i;
	char	**string;
	char	*return_str;

	i = -1;
	while (data->ide[++i])
	{
		if (data->ide[i][0] == ' '
			|| data->ide[i][ft_strlen(data->ide[i]) - 1] == ' ')
			printf_error("map not valid");
		string = ft_split(data->ide[i], ' ');
		j = 0;
		while (string[j])
			j++;
		if (j != 2)
			printf_error("your texture name not valid ee");
		return_str = ft_strjoin(string[0], " ");
		return_str = t_strjoin(return_str, string[1]);
		next_splite_ide(data, string);
		(free_it(string), free(return_str));
	}
	if (!(data->no && data->so && data->we
			&& data->ea && data->f && data->c))
		printf_error("your map not valid check it");
}
