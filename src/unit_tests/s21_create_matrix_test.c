#include "s21_matrix_test.h"

START_TEST(create_matrix1) {
  int rows = 1;
  int cols = -1;
  matrix_t m = {0};
  int res = s21_create_matrix(rows, cols, &m);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

Suite *suite_create_matrix(void) {
  Suite *suite = suite_create("\033[30;43m S21_CREATE_MATRIX \033[0m");

  TCase *tc = tcase_create("tcase_transpose");
  tcase_add_test(tc, create_matrix1);

  suite_add_tcase(suite, tc);
  return suite;
}