/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:21:57 by bbousaad          #+#    #+#             */
/*   Updated: 2024/07/16 18:34:50 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handl_echo_redir(t_data *dta, char **envp)
{
	int	i;

	i = 0;
	(void) envp;
	while (dta->exec[i])
	{
		if (ft_strncmpp(dta->read[0], "echo\0", 5) == 0)
		{
			if (count_redir(dta->exec[i], '>') == 1)
				return (1);
			if (count_redir(dta->exec[i], '>') == 2)
				return (1);
			if (count_redir(dta->exec[i], '<') == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

void	handl_echo_2(t_data *dta, char **envp)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	(void) envp;
	while (dta->read[len])
		len++;
	if (ft_strncmpp(dta->read[0], "echo\0", 5) == 0
		&& dta->read[1] != 0)
	{
		if (dta->read[1][0] == '-' && dta->read[1][1] == 'n')
		{
			print_echo(dta);
			g_exit_status = 0;
		}
		else
		{
			handl_dollar(dta, i, len);
			g_exit_status = 0;
		}
	}
	else
		handl_exec3(dta, envp);
}
