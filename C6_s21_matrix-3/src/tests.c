#include <check.h>

#include "s21_matrix.h"

START_TEST(create_matrix) {
  matrix_t result;
  int res_creat = s21_create_matrix(3, 3, &result);
  ck_assert_int_eq(res_creat, OK);
  s21_remove_matrix(&result);

  int res_creat1 = s21_create_matrix(3, 5, &result);
  ck_assert_int_eq(res_creat1, OK);
  s21_remove_matrix(&result);

  int res_creat2 = s21_create_matrix(0, 0, &result);
  ck_assert_int_eq(res_creat2, ERROR);

  int res_creat3 = s21_create_matrix(-1, -3, &result);
  ck_assert_int_eq(res_creat3, ERROR);

  int res_creat4 = s21_create_matrix(3, 3, NULL);
  ck_assert_int_eq(res_creat4, ERROR);

  int res_creat5 = s21_create_matrix(3, -3, &result);
  ck_assert_int_eq(res_creat5, ERROR);

  int res_creat6 = s21_create_matrix(-3, 3, &result);
  ck_assert_int_eq(res_creat6, ERROR);
}
END_TEST

START_TEST(eq_matrix) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[1][0] = 1;
  B.matrix[1][1] = 2;
  B.matrix[2][0] = 3;
  B.matrix[2][1] = 4;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  matrix_t C;
  matrix_t D;
  s21_create_matrix(2, 2, &C);
  C.matrix[0][0] = 1;
  C.matrix[0][1] = 5;
  C.matrix[1][0] = 2;
  C.matrix[1][1] = 3;
  s21_create_matrix(3, 2, &D);
  D.matrix[0][0] = 1;
  D.matrix[0][1] = -1;
  D.matrix[1][0] = 1;
  D.matrix[1][1] = 2;
  D.matrix[2][0] = 3;
  D.matrix[2][1] = 4;
  ck_assert_int_eq(s21_eq_matrix(&C, &D), FAILURE);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);

  matrix_t E;
  matrix_t F;
  s21_create_matrix(3, 2, &E);
  E.matrix[0][0] = 1;
  E.matrix[0][1] = -1;
  E.matrix[1][0] = 1;
  E.matrix[1][1] = 2;
  E.matrix[2][0] = 3;
  E.matrix[2][1] = 4;
  s21_create_matrix(2, 2, &F);
  F.matrix[0][0] = 1;
  F.matrix[0][1] = 5;
  F.matrix[1][0] = 2;
  F.matrix[1][1] = 3;
  ck_assert_int_eq(s21_eq_matrix(&E, NULL), FAILURE);
  ck_assert_int_eq(s21_eq_matrix(NULL, &F), FAILURE);
  s21_remove_matrix(&E);
  s21_remove_matrix(&F);

  matrix_t G;
  matrix_t H;
  s21_create_matrix(2, 2, &G);
  G.matrix[0][0] = 1;
  G.matrix[0][1] = 4;
  G.matrix[1][0] = 2;
  G.matrix[1][1] = 5;
  s21_create_matrix(2, 2, &H);
  H.matrix[0][0] = 1;
  H.matrix[0][1] = 4;
  H.matrix[1][0] = 2;
  H.matrix[1][1] = 5;
  ck_assert_int_eq(s21_eq_matrix(&G, &H), SUCCESS);
  s21_remove_matrix(&G);
  s21_remove_matrix(&H);

  matrix_t I;
  matrix_t K;
  s21_create_matrix(3, 2, &I);
  I.matrix[0][0] = 1.159357;
  I.matrix[0][1] = 4.789123;
  I.matrix[1][0] = 2.456123;
  I.matrix[1][1] = 5.963852;
  I.matrix[2][0] = 3.852741;
  I.matrix[2][1] = 6.852456;
  s21_create_matrix(3, 2, &K);
  K.matrix[0][0] = 1.159357;
  K.matrix[0][1] = 4.789123;
  K.matrix[1][0] = 2.456123;
  K.matrix[1][1] = 5.963852;
  K.matrix[2][0] = 3.852741;
  K.matrix[2][1] = 6.852456;
  ck_assert_int_eq(s21_eq_matrix(&I, &K), SUCCESS);
  s21_remove_matrix(&I);
  s21_remove_matrix(&K);
}
END_TEST

