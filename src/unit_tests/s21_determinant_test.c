#include "s21_matrix_test.h"

START_TEST(determinant1) {
  int size = 3;

  matrix_t m = {0};

  s21_create_matrix(size, size, &m);

  double x = 1;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      m.matrix[i][j] = x++;
    }
  }

  double res = 0;
  int code = s21_determinant(&m, &res);

  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant2) {
  int size = 3;

  matrix_t m = {0};

  s21_create_matrix(size, size, &m);

  double x = 1;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      m.matrix[i][j] = x++;
    }
    x = 1;
  }

  double res = 0;
  int code = s21_determinant(&m, &res);

  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant3) {
  int size = 2;

  matrix_t m = {0};

  s21_create_matrix(size, size, &m);

  m.matrix[0][0] = 6;
  m.matrix[0][1] = -2;

  m.matrix[1][0] = 12;
  m.matrix[1][1] = 21;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 150, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant4) {
  int size = 3;

  matrix_t m = {0};

  s21_create_matrix(size, size, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 3;
  m.matrix[0][2] = 1;

  m.matrix[1][0] = 7;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 1;

  m.matrix[2][0] = 9;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = 1;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, -32, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant5) {
  int size = 2;

  matrix_t m = {0};

  s21_create_matrix(size, size, &m);

  m.matrix[0][0] = -5;
  m.matrix[0][1] = -4;

  m.matrix[1][0] = -2;
  m.matrix[1][1] = -3;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 7, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant6) {
  int size = 1;

  matrix_t m = {0};

  s21_create_matrix(size, size, &m);

  m.matrix[0][0] = -5;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, -5, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_error1) {
  matrix_t m = {0};

  int size = -5;

  s21_create_matrix(size, size, &m);

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_int_eq(code, INCORRECT_MATRIX);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_error2) {
  matrix_t m = {0};

  int rows = 4;
  int cols = 5;

  s21_create_matrix(rows, cols, &m);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = 5;
    }
  }

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_int_eq(code, ARITHMETIC_ERROR);

  s21_remove_matrix(&m);
}
END_TEST

Suite *suite_determinant(void) {
  Suite *s = suite_create("\033[30;43m S21_DETERMINANT \033[0m");

  TCase *tc = tcase_create("tcase_determinant");
  tcase_add_test(tc, determinant1);
  tcase_add_test(tc, determinant2);
  tcase_add_test(tc, determinant3);
  tcase_add_test(tc, determinant4);
  tcase_add_test(tc, determinant5);
  tcase_add_test(tc, determinant6);

  TCase *tc_error = tcase_create("tcase_error_tests");
  tcase_add_test(tc_error, determinant_error1);
  tcase_add_test(tc_error, determinant_error2);

  suite_add_tcase(s, tc);
  suite_add_tcase(s, tc_error);

  return s;
}