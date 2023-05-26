/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:53:01 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/26 17:31:49 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
void	check_map()
{
	int	i;
	char *map;
	int new_line_count = 0;
	
	i = 0;

	map = "\n111111111111\n111100000P11\n100000000C11\n111111111111\n\n\n\n\n\n\n";
	while (map[i])
	{
		if (map[i] == '1' || map[i] == '0' || map[i] == 'C'
			|| map[i] == 'P' || map[i] == 'E')
        {
            new_line_count = 0;
			i++;
        }
		else if(map[i] == '\n')
		{
        printf("%s", map);
			new_line_count++;
			if(new_line_count > 1)
			{
				
				puts("Error: Too Many New Lines");
                exit (1);
			}
		}
        else
        {
          
            puts("Error: Invalid Map");
            exit (1);
        }
	}
}
int main()
{

     check_map();
     return 0;
}