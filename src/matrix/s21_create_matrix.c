#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  error_code error = OK;
  if (rows < 0 || columns < 0) {
    error = INCORRECT_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix) {
      for (int i = 0; i < rows && (error == OK); i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (!result->matrix[i]) {
          for (int j = 0; j < i; j++) free(result->matrix[j]);
          free(result->matrix);
          error = INCORRECT_MATRIX;
        }
      }
    }
  }
  return error;
}
