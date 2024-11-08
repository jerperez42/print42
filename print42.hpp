/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print42.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:45:45 by jerperez          #+#    #+#             */
/*   Updated: 2024/11/08 13:16:31 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT42_HPP
# define PRINT42_HPP

#include <map>
#include <string>

	typedef std::map<std::string, std::string> t_map;

	void log_result(t_map &map);
	void putstr_fd(std::string const &s, t_map &map);
	void set_mood(t_map &map, std::string &s);
	void update_ans_time(t_map &map, int &ans);

#endif
