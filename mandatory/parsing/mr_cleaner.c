/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mr_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:14:33 by efarhat           #+#    #+#             */
/*   Updated: 2023/09/24 11:00:52 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clean_arr2d(char **arr2d)
{
	int	i;

	if (!arr2d || !*arr2d)
		return ;
	i = 0;
	while (arr2d[i])
	{
		free(arr2d[i]);
		arr2d[i] = NULL;
		i++;
	}
	free(arr2d);
	arr2d = NULL;
}
