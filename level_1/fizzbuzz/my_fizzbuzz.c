/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fizzbuzz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:35:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/20 13:37:38 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int is_divisible_by_three(int i);
static int is_divisible_by_five(int i);
static int is_divisible_by_three_and_five(int i);
static int putendl(char *s);
static void print_number(int i);
static void my_putchar(char c) { write(1, &c, 1); }

int main(void) {
    int i = 0;

    while (++i <= 100) {
        if (is_divisible_by_three_and_five(i))
            putendl("FizzBuzz");
        else if (is_divisible_by_three(i))
            putendl("Fizz");
        else if (is_divisible_by_five(i))
            putendl("Buzz");
        else {
            print_number(i);
            putendl("");
        }
    }
    putendl("");
}

void print_number(int number) {
    if (number > 9) print_number(number / 10);
    my_putchar(number % 10 + '0');
}

int putendl(char *s) {
    int count;
    while (s && *s) count += write(1, s++, 1);
    count += write(1, "\n", 1);
    return (count);
}

static int is_divisible_by_three(int i) { return (!(i % 3)); }

static int is_divisible_by_five(int i) { return (!(i % 5)); }

static int is_divisible_by_three_and_five(int i) {
    return (!(i % 3) && !(i % 5));
}
