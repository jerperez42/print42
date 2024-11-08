/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:50:34 by jerperez          #+#    #+#             */
/*   Updated: 2024/11/08 13:25:34 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <unistd.h>
#include <cstdlib>
#include "print42.hpp"
//#include <iostream>

void putstr_fd(std::string const &s, t_map &map)
{
	std::string opt(map["--set-fd-out"]);

	int fd = 0;
	if ("" != opt)
		fd = std::atoi(opt.c_str());
	if (fd == STDIN_FILENO || fd == STDOUT_FILENO || fd == STDERR_FILENO)
		write(fd, s.c_str(), s.length());
}
