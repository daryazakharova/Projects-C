#include "s21_math.h"

long double s21_atan(double x) {
  long double atan = 0, x2;
  int i = 0, flag_x = 1;
  if (x < 0) {
    x *= -1;
    flag_x = -1;
  }
  if (x != x) {
    atan = S21_NAN;
  } else if (x == S21_INF) {
    atan = S21_PI / 2 * flag_x;
  } else if (x == 1) {
    atan = S21_PI / 4 * flag_x;
  } else {
    if (x <= 1) {
      atan = x2 = x;
      while (s21_fabs(x2) >= S21_EPS) {
        x2 = -x2;
        x2 *= ((x * x * (1 + 2 * i)) / (3 + 2 * i));
        atan += x2;
        i++;
      }
      atan *= flag_x;
    } else {
      atan = x2 = 1 / x;
      while (s21_fabs(x2) >= S21_EPS) {
        x2 = -x2;
        x2 *= ((1 + 2 * i) / (x * x * (3 + 2 * i)));
        atan += x2;
        i++;
      }
      atan = (S21_PI * s21_fabs(x) / (2 * x) - atan);
      atan *= flag_x;
    }
  }
  return atan;
}