#include <stdio.h>
#include <stdlib.h>

#define S21_PI 3.141592653589793238462643383279
#define S21_2PI 2.0 * S21_PI
#define S21_EXP 2.7182818284590452353602874713526624
#define S21_EPS 1e-8

#define S21_INF 1.0 / 0.0
#define S21_N_INF 1.0 / -0.0
#define S21_NAN 0.0 / 0.0

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

int s21_isNaN(double x);
int s21_isINF(double x);
int s21_isNINF(double x);
