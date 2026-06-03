/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:53:30 by bbousaad          #+#    #+#             */
/*   Updated: 2024/07/15 12:53:33 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strncmpp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	s = (char *)s1;
	d = (char *)s2;
	while ((s[i] != '\0') && (d[i] != '\0') && (s[i] == d[i]) && (i < n))
		i++;
	if (((unsigned char)s[i] == (unsigned char)d[i]) || (i == n))
		return (0);
	return ((unsigned char)s[i] - (unsigned char)d[i]);
}
