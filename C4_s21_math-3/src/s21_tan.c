#include "s21_math.h"

long double s21_tan(double x) {
  long double res;
  if (x == S21_N_INF || x == S21_INF || x == S21_NAN)
    res = S21_NAN;
  else {
    while (x > S21_PI / 2. || x < -S21_PI / 2.) {
      x += x > S21_PI / 2. ? -S21_PI : S21_PI;
    }
    if (x == S21_PI / 2.)
      res = S21_INF;
    else if (x == -S21_PI / 2.)
      res = S21_N_INF;
    else
      res = s21_sin(x) / s21_cos(x);
  }
  return res;
}