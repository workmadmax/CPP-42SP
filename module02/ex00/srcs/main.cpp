/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:12:21 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/15 11:03:42 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:00:26 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/15 11:02:11 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ieee754.h>
#include <cstdio>
#include <cmath>

#define LOG2_10 3.321928095
 
#define flt_zero(x) (fabs(x) < EPSILON)

const double EPSILON = 1e-10;

 
int max_digs_rt = 3;  /* maximum # of 0's right of decimal before using
                         scientific notation */
int max_digs_lf = 5;  /* max # of digits left of decimal */
 
void print_real(double r, int width, int dec)
{
    int mag;
    double fpart, temp;
    char format[8];
    char num_format[3] = {'l',0,0};
    union ieee754_double *dl;
 
    dl = (union ieee754_double*)&r;
    mag = (dl->ieee.exponent - IEEE754_DOUBLE_BIAS) / LOG2_10;
    if (r == 0)
        mag = 0;
    if ((mag > max_digs_lf-1) || (mag < -max_digs_rt)) {
        num_format[1] = 'e';
        temp = r/pow(10, mag);      /* see if number will have a decimal */
        fpart = temp - floor(temp); /* when written in scientific notation */
    }
    else {
        num_format[1] = 'f';
        fpart = r - floor(r);
    }
    if (flt_zero(fpart))
        dec = 0;
    if (width == 0) {
        snprintf(format, 8, "%%.%d%s", dec, num_format);
    }
    else {
        snprintf(format, 8, "%%%d.%d%s", width, dec, num_format);
    }
    printf(format, r);
}

int main()
{
    double d1 = 42.424242424;
    double d2 = 0.0000000001;
    double d3 = 123456789.987654321;
    double d4 = -3.14159265358979323846;
    
    print_real(d1, 0, 0); // should print "42.424242"
	printf("\n");
    print_real(d2, 0, 0); // should print "0.000000"
	printf("\n");
    print_real(d3, 0, 0); // should print "1.23457e+08"
	printf("\n");
    print_real(d4, 0, 5); // should print "-3.14159"
	printf("\n");
    
    return 0;
}