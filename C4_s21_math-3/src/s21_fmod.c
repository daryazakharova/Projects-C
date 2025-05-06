#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result;
  if (s21_isINF(x) && s21_isINF(y)) {
    result = S21_NAN;
  } else if (y == 0 || s21_isNaN(x) || s21_isNaN(y) || s21_isINF(x)) {
    result = S21_NAN;
  } else if (x == 0 || x == y) {
    result = 0.;
  } else {
    result = x - ((x / y) < 0 ? s21_ceil(x / y) : s21_floor(x / y)) * y;
    if (s21_isINF(y)) {
      result = x;
    }
  }
  return result;
}