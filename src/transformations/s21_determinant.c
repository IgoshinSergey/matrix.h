#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  error_code error = OK;
  if (!s21_is_correct_matrix(A)) {
    error = INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    error = ARITHMETIC_ERROR;
  } else {
    double det_A = s21_determinant_calculating(A);
    *result = det_A;
  }
  return error;
}
