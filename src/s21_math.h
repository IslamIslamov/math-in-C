#ifndef S21_MATH_H
#define S21_MATH_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_PI 3.14159265358979324
#define s21_PI_2 (s21_PI / 2.F)
#define s21_NPI -3.14159265358979324
#define s21_EPS 1e-17
#define s21_SQRT_EPS 1e-20l
#define s21_ln10 2.30258509299404590109
#define s21_MAX_double 1.7976931348623157e308
#define s21_EXP 2.71828182845904523536

#define ROUND_UP 1e-06

#define s21_INF __builtin_inf()
#define s21_NAN __builtin_nan("")
#define s21_is_inf __builtin_isinf
#define s21_is_nan __builtin_isnan

int s21_abs(int x);
long double s21_exp(double x);
long double s21_ceil(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_sqrt(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double expp);

#endif  //  S21_MATH_H