/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fizzbuzz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:35:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/25 09:15:02 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static short		is_divisible_by_three(int i);
static short		is_divisible_by_five(int i);
static short		is_divisible_by_seven(int i);
static short 		is_divisible_by_eleven(int i);
static short		is_divisible_by_three_and_five(int i);
static void			print_number(int i);

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 1000000)
	{
		if (is_divisible_by_three_and_five(i))
			write(1, "FizzBuzz\n", 9);
		else if (is_divisible_by_three(i))
			write(1, "Fizz\n", 5);
		else if (is_divisible_by_five(i))
			write(1, "Buzz\n", 5);
		else
			print_number(i);
		i++;
	}
	write(1, "\n", 1);
}

static  void	print_number(int number)
{
    static const char str[10] = {"0123456789"};
    int digits[10];
    int i = 0;

    while (number > 0) 
	{
        digits[i++] = number % 10;
        number /= 10;
    }
    while (i > 0) 
	{
        i--;
        write(1, &str[digits[i]], 1);
    }
	write(1, "\n", 1);
}

static  short	is_divisible_by_three(int i)
{
	return (!(i % 3));
}

static  short	is_divisible_by_five(int i)
{
	return (!(i % 5));
}

static  short is_divisible_by_seven(int i)
{
	return (!(i % 7));
}

static  short is_divisible_by_eleven(int i)
{
	return (! (i % 11));
}

static  short	is_divisible_by_three_and_five(int i)
{
	return (!(i % 3) && !(i % 5));
}
