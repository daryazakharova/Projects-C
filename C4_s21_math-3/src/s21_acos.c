#include "s21_math.h"

long double s21_acos(double x) {
  long double acos = 0;
  if (x != x || x > 1 || x < -1) {
    acos = S21_NAN;
  } else {
    if (x == 1) {
      acos = 0;
    } else if (x == -1) {
      acos = S21_PI;
    } else {
      acos = S21_PI / 2 - s21_asin(x);
    }
  }
  return acos;
}