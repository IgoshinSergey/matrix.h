#include "s21_matrix_test.h"

void run_testcase(Suite *testcase) {
  printf("\n");
  SRunner *suite_runner = srunner_create(testcase);
  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  srunner_free(suite_runner);
}

void run_tests(void) {
  printf("\n\033[30;43m -=S21_MATRIX_TESTS=- \033[0m\n");
  Suite *case_list[] = {suite_sum_matrix(),
                        suite_sub_matrix(),
                        suite_mult_number(),
                        suite_mult_matrix(),
                        suite_transpose(),
                        suite_eq_matrix(),
                        suite_determinant(),
                        suite_calc_complements(),
                        suite_inverse_matrix(),
                        suite_create_matrix(),
                        NULL};
  for (Suite **cur_test_case = case_list; *cur_test_case != NULL;
       cur_test_case++) {
    run_testcase(*cur_test_case);
  }
}

int main() {
  run_tests();
  return 0;
}
