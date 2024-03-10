#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  error_code error = OK;
  if (!s21_is_correct_matrix(A)) {
    error = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    error = ARITHMETIC_ERROR;
  } else {
    double det_a = s21_determinant_calculating(A);
    if (det_a == 0) {
      error = ARITHMETIC_ERROR;
    } else {
      matrix_t calc_comp = {0};
      matrix_t calc_comp_t = {0};

      s21_calc_complements(A, &calc_comp);
      s21_transpose(&calc_comp, &calc_comp_t);
      s21_mult_number(&calc_comp_t, 1 / det_a, result);

      s21_remove_matrix(&calc_comp);
      s21_remove_matrix(&calc_comp_t);
    }
  }
  return error;
}
