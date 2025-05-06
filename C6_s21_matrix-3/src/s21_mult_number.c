#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int resultCode = OK;
  if (A == NULL || result == NULL || A->rows <= 0 || A->columns <= 0) {
    resultCode = ERROR;
  } else {
    if (s21_create_matrix(A->rows, A->columns, result) != OK)
      resultCode = ERROR;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = number * A->matrix[i][j];
      }
    }
  }
  return resultCode;
}
