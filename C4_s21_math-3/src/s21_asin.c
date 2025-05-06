#include "s21_math.h"

long double s21_asin(double x) {
  long double asin = 0;
  if ((-1 <= x) && (x <= 1)) {
    asin = s21_atan(x / (s21_sqrt(1 - x * x)));
  } else
    asin = S21_NAN;
  return asin;
}