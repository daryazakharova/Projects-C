#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int resultCode = OK;
  if (A == NULL || B == NULL || result == NULL || A->rows <= 0 ||
      A->columns <= 0 || B->rows <= 0 || B->columns <= 0) {
    resultCode = ERROR;
  } else if (A->columns != B->columns || A->rows != B->rows) {
    resultCode = CALC_ERROR;
  } else {
    if (s21_create_matrix(A->rows, A->columns, result) != OK)
      resultCode = ERROR;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return resultCode;
}
