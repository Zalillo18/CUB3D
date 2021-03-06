/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartin- <gmartin-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:54:07 by gmartin-          #+#    #+#             */
/*   Updated: 2019/11/18 18:11:20 by gmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int a;

	a = 0;
	if (s)
	{
		while (s[a] != '\0')
		{
			write(fd, &s[a], 1);
			a++;
		}
		write(fd, "\n", 1);
	}
}
