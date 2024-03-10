#include "s21_matrix_test.h"

START_TEST(inverse1) {
  int rows = 3;
  int cols = 3;

  matrix_t m = {0};
  matrix_t check = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &check);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  check.matrix[0][0] = 1;
  check.matrix[0][1] = -1;
  check.matrix[0][2] = 1;
  check.matrix[1][0] = -38;
  check.matrix[1][1] = 41;
  check.matrix[1][2] = -34;
  check.matrix[2][0] = 27;
  check.matrix[2][1] = -29;
  check.matrix[2][2] = 24;

  ck_assert_int_eq(s21_inverse_matrix(&m, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&res, &check), 1);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(inverse2) {
  int rows = 2;
  int cols = 2;

  matrix_t m;
  matrix_t check;
  matrix_t res;

  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &check);

  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 7;

  ck_assert_int_eq(s21_inverse_matrix(&m, &res), OK);
  ck_assert_double_eq_tol(res.matrix[0][0], -1.4, 1);
  ck_assert_double_eq_tol(res.matrix[0][1], 0.4, 1);
  ck_assert_double_eq_tol(res.matrix[1][0], 1.2, 1);
  ck_assert_double_eq_tol(res.matrix[1][1], -0.2, 1);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(inverse_error1) {
  int rows = 3;
  int cols = 3;

  matrix_t m;
  matrix_t res;

  s21_create_matrix(rows, cols, &m);

  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;
  m.matrix[1][0] = 4;
  m.matrix[1][1] = 5;
  m.matrix[1][2] = 6;
  m.matrix[2][0] = 7;
  m.matrix[2][1] = 8;
  m.matrix[2][2] = 9;

  ck_assert_int_eq(s21_inverse_matrix(&m, &res), ARITHMETIC_ERROR);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_error2) {
  int rows = 3;
  int cols = 2;

  matrix_t m = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  ck_assert_int_eq(s21_inverse_matrix(&m, &res), ARITHMETIC_ERROR);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_error3) {
  int rows = -3;
  int cols = -2;

  matrix_t m = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &m);
  ck_assert_int_eq(s21_inverse_matrix(&m, &res), INCORRECT_MATRIX);

  s21_remove_matrix(&m);
}
END_TEST

// START_TEST(test_one_by_one) {
//   matrix_t m = {0};
//   matrix_t result = {0};
//   int codec = s21_create_matrix(1, 1, &m);
//   if (codec) {
//     m.matrix[0][0] = 1431.12312331;
//     int code = s21_inverse_matrix(&m, &result);
//     ck_assert_int_eq(result.matrix[0][0] == (1.0 / m.matrix[0][0]), 1);
//     ck_assert_int_eq(code, OK);
//     s21_remove_matrix(&m);
//     s21_remove_matrix(&result);
//   }
// }
// END_TEST

// START_TEST(test_zero_det) {
//   matrix_t m = {0};
//   matrix_t result = {0};
//   int codec = s21_create_matrix(1, 1, &m);
//   if (codec) {
//     int code = s21_inverse_matrix(&m, &result);
//     ck_assert_int_eq(code, ARITHMETIC_ERROR);
//     s21_remove_matrix(&m);
//   }
// }
// END_TEST

// START_TEST(test_incorrect) {
//   matrix_t m = {0};
//   matrix_t result = {0};
//   int code = s21_inverse_matrix(&m, &result);
//   ck_assert_int_eq(code, INCORRECT_MATRIX);
// }
// END_TEST

// START_TEST(determinant) {
//   const int size = 2;
//   matrix_t m = {0};
//   s21_create_matrix(size, size, &m);
//   m.matrix[0][0] = 1;
//   m.matrix[0][1] = 1;
//   m.matrix[1][0] = 1;
//   m.matrix[1][1] = 1;

//   matrix_t result = {0};
//   int code = s21_inverse_matrix(&m, &result);
//   ck_assert_int_eq(code, ARITHMETIC_ERROR);

//   s21_remove_matrix(&m);
// }
// END_TEST

