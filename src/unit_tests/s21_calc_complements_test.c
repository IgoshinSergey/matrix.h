#include "s21_matrix_test.h"

START_TEST(calc_complements1) {
  int rows = 3;
  int cols = 3;

  matrix_t m = {0};
  matrix_t check = {0};
  matrix_t result = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &check);

  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;
  m.matrix[1][0] = 0;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 2;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = 2;
  m.matrix[2][2] = 1;

  check.matrix[0][0] = 0;
  check.matrix[0][1] = 10;
  check.matrix[0][2] = -20;
  check.matrix[1][0] = 4;
  check.matrix[1][1] = -14;
  check.matrix[1][2] = 8;
  check.matrix[2][0] = -8;
  check.matrix[2][1] = -2;
  check.matrix[2][2] = 4;

  int code = s21_calc_complements(&m, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), 1);

  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(calc_complements2) {
  int rows = 2;
  int cols = 2;

  matrix_t m = {0};
  matrix_t check = {0};
  matrix_t result = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &check);

  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[1][0] = 3;
  m.matrix[1][1] = 4;

  check.matrix[0][0] = 4;
  check.matrix[0][1] = -3;
  check.matrix[1][0] = -2;
  check.matrix[1][1] = 1;

  int code = s21_calc_complements(&m, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), 1);

  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(calc_complements_error1) {
  int rows = -1;
  int cols = -2;

  matrix_t m = {0};
  matrix_t result = {0};

  s21_create_matrix(rows, cols, &m);

  int code = s21_calc_complements(&m, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(calc_complements_error2) {
  int rows = 3;
  int cols = 4;

  matrix_t m = {0};
  matrix_t result = {0};

  s21_create_matrix(rows, cols, &m);

  int code = s21_calc_complements(&m, &result);
  ck_assert_int_eq(code, ARITHMETIC_ERROR);

  s21_remove_matrix(&m);
}
END_TEST

Suite *suite_calc_complements(void) {
  Suite *s = suite_create("\033[30;43m S21_CALC_COMPLEMETS \033[0m");

  TCase *tc = tcase_create("tcase_calc_complements");
  tcase_add_test(tc, calc_complements1);
  tcase_add_test(tc, calc_complements2);

  TCase *tc_error = tcase_create("tcase_error_tests");
  tcase_add_test(tc, calc_complements_error1);
  tcase_add_test(tc, calc_complements_error2);

  suite_add_tcase(s, tc);
  suite_add_tcase(s, tc_error);

  return s;
}