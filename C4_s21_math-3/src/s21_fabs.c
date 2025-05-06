#include "s21_math.h"

long double s21_fabs(double x) {
  if (s21_isNaN(x)) {
    x = S21_NAN;
  }
  if (s21_isINF(x)) {
    x = S21_INF;
  }
  x < 0 ? x *= (-1) : x;
  return x;
}