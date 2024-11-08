/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:21:53 by jerperez          #+#    #+#             */
/*   Updated: 2024/11/08 10:16:45 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <iostream>
# include <string>

static void _you_won(void)
{
	int fun;

	if (0 == (unsigned long)&fun % 3)
		std::cout << "\e[1;31mOK\e[0m" << std::endl;
	else
		std::cout << "\e[1;32mOK\e[0m" << std::endl;
}

static void _you_lose(void)
{
	std::cout << "\e[1;31mKO\e[0m" << std::endl;
}

int	main(void)
{
	char	buff[5];
	ssize_t	bread;

	bread = read(STDIN_FILENO, buff, 5);
	if (3 != bread)
	{
		_you_lose();
		return 1;
	}
	buff[bread] = '\0';
	if (buff != std::string("42\n"))
	{
		_you_lose();
		return 1;
	}
	_you_won();
	return 0;
}
