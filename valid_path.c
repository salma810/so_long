/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:51:10 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/28 18:58:54 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exist(char **map, int c) 
{
    int	i = 0;
    int	j;

    while (map[i]) 
	{
        j = 0;
        while (map[i][j]) 
		{
            if (map[i][j] == c)
                return 1;
            j++;
        }
        i++;
    }

    return 0;
}

void floodfill(char **map, int x, int y, int c) 
{
    if ((map[x][y] != '0' && map[x][y] != 'P' && map[x][y] != c && map[x][y] != 'C'))
        return ;

    map[x][y] = 'Z';

    floodfill(map, x, y + 1, c);
    floodfill(map, x, y - 1, c);
    floodfill(map, x + 1, y, c);
    floodfill(map, x - 1, y, c);
}

void check_path(struct t_list *data, int c) 
{
    char **map = data->map_2d;

    floodfill(map, data->x_player, data->y_player, c);

    if (c == 'C')
	{
        if (check_exist(map, 'C'))
        {
            _free(map);
            ft_putstr_fd("Error: no valid path to collect\n", 2);
			exit (1);
        }
    }
    if (c == 'E') 
	{
        if (check_exist(map, 'E'))
        {
            _free(map);
            ft_putstr_fd("Error: no valid path to exit\n", 2);
			exit (1);
        }
    }
}
void valid_path(t_list *data)
{
	check_path(data, 'C');
	check_path(data, 'E');
}