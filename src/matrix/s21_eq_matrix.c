#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error = SUCCESS;
  if ((A->rows == B->rows) && (A->columns == B->columns) &&
      s21_is_correct_matrix(A) && s21_is_correct_matrix(B)) {
    for (int i = 0; (i < A->rows) && error; i++) {
      for (int j = 0; j < B->columns; j++) {
        double a = floor(A->matrix[i][j] * pow(10., 7.));
        double b = floor(B->matrix[i][j] * pow(10., 7.));
        if (a != b) {
          error = FAILURE;
          break;
        }
      }
    }
  } else {
    error = FAILURE;
  }
  return error;
}
