#include "s21_math.h"

long double s21_ceil(double x) {
  long double ceil;
  if (x != x) {
    ceil = S21_NAN;
  } else if (s21_isINF(x)) {
    ceil = S21_INF;
  } else if (s21_isNINF(x)) {
    ceil = S21_N_INF;
  } else {
    ceil = (long long int)x;
    if (s21_fabs(x) > 0 && x != ceil) {
      if (x > 0) {
        ceil += 1;
      }

      if (-1 < x && x < 0) {
        ceil = -0.0;
      }
    }
  }
  return ceil;
}