START_TEST(sum_matrix) {
  matrix_t A;
  matrix_t B;
  matrix_t resAB;
  matrix_t correctResult;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 7;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 1;
  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 4;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 5;
  B.matrix[2][0] = 3;
  B.matrix[2][1] = 6;
  s21_create_matrix(3, 2, &correctResult);
  correctResult.matrix[0][0] = 8;
  correctResult.matrix[0][1] = 8;
  correctResult.matrix[1][0] = 8;
  correctResult.matrix[1][1] = 8;
  correctResult.matrix[2][0] = 5;
  correctResult.matrix[2][1] = 7;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &resAB), OK);
  ck_assert_int_eq(s21_eq_matrix(&resAB, &correctResult), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&resAB);
  s21_remove_matrix(&correctResult);

  matrix_t C;
  matrix_t D;
  matrix_t resCD;
  s21_create_matrix(2, 2, &C);
  s21_create_matrix(3, 2, &D);
  ck_assert_int_eq(s21_sum_matrix(&C, &D, &resCD), CALC_ERROR);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);

  matrix_t E;
  matrix_t F;
  matrix_t resEF;
  s21_create_matrix(2, 2, &E);
  s21_create_matrix(2, 2, &F);
  ck_assert_int_eq(s21_sum_matrix(&E, &F, NULL), ERROR);
  ck_assert_int_eq(s21_sum_matrix(NULL, &F, &resEF), ERROR);
  ck_assert_int_eq(s21_sum_matrix(&E, NULL, &resEF), ERROR);
  s21_remove_matrix(&E);
  s21_remove_matrix(&F);

  matrix_t G;
  matrix_t H;
  matrix_t resGH;
  s21_create_matrix(2, 2, &G);
  G.matrix[0][0] = 1;
  G.matrix[0][1] = 4;
  G.matrix[1][0] = 2;
  G.matrix[1][1] = 5;
  s21_create_matrix(2, 2, &H);
  H.matrix[0][0] = 3;
  H.matrix[0][1] = 7;
  H.matrix[1][0] = 6;
  H.matrix[1][1] = 8;
  s21_create_matrix(2, 2, &correctResult);
  correctResult.matrix[0][0] = 4;
  correctResult.matrix[0][1] = 11;
  correctResult.matrix[1][0] = 8;
  correctResult.matrix[1][1] = 13;
  ck_assert_int_eq(s21_sum_matrix(&G, &H, &resGH), OK);
  ck_assert_int_eq(s21_eq_matrix(&resGH, &correctResult), SUCCESS);
  s21_remove_matrix(&G);
  s21_remove_matrix(&H);
  s21_remove_matrix(&resGH);
  s21_remove_matrix(&correctResult);

  matrix_t I;
  matrix_t K;
  matrix_t resIK;
  s21_create_matrix(1, 2, &I);
  I.matrix[0][0] = 1.159357;
  I.matrix[0][1] = 4.789123;
  s21_create_matrix(2, 3, &K);
  K.matrix[0][0] = 1.159357;
  K.matrix[0][1] = 4.789123;
  K.matrix[0][2] = 2.456123;
  K.matrix[1][0] = 5.963852;
  K.matrix[1][1] = 3.852741;
  K.matrix[1][2] = 6.852456;
  ck_assert_int_eq(s21_sum_matrix(&I, &K, &resIK), CALC_ERROR);
  s21_remove_matrix(&I);
  s21_remove_matrix(&K);
}
END_TEST

