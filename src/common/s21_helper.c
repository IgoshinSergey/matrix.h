#include "../s21_matrix.h"

int s21_is_correct_matrix(matrix_t *A) {
  int error = SUCCESS;
  if (A->columns < 1 || A->rows < 1 || !A->matrix) {
    error = FAILURE;
  }
  return error;
}

double s21_determinant_calculating(matrix_t *A) {
  double det_A = 0;
  if (A->rows == 1) {
    det_A = A->matrix[0][0];
  } else if (A->rows == 2) {
    det_A =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  } else {
    for (int j = 0; j < A->columns; j++) {
      matrix_t B = {0};
      s21_create_matrix(A->rows - 1, A->columns - 1, &B);
      s21_get_new_matrix(0, j, A, &B);
      if (j % 2 == 0) {
        det_A += A->matrix[0][j] * s21_determinant_calculating(&B);
      } else {
        det_A -= A->matrix[0][j] * s21_determinant_calculating(&B);
      }
      s21_remove_matrix(&B);
    }
  }
  return det_A;
}

void s21_get_new_matrix(int row, int column, matrix_t *src, matrix_t *dest) {
  if (s21_is_correct_matrix(src) && s21_is_correct_matrix(dest)) {
    int tmp_rows = 0;
    for (int i = 0; i < src->rows; i++) {
      if (i == row) continue;
      int tmp_columns = 0;
      for (int j = 0; j < src->columns; j++) {
        if (j == column) continue;
        dest->matrix[tmp_rows][tmp_columns] = src->matrix[i][j];
        tmp_columns++;
      }
      tmp_rows++;
    }
  }
}
