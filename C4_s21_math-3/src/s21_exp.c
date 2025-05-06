#include "s21_math.h"
long double s21_exp(double x) {
  long double result = 0;
  long double current = 1;
  int flag = 0;
  int count = 1;
  if (x < 0) {
    flag = 1;
    x *= -1;
  }
  while (current > S21_EPS) {
    if (x == S21_INF) {
      result = S21_INF;
      break;
    }
    if (x != x) {
      result = S21_NAN;
      break;
    }
    result += current;
    current *= x / count;
    count++;
    if (count == 376) {
      result = S21_INF;
      break;
    }
  }
  if (flag) {
    result = 1 / result;
  }
  return result;
}
