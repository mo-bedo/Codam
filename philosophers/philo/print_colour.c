/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_colour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:14 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/14 11:55:14 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "print_colour.h"

//// Example of usage:

//	int main ()
//	{
//		red();
//		printf("Hello ");
//		yellow();
//		printf("world\n");
//		reset();
//		return 0;
//	}

//// Will print 'Hello' in red and 'world' in yellow. 'reset()' resets colour to default.

//// Changing [1;31m -> [0;31m will make it non-bold (so 1 == bold, 0 == normal)

void print_test(void *input)
{
	int count_test_runs = 1;

	cyan();
	printf("\t\t\t###############");
	red();
	printf(" TEST PRINT #%i \tpointer = %p\n", count_test_runs++, input);
//	printf("%i", *(int*)input);
	cyan();
	printf("###############\n");
	reset();
}

void red (void)
{
	printf("\033[1;31m");
}

void yellow (void)
{
		printf("\033[1;33m");
}

void green (void)
{
	printf("\033[1;32m");
}

void blue (void)
{
	printf("\033[1;34m");
}

void purple (void)
{
	printf("\033[1;35m");
}

void cyan (void)
{
	printf("\033[1;36m");
}

void reset (void)
{
	printf("\033[0m");
}
