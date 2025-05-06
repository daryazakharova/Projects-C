#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int resultCode = OK;
  if (A == NULL || result == NULL || A->rows <= 0 || A->columns <= 0) {
    resultCode = ERROR;
  } else if (A->rows != A->columns) {
    resultCode = CALC_ERROR;
  } else {
    double resultA = 0;
    s21_determinant(A, &resultA);
    if (resultA == 0) resultCode = CALC_ERROR;
    matrix_t transposeResult = {0};
    s21_calc_complements(A, result);
    s21_transpose(result, &transposeResult);
    s21_remove_matrix(result);
    double detA = 1 / resultA;
    s21_mult_number(&transposeResult, detA, result);
    s21_remove_matrix(&transposeResult);
  }
  return resultCode;
}
