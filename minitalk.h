/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 02:23:16 by ayouahid          #+#    #+#             */
/*   Updated: 2025/03/02 02:23:19 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>

long	ft_atoi(const char *str);
long	ft_atoi_err(const char *str, int *err);
int	ft_isdigit(int a);
char	*isvalid(char *av);

#endif