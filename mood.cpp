/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mood.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:10:15 by jerperez          #+#    #+#             */
/*   Updated: 2024/11/08 13:58:36 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print42.hpp"
#include <string>
//#include <iostream> //

void	set_mood(t_map &map, std::string &s)
{
	std::string mood  = map["--기분"];

	int pos = s.length() - 1;
	std::string s_out;
	bool no_newline = (-1 == pos || '\n' != s[pos]);
	bool not_changed = false;

	if (no_newline)
		s_out = s;
	else
		s_out=s.substr(0, pos);

	if ("기본" == mood)
		not_changed = true;
	else if ("신남" == mood)
		s = "\e[1;6;30;45m" + s_out + "\e[0m";
	else if ("나태" == mood)
		s = "\e[94m" + s_out + "\e[0m";
	else if ("basic" == mood || "" == mood)
		s = "\e[0m" + s_out + "\e[0m";
	if (false == not_changed && false == no_newline)
		s += '\n';
}
