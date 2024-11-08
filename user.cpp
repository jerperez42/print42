/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:20:26 by jerperez          #+#    #+#             */
/*   Updated: 2024/11/08 11:01:37 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>

static void log(std::ofstream &f, char *username)
{
	f << "I, " << username << " hereby certify I did not read the manual." << std::endl;
}

void log_result(void)
{
	char 		*username;
	//int 		i;

	username = getenv("USER");
	// if (NULL == user || '\0' == user[0])
	// 	std::cout << "print42: info: env: USER is not set" << std::endl;
	// if ('\0' == username[0])
	// {
	// 	i = 0;
	// 	while ('\0' != user[i] && i < 15)
	// 	{
	// 		username[i] = user[i];
	// 		i++;
	// 	}
	// 	username[i] = user[i];
	// }
	// else
	// {
	// 	i = 0;
	// 	while ('\0' != user[i] && i < 15)
	// 	{
	// 		if (username[i] != user[i])
	// 		{
	// 			std::cout << "print42: info: env: USER has changed!" << std::endl;
	// 			break;
	// 		}
	// 		i++;
	// 	}
	// 	username[i] = user[i];
	// }
	std::ofstream	f("/tmp/print42_readme.txt");

	if (f.is_open())
	{
		log(f, username);
		f.close();
	}
}