#include "s21_math.h"

long double s21_cos(double x) {
  long double result;
  if (x == 0.) {
    result = 1.;
  } else if (s21_isNaN(x) || s21_isINF(x)) {
    result = S21_NAN;
  } else {
    x = s21_fmod(x, S21_2PI);

    result = s21_sin(x + S21_PI / 2.);
  }
  return result;
}