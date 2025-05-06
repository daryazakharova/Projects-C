#include "s21_math.h"

long double s21_log(double x) {
  long double res = 0.;  // результат вычислений
  int ind = 0;           // индекс текущего слогаемого
  if (x < 0.)
    res = S21_NAN;  // если аргумент отрицательный, то значения не существует
  else if (x == 0.) {
    res = S21_N_INF;
  } else if (x == 1.) {
    res = 0.;
  } else if (x == S21_INF) {
    res = S21_INF;
  } else {
    while (x >= S21_EXP) {
      x /= S21_EXP;
      ind++;
    }
    for (int i = 0; i < 100; i++) {
      long double add = res;
      res = add + 2 * (x - s21_exp(add)) / (x + s21_exp(add));
    }
    res += ind;
  }
  return res;
}
