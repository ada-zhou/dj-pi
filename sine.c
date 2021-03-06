//
//  sine.c
//  
//
//  Created by Harrison Bronfeld on 6/7/17.
//
//

#include "sine.h"

static double three_factorial = 6.0;
static double five_factorial = 120.0;
static double seven_factorial = 5040.0;
static double nine_factorial = 362880.0;
static double eleven_factorial = 39916800.0;
static double thirteen_factorial = 6227020800.0;

//simple power function
double power(double x, double exponent){
    double result = 1;
    for (int i = 0; i < exponent; i++){
        result *= x;
    }
    return result;
}

//calculates a sine using the taylor series to the 13th degree
double sine(double x){
    double mod_x = float_mod(x, 3.1415926); //uses float mod on everything greater than pi
    double result = mod_x;
    result -= power(mod_x, 3.0) / three_factorial;
    result += power(mod_x, 5.0) / five_factorial;
    result -= power(mod_x, 7.0) / seven_factorial;
    result += power(mod_x, 9.0) / nine_factorial;
    result -= power(mod_x, 11.0) / eleven_factorial;
    result += power(mod_x, 13.0) / thirteen_factorial;
    return result;
}

//simple float mod function
double float_mod(double x, double y){
    int num_times = x / y;
    if (num_times % 2 == 0){
        return x - (y * (double)num_times);
    }
    return -1 * (x - (y * (double)num_times));
}