START_TEST(sub_matrix) {
  matrix_t correctResult;
  matrix_t A;
  matrix_t B;
  matrix_t resAB;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 7;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 1;
  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 4;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 5;
  B.matrix[2][0] = 3;
  B.matrix[2][1] = 6;
  s21_create_matrix(3, 2, &correctResult);
  correctResult.matrix[0][0] = 6;
  correctResult.matrix[0][1] = 0;
  correctResult.matrix[1][0] = 4;
  correctResult.matrix[1][1] = -2;
  correctResult.matrix[2][0] = -1;
  correctResult.matrix[2][1] = -5;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &resAB), OK);
  ck_assert_int_eq(s21_eq_matrix(&resAB, &correctResult), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&resAB);
  s21_remove_matrix(&correctResult);

  matrix_t C;
  matrix_t D;
  matrix_t resCD;
  s21_create_matrix(2, 2, &C);
  s21_create_matrix(3, 2, &D);
  ck_assert_int_eq(s21_sub_matrix(&C, &D, &resCD), CALC_ERROR);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);

  matrix_t E;
  matrix_t F;
  matrix_t resEF;
  s21_create_matrix(2, 2, &E);
  s21_create_matrix(2, 2, &F);
  ck_assert_int_eq(s21_sub_matrix(&E, &F, NULL), ERROR);
  ck_assert_int_eq(s21_sub_matrix(NULL, &F, &resEF), ERROR);
  ck_assert_int_eq(s21_sub_matrix(&E, NULL, &resEF), ERROR);
  s21_remove_matrix(&E);
  s21_remove_matrix(&F);

  matrix_t G;
  matrix_t H;
  matrix_t resGH;
  s21_create_matrix(2, 2, &G);
  G.matrix[0][0] = 1;
  G.matrix[0][1] = 4;
  G.matrix[1][0] = 2;
  G.matrix[1][1] = 5;
  s21_create_matrix(2, 2, &H);
  H.matrix[0][0] = 3;
  H.matrix[0][1] = 7;
  H.matrix[1][0] = 6;
  H.matrix[1][1] = 8;
  s21_create_matrix(2, 2, &correctResult);
  correctResult.matrix[0][0] = -2;
  correctResult.matrix[0][1] = -3;
  correctResult.matrix[1][0] = -4;
  correctResult.matrix[1][1] = -3;
  ck_assert_int_eq(s21_sub_matrix(&G, &H, &resGH), OK);
  ck_assert_int_eq(s21_eq_matrix(&resGH, &correctResult), SUCCESS);
  s21_remove_matrix(&G);
  s21_remove_matrix(&H);
  s21_remove_matrix(&resGH);
  s21_remove_matrix(&correctResult);

  matrix_t I;
  matrix_t K;
  matrix_t resIK;
  s21_create_matrix(1, 2, &I);
  I.matrix[0][0] = 1.159357;
  I.matrix[0][1] = 4.789123;
  s21_create_matrix(2, 3, &K);
  K.matrix[0][0] = 1.159357;
  K.matrix[0][1] = 4.789123;
  K.matrix[0][2] = 2.456123;
  K.matrix[1][0] = 5.963852;
  K.matrix[1][1] = 3.852741;
  K.matrix[1][2] = 6.852456;
  ck_assert_int_eq(s21_sub_matrix(&I, &K, &resIK), CALC_ERROR);
  s21_remove_matrix(&I);
  s21_remove_matrix(&K);
}
END_TEST

