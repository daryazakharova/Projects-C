#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int resultCode = OK;
  if (rows <= 0 || columns <= 0 || result == NULL)
    resultCode = ERROR;
  else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
      }

    } else
      resultCode = ERROR;
  }
  return resultCode;
}
