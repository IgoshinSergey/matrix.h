#include "s21_matrix_test.h"

START_TEST(eq_matrix1) {
  int rows = 2;
  int cols = 2;

  matrix_t m1 = {0};
  matrix_t m2 = {0};

  s21_create_matrix(rows, cols, &m1);
  s21_create_matrix(rows, cols, &m2);

  double x = 1;
  for (int i = 0; i < m1.rows; i++) {
    for (int j = 0; j < m1.columns; j++) {
      m1.matrix[i][j] = x++;
    }
  }

  x = 1;
  for (int i = 0; i < m2.rows; i++) {
    for (int j = 0; j < m2.columns; j++) {
      m2.matrix[i][j] = x++;
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&m1, &m2), 1);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(eq_matrix2) {
  int rows = 5;
  int cols = 4;

  matrix_t m1 = {0};
  matrix_t m2 = {0};

  s21_create_matrix(rows, cols, &m1);
  s21_create_matrix(rows, cols, &m2);

  double x = 1;
  for (int i = 0; i < m1.rows; i++) {
    for (int j = 0; j < m1.columns; j++) {
      m1.matrix[i][j] = x++;
    }
  }

  x = 1;
  for (int i = 0; i < m2.rows; i++) {
    for (int j = 0; j < m2.columns; j++) {
      m2.matrix[i][j] = x++;
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&m1, &m2), 1);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(eq_matrix3) {
  int rows = 4;
  int cols = 7;

  matrix_t m1 = {0};
  matrix_t m2 = {0};

  s21_create_matrix(rows, cols, &m1);
  s21_create_matrix(rows, cols, &m2);

  double x = 10;
  for (int i = 0; i < m1.rows; i++) {
    for (int j = 0; j < m1.columns; j++) {
      m1.matrix[i][j] = x++;
    }
  }

  x = 10;
  for (int i = 0; i < m2.rows; i++) {
    for (int j = 0; j < m2.columns; j++) {
      m2.matrix[i][j] = x++;
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&m1, &m2), 1);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(eq_matrix_error1) {
  int rows = 5;
  int cols = 4;

  matrix_t m1 = {0};
  matrix_t m2 = {0};

  s21_create_matrix(rows, cols, &m1);
  s21_create_matrix(cols, rows, &m2);

  double x = 1;
  for (int i = 0; i < m1.rows; i++) {
    for (int j = 0; j < m1.columns; j++) {
      m1.matrix[i][j] = x++;
    }
  }

  x = 1;
  for (int i = 0; i < m2.rows; i++) {
    for (int j = 0; j < m2.columns; j++) {
      m2.matrix[i][j] = x++;
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&m1, &m2), 0);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(eq_matrix_error2) {
  int rows = 5;
  int cols = 4;

  matrix_t m1 = {0};
  matrix_t m2 = {0};

  s21_create_matrix(rows, cols, &m1);
  s21_create_matrix(rows, cols, &m2);

  double x = 1;
  for (int i = 0; i < m1.rows; i++) {
    for (int j = 0; j < m1.columns; j++) {
      m1.matrix[i][j] = x++;
    }
  }

  x = 2;
  for (int i = 0; i < m2.rows; i++) {
    for (int j = 0; j < m2.columns; j++) {
      m2.matrix[i][j] = x++;
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&m1, &m2), 0);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST

Suite *suite_eq_matrix(void) {
  Suite *suite = suite_create("\033[30;43m S21_EQ_MATRIX \033[0m");

  TCase *tc = tcase_create("tcase_eq_matrix");
  tcase_add_test(tc, eq_matrix1);
  tcase_add_test(tc, eq_matrix2);
  tcase_add_test(tc, eq_matrix3);

  TCase *tc_error = tcase_create("tcase_error_tests");
  tcase_add_test(tc_error, eq_matrix_error1);
  tcase_add_test(tc_error, eq_matrix_error2);

  suite_add_tcase(suite, tc);
  suite_add_tcase(suite, tc_error);

  return suite;
}