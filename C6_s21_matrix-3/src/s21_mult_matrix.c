#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int resultCode = OK;
  if (A == NULL || B == NULL || result == NULL || A->rows <= 0 ||
      A->columns <= 0 || B->rows <= 0 || B->columns <= 0)
    resultCode = ERROR;
  else if (A->columns != B->rows)
    return CALC_ERROR;
  else {
    if (s21_create_matrix(A->rows, B->columns, result) != OK)
      resultCode = ERROR;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return resultCode;
}
