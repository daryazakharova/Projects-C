#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int resultCode = OK;
  if (A == NULL || result == NULL || A->rows <= 0 || A->columns <= 0) {
    resultCode = ERROR;
  } else {
    if (s21_create_matrix(A->columns, A->rows, result) != OK)
      resultCode = ERROR;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return resultCode;
}
