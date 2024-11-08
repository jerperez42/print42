/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:49:11 by jerperez          #+#    #+#             */
/*   Updated: 2024/11/08 12:00:42 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <cstdlib>
#include "print42.hpp"

static int _ans_time(int ans, int mod=60)
{
	struct timeval tv;
	struct timezone tz;

	gettimeofday(&tv,&tz);
	return ans + ((tv.tv_sec / 60) % mod);
}

void update_ans_time(t_map &map, int &ans)
{
	std::string s = map["--modulo-prendre-temps-journée"];

	if ("" == s)
		ans = _ans_time(ans, 60);
	else
		ans = _ans_time(ans, std::atoi(s.c_str()));
}
