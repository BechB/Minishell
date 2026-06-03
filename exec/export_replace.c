/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:03:01 by bbousaad          #+#    #+#             */
/*   Updated: 2024/07/16 18:30:29 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_export2(t_data *dta, int cmd, int y, int len_read)
{
	if (dta->read[cmd][len_read] == '\0' || dta->read[cmd][len_read] == '=')
	{
		if (dta->cpy_envp[y])
			free (dta->cpy_envp[y]);
		dta->cpy_envp[y] = ft_strdupp(dta->read[cmd]);
		return (1);
	}
	return (0);
}

int	check_export3(t_data *dta, int cmd, int y, int len_read)
{
	if (dta->read[cmd][len_read] == '=' && dta->cpy_envp[y][len_read] == '\0')
	{
		if (dta->cpy_envp[y])
			free (dta->cpy_envp[y]);
		dta->cpy_envp[y] = ft_strdupp(dta->read[cmd]);
		return (1);
	}
	if (dta->read[cmd][len_read] == '\0' && dta->cpy_envp[y][len_read] == '=')
		return (1);
	return (0);
}

int	check_export(t_data *dta, int cmd)
{
	int	y;
	int	len_read;

	y = 0;
	len_read = 0;
	while (dta->read[cmd][len_read] && dta->read[cmd][len_read] != '=')
		len_read++;
	while (dta->cpy_envp[y])
	{
		if (ft_strncmpp(dta->cpy_envp[y], dta->read[cmd], len_read + 1) == 0)
		{
			if (check_export2(dta, cmd, y, len_read))
				return (1);
		}
		if (ft_strncmpp(dta->cpy_envp[y], dta->read[cmd], len_read) == 0)
		{
			if (check_export3(dta, cmd, y, len_read))
				return (1);
		}
		y++;
	}
	return (0);
}
