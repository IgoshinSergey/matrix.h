#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  error_code error = OK;
  if (!s21_is_correct_matrix(A) || !s21_is_correct_matrix(B)) {
    error = INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    error = ARITHMETIC_ERROR;
  } else {
    int res_rows = A->rows;
    int res_columns = B->columns;
    int l = A->columns;
    error = s21_create_matrix(res_rows, res_columns, result);
    for (int i = 0; (i < res_rows) && (error == OK); i++) {
      for (int j = 0; j < res_columns; j++) {
        double elem = 0;
        for (int k = 0; k < l; k++) elem += (A->matrix[i][k] * B->matrix[k][j]);
        result->matrix[i][j] = elem;
      }
    }
  }
  return error;
}
