/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print42.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:21:53 by jerperez          #+#    #+#             */
/*   Updated: 2024/11/08 13:59:39 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cstring>
# include <map>
# include <unistd.h>
# include <cstdlib>
# include <sstream>
# include "print42.hpp"

static std::string _cstr(int num)
{
	std::stringstream ss;

	ss << num;
	return ss.str();
}

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


// static void _printArgs(t_map &map)
// {
// 	t_map::const_iterator const	it_end = map.end();

// 	for (t_map::iterator it = map.begin(); it != it_end; ++it)
// 		std::cerr << it->first << ':' << it->second << "|" << std::endl;
// }


static int	_get_score(int ac, char *av[])
{
	int score = 0;
	for (int i = 0; i != ac; ++i)
	{
		score += std::strlen(av[i]);
	}
	return score;
}

static void	_print_msg(int ac, char *av[], char *env[], t_map &map)
{
	(void)env;
	int num = 42;

	update_ans_time(map, num);
	std::string ans = _cstr(num);

	print(map, ans);
	ans += '\n';
	set_mood(map, ans);
	putstr_fd(ans, map);
	log_result(ans, map);
	std::cerr << "info: your score is " << _get_score(ac, av) << std::endl;
}

int	main(int ac, char *av[], char *env[])
{
	t_map 		map;

	if (_parseArgs(ac, av, map))
	{
		std::cerr << "print42: error: bad options" << std :: endl;
		return 1;
	}
	//_printArgs(map);
	_print_msg(ac, av, env, map);
	return 0;
}
