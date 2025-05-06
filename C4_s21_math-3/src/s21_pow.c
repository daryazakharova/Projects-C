#include <float.h>

#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 1;
  if (base == 1. || exp == 0. || (base == 1. && exp == S21_NAN)) {
    result = 1;
  } else if (s21_isNaN(exp) || s21_isNaN(base)) {
    result = S21_NAN;
  } else if (base == 0.) {
    if (s21_isNINF(exp))
      result = S21_INF;
    else
      result = 0.;
  } else if (s21_isINF(base) || s21_isNINF(base) || s21_isINF(exp) ||
             base >= DBL_MAX || exp >= DBL_MAX) {
    result = S21_INF;
  } else if (s21_isNINF(exp)) {
    result = 0.;
  } else {
    if (exp != 0) {
      result = base;
      for (int i = 1; i < s21_fabs(exp); i++) {
        result *= base;
      }
    }
    if (exp < 0) result = 1 / result;
    if ((long long int)exp != exp) result = s21_exp(exp * s21_log(base));
  }
  return result;
}