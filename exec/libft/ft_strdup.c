/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:53:49 by bbousaad          #+#    #+#             */
/*   Updated: 2024/07/15 12:53:58 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdupp(const char *s1)
{
	int		i;
	char	*s2;

	s2 = malloc(sizeof(char) * ft_strlenn((char *)s1) + 1);
	if (!s2)
		return (NULL);
	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
