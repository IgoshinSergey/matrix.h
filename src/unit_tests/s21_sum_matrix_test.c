#include "s21_matrix_test.h"

START_TEST(sum_matrix1) {
  int rows = 1;
  int cols = 1;

  matrix_t m = {0};
  matrix_t sum = {0};
  matrix_t check = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &sum);
  s21_create_matrix(rows, cols, &check);

  double x = 1.;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = x;
      sum.matrix[i][j] = x++;
      check.matrix[i][j] = m.matrix[i][j] + sum.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&m, &sum, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&sum);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(sum_matrix2) {
  int rows = 3;
  int cols = 3;

  matrix_t m = {0};
  matrix_t sum = {0};
  matrix_t check = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &sum);
  s21_create_matrix(rows, cols, &check);

  double x = 1.;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = x;
      sum.matrix[i][j] = x++;
      check.matrix[i][j] = m.matrix[i][j] + sum.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&m, &sum, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&sum);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(sum_matrix3) {
  int rows = 2;
  int cols = 5;

  matrix_t m = {0};
  matrix_t sum = {0};
  matrix_t check = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &sum);
  s21_create_matrix(rows, cols, &check);

  double x = 1.;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = x;
      sum.matrix[i][j] = x++;
      check.matrix[i][j] = m.matrix[i][j] + sum.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&m, &sum, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&sum);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(sum_matrix_error1) {
  int rows = 1;
  int cols = 2;
  int rows1 = 2;
  int cols1 = 3;

  matrix_t m = {0};
  matrix_t sum = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows1, cols1, &sum);

  double x = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = x++;
    }
  }

  x = 1;
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols1; j++) {
      sum.matrix[i][j] = x++;
    }
  }

  ck_assert_int_eq(s21_sum_matrix(&m, &sum, &res), ARITHMETIC_ERROR);
  s21_remove_matrix(&m);
  s21_remove_matrix(&sum);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sum_matrix_error2) {
  int rows = -3;
  int cols = -2;

  matrix_t m = {0};
  matrix_t sum = {0};
  matrix_t check = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &sum);
  s21_create_matrix(rows, cols, &check);

  ck_assert_int_eq(s21_sum_matrix(&m, &sum, &res), INCORRECT_MATRIX);

  s21_remove_matrix(&m);
  s21_remove_matrix(&sum);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

Suite *suite_sum_matrix(void) {
  Suite *suite = suite_create("\033[30;43m S21_SUM_MATRIX \033[0m");

  TCase *tc = tcase_create("tcase_sum_matrix");
  tcase_add_test(tc, sum_matrix1);
  tcase_add_test(tc, sum_matrix2);
  tcase_add_test(tc, sum_matrix3);

  TCase *tc_error = tcase_create("tcase_error_tests");
  tcase_add_test(tc_error, sum_matrix_error1);
  tcase_add_test(tc_error, sum_matrix_error2);

  suite_add_tcase(suite, tc);
  suite_add_tcase(suite, tc_error);

  return suite;
}