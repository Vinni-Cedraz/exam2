/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:32:48 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/18 22:46:17 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <stdio.h>

static int my_putchar(char c);
static void create_stack(unsigned char octet, int counter);

void print_bits_rec(unsigned char octet) { 
  create_stack(octet, 8); 
}

static inline void create_stack(unsigned char octet, int counter) {
  if (counter > 0) {
    create_stack(octet >> 1, counter - 1);
    my_putchar((octet & 1) + '0');
  }
}

static inline int my_putchar(char c) { 
  return (write(1, &c, 1));
}

void print_bits(char octet) {
  unsigned char mask = 0b10000000;
  while (mask) {
    my_putchar((octet & mask) ? '1' : '0');
    mask >>= 1;
  }
}

int main() {
  char num1 = 0b00000000;
  print_bits(num1); // should print "00000000\n"
  my_putchar('\n');
  print_bits_rec(num1); // should print "00000000\n"
  my_putchar('\n');

  char num2 = 0b11111111;
  print_bits(num2); // should print "11111111\n"
  my_putchar('\n');
  print_bits_rec(num2); // should print "11111111\n"
  my_putchar('\n');

  char num3 = 0b01010101;
  print_bits(num3); // should print "01010101\n"
  my_putchar('\n');
  print_bits_rec(num3); // should print "01010101\n"
  my_putchar('\n');

  char num4 = 0b10000000;
  print_bits(num4); // should print "10000000\n"
  my_putchar('\n');
  print_bits_rec(num4); // should print "10000000\n"
  my_putchar('\n');

  char num5 = 0b00110001;
  print_bits(num5); // should print "00110001\n"
  my_putchar('\n');
  print_bits_rec(num5); // should print "00110001\n"
  my_putchar('\n');

  return 0;
}