// START_TEST(test_not_sqare) {
//   matrix_t m = {0};
//   matrix_t result = {0};
//   int codec = s21_create_matrix(1, 4, &m);
//   if (codec) {
//     int code = s21_inverse_matrix(&m, &result);
//     ck_assert_int_eq(code, ARITHMETIC_ERROR);
//     s21_remove_matrix(&m);
//   }
// }
// END_TEST

// START_TEST(test_normal) {
//   matrix_t m = {0};
//   matrix_t expected = {0};
//   int codec1, codec2;
//   codec1 = s21_create_matrix(3, 3, &m);
//   if (codec1) codec2 = s21_create_matrix(3, 3, &expected);

//   if (codec1 && codec2) {
//     m.matrix[0][0] = 2;
//     m.matrix[0][1] = 5;
//     m.matrix[0][2] = 7;

//     m.matrix[1][0] = 6;
//     m.matrix[1][1] = 3;
//     m.matrix[1][2] = 4;

//     m.matrix[2][0] = 5;
//     m.matrix[2][1] = -2;
//     m.matrix[2][2] = -3;

//     expected.matrix[0][0] = 1;
//     expected.matrix[0][1] = -1;
//     expected.matrix[0][2] = 1;

//     expected.matrix[1][0] = -38;
//     expected.matrix[1][1] = 41;
//     expected.matrix[1][2] = -34;

//     expected.matrix[2][0] = 27;
//     expected.matrix[2][1] = -29;
//     expected.matrix[2][2] = 24;
//     matrix_t result = {0};
//     int code = s21_inverse_matrix(&m, &result);

//     ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
//     ck_assert_int_eq(code, OK);

//     s21_remove_matrix(&m);
//     s21_remove_matrix(&result);
//     s21_remove_matrix(&expected);
//   }
// }
// END_TEST

// START_TEST(inverse) {
//   /* const int size = rand() % 100 + 1; */
//   const int size = 3;
//   matrix_t m = {0};
//   s21_create_matrix(size, size, &m);

//   m.matrix[0][0] = 2;
//   m.matrix[0][1] = 5;
//   m.matrix[0][2] = 7;
//   m.matrix[1][0] = 6;
//   m.matrix[1][1] = 3;
//   m.matrix[1][2] = 4;
//   m.matrix[2][0] = 5;
//   m.matrix[2][1] = -2;
//   m.matrix[2][2] = -3;

//   matrix_t res = {0};
//   s21_inverse_matrix(&m, &res);

//   matrix_t expected = {0};
//   s21_create_matrix(size, size, &expected);
//   expected.matrix[0][0] = 1;
//   expected.matrix[0][1] = -1;
//   expected.matrix[0][2] = 1;
//   expected.matrix[1][0] = -38;
//   expected.matrix[1][1] = 41;
//   expected.matrix[1][2] = -34;
//   expected.matrix[2][0] = 27;
//   expected.matrix[2][1] = -29;
//   expected.matrix[2][2] = 24;

//   ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);

//   s21_remove_matrix(&expected);
//   s21_remove_matrix(&res);
//   s21_remove_matrix(&m);
// }
// END_TEST

Suite *suite_inverse_matrix(void) {
  Suite *s = suite_create("\033[30;43m S21_INVERSE_MATRIX \033[0m");

  TCase *tc = tcase_create("tcase_inverse_matrix");
  tcase_add_test(tc, inverse1);
  tcase_add_test(tc, inverse2);

  TCase *tc_error = tcase_create("tcase_error_tests");
  tcase_add_test(tc, inverse_error1);
  tcase_add_test(tc, inverse_error2);
  tcase_add_test(tc, inverse_error3);
  //   tcase_add_test(tc, test_not_sqare);
  //   tcase_add_test(tc, test_zero_det);
  //   tcase_add_test(tc, test_incorrect);
  //   tcase_add_test(tc, test_one_by_one);

  suite_add_tcase(s, tc);
  suite_add_tcase(s, tc_error);
  return s;
}