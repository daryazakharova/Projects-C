#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int resultCode = OK;
  if (A == NULL || A->rows <= 0 || A->columns <= 0)
    resultCode = ERROR;
  else if (A->rows != A->columns)
    resultCode = CALC_ERROR;
  else if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  } else {
    matrix_t B = {0};
    double degree = 1;
    double resultB = 0;
    *result = 0;
    s21_create_matrix(A->rows - 1, A->columns - 1, &B);
    for (int j = 0; j < A->rows; j++) {
      s21_getMatrix(A, 0, j, &B);
      s21_determinant(&B, &resultB);
      *result += degree * A->matrix[0][j] * resultB;
      degree = -degree;
    }
    s21_remove_matrix(&B);
  }
  return resultCode;
}
