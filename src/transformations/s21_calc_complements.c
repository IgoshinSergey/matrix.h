#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  error_code error = OK;
  if (!s21_is_correct_matrix(A)) {
    error = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    error = ARITHMETIC_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t m = {0};
        s21_create_matrix(A->rows - 1, A->columns - 1, &m);
        s21_get_new_matrix(i, j, A, &m);
        double minor = s21_determinant_calculating(&m);
        double calc_complement = pow(-1, i + j) * minor;
        result->matrix[i][j] = calc_complement;
        s21_remove_matrix(&m);
      }
    }
  }
  return error;
}
