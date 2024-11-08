/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print42.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:45:45 by jerperez          #+#    #+#             */
/*   Updated: 2024/11/08 11:19:54 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT42_HPP
# define PRINT42_HPP

#include <map>
#include <string>

	typedef std::map<std::string, std::string> t_map;

	void log_result(void);
	void putstr_fd(std::string const &s, int fd = 0);
	void set_mood(t_map &map, std::string &s);

#endif
