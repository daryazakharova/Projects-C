#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int resultCode = OK;
  if (A == NULL || result == NULL || A->rows <= 0 || A->columns <= 0) {
    resultCode = ERROR;
  } else if (A->rows != A->columns) {
    resultCode = CALC_ERROR;
  } else {
    matrix_t M = {0};
    if (s21_create_matrix(A->rows - 1, A->columns - 1, &M) != OK)
      resultCode = ERROR;
    if (s21_create_matrix(A->rows, A->columns, result) != OK)
      resultCode = ERROR;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        s21_getMatrix(A, i, j, &M);
        s21_determinant(&M, &result->matrix[i][j]);
        result->matrix[i][j] *= pow(-1, i + j);
      }
    }
    s21_remove_matrix(&M);
  }
  return resultCode;
}
