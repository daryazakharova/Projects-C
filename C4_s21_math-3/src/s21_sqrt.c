#include "s21_math.h"

long double s21_sqrt(double x) {
  long double current = 0, result = 600;
  if (x == 0.)
    result = 0;
  else if (x == S21_INF) {
    result = S21_INF;
  } else {
    while (s21_fabs(result - current) > S21_EPS) {
      if (x < 0) {
        result = S21_NAN;
        break;
      }
      current = result;
      result = (current + x / current) / 2;
    }
  }
  return result;
}