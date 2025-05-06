#include "s21_math.h"

long double s21_sin(double x) {  //нет проверки на inf
  long double res = 0.;          // результат вычислений

  if (x == S21_NAN || x == S21_N_INF || x == S21_INF) {
    res = S21_NAN;
  } else {
    // x в пределы от -PI до PI
    while (x > S21_PI || x < -S21_PI) {
      x += x > S21_PI ? -2 * S21_PI : 2 * S21_PI;
    }
    int ind = 0;           // индекс текущего слогаемого
    long double num;       // числитель
    long double det;       // знаменатель
    long double add = 0.;  // расчетное слогаемое
    long double eps;
    num = x;          // числительс индексом 0
    det = 1.;         // знаменатель с индексом 0
    add = num / det;  // первое приближение
    res = add;
    do {
      ++ind;
      long double pred = res;
      num *= -1 * x * x;
      det *= (2 * ind) * (2 * ind + 1);
      add = num / det;
      res += add;
      eps = pred - res < 0 ? res - pred : pred - res;
    } while (eps > S21_EPS /*ind < 100*/);
  }
  return res;
}