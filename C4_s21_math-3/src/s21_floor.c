#include "s21_math.h"

long double s21_floor(double x) {
  long double result = (long long int)x;
  if (s21_isNaN(x)) {
    result = S21_NAN;
  }
  if (s21_isINF(x)) {
    result = S21_INF;
  }
  if (s21_isNINF(x)) {
    result = S21_N_INF;
  }
  if (s21_fabs(x - result) > 0. && x != result && s21_fabs(x) > 0.) {
    if (x < 0.) {
      result -= 1;
    }
  }
  return result;
}