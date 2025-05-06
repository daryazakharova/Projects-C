#include "s21_matrix.h"

void s21_getMatrix(matrix_t *A, int row, int col, matrix_t *result) {
  int offsetRow = 0;
  for (int i = 0; i < A->rows - 1; i++) {
    if (i == row) {
      offsetRow = 1;
    }
    int offsetCol = 0;
    for (int j = 0; j < A->columns - 1; j++) {
      if (j == col) offsetCol = 1;
      result->matrix[i][j] = A->matrix[i + offsetRow][j + offsetCol];
    }
  }
}
