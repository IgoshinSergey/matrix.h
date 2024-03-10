#include "s21_matrix_test.h"

START_TEST(mult_matrix1) {
  int rows = 1;
  int cols = 2;

  matrix_t m = {0};
  matrix_t mult = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(cols, rows, &mult);

  double x = 1;
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = x++;
    }
  }

  x = 1;
  for (int i = 0; i < mult.rows; i++) {
    for (int j = 0; j < mult.columns; j++) {
      mult.matrix[i][j] = x++;
    }
  }

  ck_assert_int_eq(s21_mult_matrix(&m, &mult, &res), OK);
  ck_assert_int_eq(res.matrix[0][0], 5);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mult);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix2) {
  int rows = 3;
  int cols = 2;

  matrix_t m = {0};
  matrix_t mult = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(cols, rows, &mult);

  double x = 1;
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = x++;
    }
  }

  x = 1;
  for (int i = 0; i < mult.rows; i++) {
    for (int j = 0; j < mult.columns; j++) {
      mult.matrix[i][j] = x++;
    }
  }

  ck_assert_int_eq(s21_mult_matrix(&m, &mult, &res), OK);
  ck_assert_int_eq(res.matrix[0][0], 9);
  ck_assert_int_eq(res.matrix[0][1], 12);
  ck_assert_int_eq(res.matrix[0][2], 15);
  ck_assert_int_eq(res.matrix[1][0], 19);
  ck_assert_int_eq(res.matrix[1][1], 26);
  ck_assert_int_eq(res.matrix[1][2], 33);
  ck_assert_int_eq(res.matrix[2][0], 29);
  ck_assert_int_eq(res.matrix[2][1], 40);
  ck_assert_int_eq(res.matrix[2][2], 51);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mult);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix3) {
  int rows = 2;
  int cols = 2;

  matrix_t m = {0};
  matrix_t mult = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(cols, rows, &mult);

  double x = 1;
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.columns; j++) {
      m.matrix[i][j] = x++;
    }
  }

  x = 1;
  for (int i = 0; i < mult.rows; i++) {
    for (int j = 0; j < mult.columns; j++) {
      mult.matrix[i][j] = x++;
    }
  }

  ck_assert_int_eq(s21_mult_matrix(&m, &mult, &res), OK);
  ck_assert_int_eq(res.matrix[0][0], 7);
  ck_assert_int_eq(res.matrix[0][1], 10);
  ck_assert_int_eq(res.matrix[1][0], 15);
  ck_assert_int_eq(res.matrix[1][1], 22);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mult);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix_error1) {
  int rows = -1;
  int cols = -2;

  matrix_t m = {0};
  matrix_t mult = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(cols, rows, &mult);

  ck_assert_int_eq(s21_mult_matrix(&m, &mult, &res), INCORRECT_MATRIX);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mult);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix_error2) {
  int rows = 4;
  int cols = 3;

  matrix_t m = {0};
  matrix_t mult = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &mult);

  ck_assert_int_eq(s21_mult_matrix(&m, &mult, &res), ARITHMETIC_ERROR);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mult);
  s21_remove_matrix(&res);
}
END_TEST

Suite *suite_mult_matrix(void) {
  Suite *suite = suite_create("\033[30;43m S21_MULT_MATRIX \033[0m");

  TCase *tc = tcase_create("tcase_mult_matrix");
  tcase_add_test(tc, mult_matrix1);
  tcase_add_test(tc, mult_matrix2);
  tcase_add_test(tc, mult_matrix3);

  TCase *tc_error = tcase_create("tcase_error_tests");
  tcase_add_test(tc_error, mult_matrix_error1);
  tcase_add_test(tc_error, mult_matrix_error2);

  suite_add_tcase(suite, tc);
  suite_add_tcase(suite, tc_error);

  return suite;
}