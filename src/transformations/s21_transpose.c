#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  error_code error = OK;
  if (!s21_is_correct_matrix(A)) {
    error = INCORRECT_MATRIX;
  } else {
    int res_rows = A->columns;
    int res_columns = A->rows;
    error = s21_create_matrix(res_rows, res_columns, result);
    for (int i = 0; (i < A->rows) && (error == OK); i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return error;
}
