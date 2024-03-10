#ifndef C6_S21_DECIMAL_1_UNIT_TESTS_S21_MATRIX_TEST_H_
#define C6_S21_DECIMAL_1_UNIT_TESTS_S21_MATRIX_TEST_H_

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "../s21_matrix.h"

Suite *suite_sum_matrix(void);
Suite *suite_sub_matrix(void);
Suite *suite_mult_number(void);
Suite *suite_mult_matrix(void);
Suite *suite_transpose(void);
Suite *suite_eq_matrix(void);
Suite *suite_determinant(void);
Suite *suite_calc_complements(void);
Suite *suite_inverse_matrix(void);
Suite *suite_create_matrix(void);

#endif  // C6_S21_DECIMAL_1_UNIT_TESTS_S21_MATRIX_TEST_H_