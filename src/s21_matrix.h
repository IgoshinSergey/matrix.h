#ifndef C6_S21_DECIMAL_1_S21_DECIMAL_H_
#define C6_S21_DECIMAL_1_S21_DECIMAL_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum { OK, INCORRECT_MATRIX, ARITHMETIC_ERROR } error_code;

#define SUCCESS 1
#define FAILURE 0

int s21_create_matrix(int rows, int columns, matrix_t *result);

void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// вспомогательные функции
int s21_is_correct_matrix(matrix_t *A);

double s21_determinant_calculating(matrix_t *A);

void s21_get_new_matrix(int row, int column, matrix_t *src, matrix_t *dest);

#endif  // C6_S21_DECIMAL_1_S21_DECIMAL_H_
