/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:50:28 by jerperez          #+#    #+#             */
/*   Updated: 2024/11/08 13:52:56 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print42.hpp"
#include <string>

void	print(t_map &map, std::string &ans)
{
	std::string opt(map["--print-42"]);

	if ("yes" == opt)
		ans += "42";
}
