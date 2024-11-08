/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_result.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:20:26 by jerperez          #+#    #+#             */
/*   Updated: 2024/11/08 13:14:00 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "print42.hpp"

static void log(std::ofstream &f, char *username)
{
	f << "I, " << username << " hereby certify I did not read the manual." << std::endl;
}

void log_result(t_map &map)
{
	std::string	s(map["--log-result"]);

	if ("no" == s)
		return ;
	char 		*username;
	username = getenv("USER");
	std::ofstream	f("/tmp/print42_readme.txt");

	if (f.is_open())
	{
		log(f, username);
		f.close();
	}
}
