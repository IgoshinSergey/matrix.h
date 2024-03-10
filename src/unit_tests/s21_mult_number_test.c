#include "s21_matrix_test.h"

START_TEST(mult_number_matrix1) {
  int rows = 1;
  int cols = 1;

  matrix_t m = {0};
  matrix_t check = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &check);

  double mult = 2.;
  double x = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = x++;
      check.matrix[i][j] = m.matrix[i][j] * mult;
    }
  }

  ck_assert_int_eq(s21_mult_number(&m, mult, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_matrix2) {
  int rows = 2;
  int cols = 2;

  matrix_t m = {0};
  matrix_t check = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &check);

  double mult = 25.134;
  double x = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = x++;
      check.matrix[i][j] = m.matrix[i][j] * mult;
    }
  }

  ck_assert_int_eq(s21_mult_number(&m, mult, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_matrix3) {
  int rows = 3;
  int cols = 3;

  matrix_t m = {0};
  matrix_t check = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &check);

  double mult = 1.1111;
  double x = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = x++;
      check.matrix[i][j] = m.matrix[i][j] * mult;
    }
  }

  ck_assert_int_eq(s21_mult_number(&m, mult, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_matrix4) {
  int rows = 4;
  int cols = 4;

  matrix_t m = {0};
  matrix_t check = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &check);

  double mult = 1456.23456;
  double x = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = x++;
      check.matrix[i][j] = m.matrix[i][j] * mult;
    }
  }

  ck_assert_int_eq(s21_mult_number(&m, mult, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_matrix5) {
  int rows = 5;
  int cols = 3;

  matrix_t m = {0};
  matrix_t check = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &check);

  double mult = 2.;
  double x = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = x++;
      check.matrix[i][j] = m.matrix[i][j] * mult;
    }
  }

  ck_assert_int_eq(s21_mult_number(&m, mult, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_error) {
  int rows = -5;
  int cols = -5;
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(rows, cols, &m);

  double mult_number = 1.5;
  ck_assert_int_eq(s21_mult_number(&m, mult_number, &res), INCORRECT_MATRIX);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

Suite *suite_mult_number(void) {
  Suite *suite = suite_create("\033[30;43m S21_MULT_NUMBER \033[0m");

  TCase *tc = tcase_create("tcase_mult_number");
  tcase_add_test(tc, mult_number_matrix1);
  tcase_add_test(tc, mult_number_matrix2);
  tcase_add_test(tc, mult_number_matrix3);
  tcase_add_test(tc, mult_number_matrix4);
  tcase_add_test(tc, mult_number_matrix5);

  TCase *tc_error = tcase_create("tcase_error_tests");
  tcase_add_test(tc_error, mult_number_error);

  suite_add_tcase(suite, tc);
  suite_add_tcase(suite, tc_error);

  return suite;
}