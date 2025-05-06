#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;
  if (A == NULL || B == NULL || A->columns != B->columns ||
      A->rows != B->rows || A->rows <= 0 || A->columns <= 0 || B->rows <= 0 ||
      B->columns <= 0) {
    result = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if ((A->matrix[i][j] - B->matrix[i][j]) > 1e-7) result = FAILURE;
      }
    }
  }
  return result;
}