START_TEST(mult_matrix) {
  matrix_t correctResult;
  matrix_t A;
  matrix_t B;
  matrix_t resAB;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &resAB), CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  matrix_t C;
  matrix_t D;
  matrix_t resCD;
  s21_create_matrix(2, 2, &C);
  s21_create_matrix(3, 2, &D);
  ck_assert_int_eq(s21_mult_matrix(&C, &D, &resCD), CALC_ERROR);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);

  matrix_t E;
  matrix_t F;
  matrix_t resEF;
  s21_create_matrix(2, 2, &E);
  s21_create_matrix(2, 2, &F);
  ck_assert_int_eq(s21_mult_matrix(&E, &F, NULL), ERROR);
  ck_assert_int_eq(s21_mult_matrix(NULL, &F, &resEF), ERROR);
  ck_assert_int_eq(s21_mult_matrix(&E, NULL, &resEF), ERROR);
  s21_remove_matrix(&E);
  s21_remove_matrix(&F);

  matrix_t G;
  matrix_t H;
  matrix_t resGH;
  s21_create_matrix(2, 2, &G);
  G.matrix[0][0] = 1;
  G.matrix[0][1] = 4;
  G.matrix[1][0] = 2;
  G.matrix[1][1] = 5;
  s21_create_matrix(2, 2, &H);
  H.matrix[0][0] = 3;
  H.matrix[0][1] = 7;
  H.matrix[1][0] = 6;
  H.matrix[1][1] = 8;
  s21_create_matrix(2, 2, &correctResult);
  correctResult.matrix[0][0] = 27;
  correctResult.matrix[0][1] = 39;
  correctResult.matrix[1][0] = 36;
  correctResult.matrix[1][1] = 54;
  ck_assert_int_eq(s21_mult_matrix(&G, &H, &resGH), OK);
  ck_assert_int_eq(s21_eq_matrix(&resGH, &correctResult), SUCCESS);
  s21_remove_matrix(&G);
  s21_remove_matrix(&H);
  s21_remove_matrix(&resGH);
  s21_remove_matrix(&correctResult);

  matrix_t I;
  matrix_t K;
  matrix_t resIK;
  s21_create_matrix(3, 2, &I);
  I.matrix[0][0] = 1;
  I.matrix[0][1] = 4;
  I.matrix[1][0] = 2;
  I.matrix[1][1] = 5;
  I.matrix[2][0] = 3;
  I.matrix[2][1] = 6;
  s21_create_matrix(2, 3, &K);
  K.matrix[0][0] = 1;
  K.matrix[0][1] = -1;
  K.matrix[0][2] = 1;
  K.matrix[1][0] = 2;
  K.matrix[1][1] = 3;
  K.matrix[1][2] = 4;
  s21_create_matrix(3, 3, &correctResult);
  correctResult.matrix[0][0] = 9;
  correctResult.matrix[0][1] = 11;
  correctResult.matrix[0][2] = 17;
  correctResult.matrix[1][0] = 12;
  correctResult.matrix[1][1] = 13;
  correctResult.matrix[1][2] = 22;
  correctResult.matrix[2][0] = 15;
  correctResult.matrix[2][1] = 15;
  correctResult.matrix[2][2] = 27;
  ck_assert_int_eq(s21_mult_matrix(&I, &K, &resIK), OK);
  ck_assert_int_eq(s21_eq_matrix(&resIK, &correctResult), SUCCESS);
  s21_remove_matrix(&I);
  s21_remove_matrix(&K);
  s21_remove_matrix(&resIK);
  s21_remove_matrix(&correctResult);
}
END_TEST

START_TEST(mult_number) {
  matrix_t correctResult;
  matrix_t A;
  matrix_t resA;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 4;
  s21_create_matrix(3, 3, &correctResult);
  correctResult.matrix[0][0] = 2;
  correctResult.matrix[0][1] = 4;
  correctResult.matrix[0][2] = 6;
  correctResult.matrix[1][0] = 0;
  correctResult.matrix[1][1] = 8;
  correctResult.matrix[1][2] = 4;
  correctResult.matrix[2][0] = 4;
  correctResult.matrix[2][1] = 6;
  correctResult.matrix[2][2] = 8;
  ck_assert_int_eq(s21_mult_number(&A, 2, &resA), OK);
  ck_assert_int_eq(s21_eq_matrix(&resA, &correctResult), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&resA);
  s21_remove_matrix(&correctResult);

  matrix_t B;
  ck_assert_int_eq(s21_mult_number(NULL, 2, &B), ERROR);

  matrix_t C;
  s21_create_matrix(3, 2, &C);
  ck_assert_int_eq(s21_mult_number(&C, 2, NULL), ERROR);
  s21_remove_matrix(&C);

  matrix_t D;
  matrix_t resD;
  s21_create_matrix(1, 2, &D);
  D.matrix[0][0] = 1;
  D.matrix[0][1] = 4;
  s21_create_matrix(1, 2, &correctResult);
  correctResult.matrix[0][0] = -5;
  correctResult.matrix[0][1] = -20;
  ck_assert_int_eq(s21_mult_number(&D, -5, &resD), OK);
  ck_assert_int_eq(s21_eq_matrix(&resD, &correctResult), SUCCESS);
  s21_remove_matrix(&D);
  s21_remove_matrix(&resD);
  s21_remove_matrix(&correctResult);
}
END_TEST

