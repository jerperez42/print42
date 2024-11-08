/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print42.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:21:53 by jerperez          #+#    #+#             */
/*   Updated: 2024/11/08 09:50:27 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cstring>
# include <map>
# include <unistd.h>
# include "print42.hpp"

typedef std::map<std::string, std::string> t_map;

static int	_updateArgs(std::string pair, t_map &map)
{
	std::size_t pos = pair.find("=");

	if (std::string::npos == pos)
		return 1;
	std::string const key = pair.substr(0, pos);
	std::string const value = pair.substr(pos + 1, pair.length());

	pos = value.find("=");
	if (std::string::npos != pos)
		return 1;
	map[key] = value;
	return 0;
}


static int	_parseArgs(int ac, char *av[], t_map &map)
{
	for (int i = 1; i != ac; ++i)
	{
		if (_updateArgs(av[i], map))
			return 1;
	}
	return 0;
}


static void _printArgs(t_map &map)
{
	t_map::const_iterator const	it_end = map.end();

	for (t_map::iterator it = map.begin(); it != it_end; ++it)
		std::cerr << it->first << ':' << it->second << "|" << std::endl;
}


static int	_get_score(int ac, char *av[])
{
	int score = 0;
	for (int i = 0; i != ac; ++i)
	{
		score += std::strlen(av[i]);
	}
	return score;
}

static void	_print_msg(int ac, char *av[], char *env[])
{
	(void)env;
	std::string ans = ("42\n");

	write(0, ans.c_str(), ans.length());
	//std::cout << 42 << std::endl;
	std::cerr << "info: your score is " << _get_score(ac, av) << std::endl;
}

int	main(int ac, char *av[], char *env[])
{
	t_map map;

	if (_parseArgs(ac, av, map))
	{
		std::cerr << "print42: error: bad options" << std :: endl;
		return 1;
	}
	_printArgs(map);
	_print_msg(ac, av, env);
	return 0;
}
