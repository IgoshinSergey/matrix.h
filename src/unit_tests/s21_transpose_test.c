#include "s21_matrix_test.h"

START_TEST(transpose_matrix1) {
  int rows = 3;
  int cols = 5;
  matrix_t m = {0};
  matrix_t check = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(cols, rows, &check);

  double x = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = x++;
      check.matrix[j][i] = m.matrix[i][j];
    }
  }

  ck_assert_int_eq(s21_transpose(&m, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transpose_matrix2) {
  int rows = 4;
  int cols = 2;
  matrix_t m = {0};
  matrix_t check = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(cols, rows, &check);

  double x = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = x++;
      check.matrix[j][i] = m.matrix[i][j];
    }
  }

  ck_assert_int_eq(s21_transpose(&m, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transpose_matrix3) {
  int rows = 6;
  int cols = 7;
  matrix_t m = {0};
  matrix_t check = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(cols, rows, &check);

  double x = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = x++;
      check.matrix[j][i] = m.matrix[i][j];
    }
  }

  ck_assert_int_eq(s21_transpose(&m, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transpose_matrix4) {
  int rows = 7;
  int cols = 3;
  matrix_t m = {0};
  matrix_t check = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(cols, rows, &check);

  double x = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = x++;
      check.matrix[j][i] = m.matrix[i][j];
    }
  }

  ck_assert_int_eq(s21_transpose(&m, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transpose_matrix5) {
  int rows = 5;
  int cols = 9;
  matrix_t m = {0};
  matrix_t check = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(cols, rows, &check);

  double x = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = x++;
      check.matrix[j][i] = m.matrix[i][j];
    }
  }

  ck_assert_int_eq(s21_transpose(&m, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transpose_matrix_error) {
  int rows = -5;
  int cols = 5;

  matrix_t m = {0};
  matrix_t check = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(cols, rows, &check);

  ck_assert_int_eq(s21_transpose(&m, &res), INCORRECT_MATRIX);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

Suite *suite_transpose(void) {
  Suite *suite = suite_create("\033[30;43m S21_TRANSPOSE \033[0m");

  TCase *tc = tcase_create("tcase_transpose");
  tcase_add_test(tc, transpose_matrix1);
  tcase_add_test(tc, transpose_matrix2);
  tcase_add_test(tc, transpose_matrix3);
  tcase_add_test(tc, transpose_matrix4);
  tcase_add_test(tc, transpose_matrix5);

  TCase *tc_error = tcase_create("tcase_error_tests");
  tcase_add_test(tc_error, transpose_matrix_error);

  suite_add_tcase(suite, tc);
  suite_add_tcase(suite, tc_error);

  return suite;
}