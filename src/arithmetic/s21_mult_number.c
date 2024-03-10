#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  error_code error = OK;
  if (!s21_is_correct_matrix(A)) {
    error = INCORRECT_MATRIX;
  } else {
    error = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; (i < A->rows) && (error == OK); i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return error;
}