START_TEST(transpose) {
  matrix_t correctResult;
  matrix_t A;
  matrix_t resA;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  s21_create_matrix(2, 3, &correctResult);
  correctResult.matrix[0][0] = 1;
  correctResult.matrix[0][1] = 2;
  correctResult.matrix[0][2] = 3;
  correctResult.matrix[1][0] = 4;
  correctResult.matrix[1][1] = 5;
  correctResult.matrix[1][2] = 6;
  ck_assert_int_eq(s21_transpose(&A, &resA), OK);
  ck_assert_int_eq(s21_eq_matrix(&resA, &correctResult), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&resA);
  s21_remove_matrix(&correctResult);

  matrix_t B;
  s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(s21_transpose(&B, NULL), ERROR);
  ck_assert_int_eq(s21_transpose(NULL, &B), ERROR);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(calc_complements) {
  matrix_t correctResult;
  matrix_t A;
  matrix_t resA;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  s21_create_matrix(3, 3, &correctResult);
  correctResult.matrix[0][0] = 0;
  correctResult.matrix[0][1] = 10;
  correctResult.matrix[0][2] = -20;
  correctResult.matrix[1][0] = 4;
  correctResult.matrix[1][1] = -14;
  correctResult.matrix[1][2] = 8;
  correctResult.matrix[2][0] = -8;
  correctResult.matrix[2][1] = -2;
  correctResult.matrix[2][2] = 4;
  ck_assert_int_eq(s21_calc_complements(&A, &resA), OK);
  ck_assert_int_eq(s21_eq_matrix(&resA, &correctResult), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&resA);
  s21_remove_matrix(&correctResult);

  matrix_t B;
  matrix_t resB;
  s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(s21_calc_complements(&B, NULL), ERROR);
  ck_assert_int_eq(s21_calc_complements(NULL, &resB), ERROR);
  s21_remove_matrix(&B);

  matrix_t C;
  matrix_t resC;
  s21_create_matrix(1, 2, &C);
  ck_assert_int_eq(s21_calc_complements(&C, &resC), CALC_ERROR);
  s21_remove_matrix(&C);

  matrix_t D;
  matrix_t resD;
  s21_create_matrix(2, 2, &D);
  D.matrix[0][0] = 1;
  D.matrix[0][1] = -1;
  D.matrix[1][0] = 2;
  D.matrix[1][1] = 3;
  s21_create_matrix(2, 2, &correctResult);
  correctResult.matrix[0][0] = 3;
  correctResult.matrix[0][1] = -2;
  correctResult.matrix[1][0] = 1;
  correctResult.matrix[1][1] = 1;
  ck_assert_int_eq(s21_calc_complements(&D, &resD), OK);
  ck_assert_int_eq(s21_eq_matrix(&resD, &correctResult), SUCCESS);
  s21_remove_matrix(&D);
  s21_remove_matrix(&resD);
  s21_remove_matrix(&correctResult);
}
END_TEST

START_TEST(determinant) {
  matrix_t A;
  double resA = 0;
  s21_create_matrix(3, 2, &A);
  ck_assert_int_eq(s21_determinant(&A, &resA), CALC_ERROR);
  ck_assert_int_eq(s21_determinant(NULL, &resA), ERROR);
  s21_remove_matrix(&A);

  matrix_t B;
  double resB = 0;
  double corRes = -21;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 3;
  B.matrix[0][1] = 6;
  B.matrix[1][0] = 8;
  B.matrix[1][1] = 9;
  ck_assert_int_eq(s21_determinant(&B, &resB), OK);
  ck_assert_int_eq(resB, corRes);
  s21_remove_matrix(&B);

  matrix_t C;
  double resC = 0;
  double corRes2 = 0;
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1;
  C.matrix[0][1] = 2;
  C.matrix[0][2] = 3;
  C.matrix[1][0] = 4;
  C.matrix[1][1] = 5;
  C.matrix[1][2] = 6;
  C.matrix[2][0] = 7;
  C.matrix[2][1] = 8;
  C.matrix[2][2] = 9;
  ck_assert_int_eq(s21_determinant(&C, &resC), OK);
  ck_assert_int_eq(resC, corRes2);
  s21_remove_matrix(&C);

  matrix_t D;
  double resD = 0;
  double corRes3 = -32;
  s21_create_matrix(3, 3, &D);
  D.matrix[0][0] = 6;
  D.matrix[0][1] = 5;
  D.matrix[0][2] = 5;
  D.matrix[1][0] = 4;
  D.matrix[1][1] = 1;
  D.matrix[1][2] = 3;
  D.matrix[2][0] = 8;
  D.matrix[2][1] = 7;
  D.matrix[2][2] = 9;
  ck_assert_int_eq(s21_determinant(&D, &resD), OK);
  ck_assert_int_eq(resD, corRes3);
  s21_remove_matrix(&D);

  matrix_t E;
  double resE = 0;
  double corRes4 = 3;
  s21_create_matrix(1, 1, &E);
  E.matrix[0][0] = 3;
  ck_assert_int_eq(s21_determinant(&E, &resE), OK);
  ck_assert_int_eq(resE, corRes4);
  s21_remove_matrix(&E);
}
END_TEST

START_TEST(inverse_matrix) {
  matrix_t correctResult;
  matrix_t A;
  matrix_t resA;
  s21_create_matrix(3, 2, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &resA), CALC_ERROR);
  ck_assert_int_eq(s21_inverse_matrix(NULL, &resA), ERROR);
  s21_remove_matrix(&A);

  matrix_t B;
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_inverse_matrix(&B, NULL), ERROR);
  s21_remove_matrix(&B);

  matrix_t C;
  matrix_t resC;
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 2;
  C.matrix[0][1] = 5;
  C.matrix[0][2] = 7;
  C.matrix[1][0] = 6;
  C.matrix[1][1] = 3;
  C.matrix[1][2] = 4;
  C.matrix[2][0] = 5;
  C.matrix[2][1] = -2;
  C.matrix[2][2] = -3;
  s21_create_matrix(3, 3, &correctResult);
  correctResult.matrix[0][0] = 1;
  correctResult.matrix[0][1] = -1;
  correctResult.matrix[0][2] = 1;
  correctResult.matrix[1][0] = -38;
  correctResult.matrix[1][1] = 41;
  correctResult.matrix[1][2] = -34;
  correctResult.matrix[2][0] = 27;
  correctResult.matrix[2][1] = -29;
  correctResult.matrix[2][2] = 24;
  ck_assert_int_eq(s21_inverse_matrix(&C, &resC), OK);
  ck_assert_int_eq(s21_eq_matrix(&resC, &correctResult), SUCCESS);
  s21_remove_matrix(&C);
  s21_remove_matrix(&resC);
  s21_remove_matrix(&correctResult);
}
END_TEST

Suite *copying_suite_create(void) {
  Suite *suite = suite_create("Core");
  TCase *tcase_core = tcase_create("Core");
  tcase_add_test(tcase_core, create_matrix);
  tcase_add_test(tcase_core, eq_matrix);
  tcase_add_test(tcase_core, sum_matrix);
  tcase_add_test(tcase_core, sub_matrix);
  tcase_add_test(tcase_core, mult_matrix);
  tcase_add_test(tcase_core, mult_number);
  tcase_add_test(tcase_core, transpose);
  tcase_add_test(tcase_core, calc_complements);
  tcase_add_test(tcase_core, determinant);
  tcase_add_test(tcase_core, inverse_matrix);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

int main(void) {
  Suite *suite = copying_suite_create();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_NORMAL);
  srunner_set_fork_status(suite_runner, CK_NOFORK);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
