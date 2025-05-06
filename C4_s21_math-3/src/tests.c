#include <check.h>
#include <math.h>

#include "s21_math.h"

START_TEST(suite_abs) {
  ck_assert_int_eq(s21_abs(2), abs(2));
  ck_assert_int_eq(s21_abs(-25), abs(-25));
  ck_assert_int_eq(s21_abs(1), abs(1));
  ck_assert_int_eq(s21_abs(-1), abs(-1));
  ck_assert_int_eq(s21_abs(0), abs(0));
}
END_TEST

START_TEST(suite_fabs) {
  ck_assert_double_eq(s21_fabs(2.526624), fabs(2.526624));
  ck_assert_double_eq(s21_fabs(-25.000331), fabs(-25.000331));
  ck_assert_double_eq(s21_fabs(1.), fabs(1.));
  ck_assert_double_eq(s21_fabs(0.), fabs(0.));
  ck_assert_ldouble_nan(s21_fabs(S21_NAN));
  ck_assert_ldouble_infinite(s21_fabs(S21_INF));
}
END_TEST

START_TEST(suite_fmod) {
  ck_assert_ldouble_nan(s21_fmod(0., 0.));
  ck_assert_ldouble_nan(s21_fmod(2.526624, 0.));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, 2.526624));
  ck_assert_ldouble_nan(s21_fmod(2.526624, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, S21_INF));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, 2.5));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_INF));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, S21_NAN));
  ck_assert_double_eq(s21_fmod(0., 2.526624), fmod(0., 2.526624));
  ck_assert_double_eq(s21_fmod(2.526624, S21_INF), fmod(2.526624, S21_INF));
  ck_assert_double_eq(s21_fmod(5.897357, 5.897357), fmod(5.897357, 5.897357));
  ck_assert_double_eq(s21_fmod(-5.897357, 3.326624), fmod(-5.897357, 3.326624));
  ck_assert_double_eq(s21_fmod(5.897357, -3.326624), fmod(5.897357, -3.326624));
}
END_TEST

START_TEST(suite_cos) {
  ck_assert_double_eq(s21_cos(0.), cos(0.));
  ck_assert_double_eq_tol(s21_cos(1.), cos(1.), 0.000001);
  ck_assert_double_eq_tol(s21_cos(628), cos(628), 0.000001);
  ck_assert_double_eq_tol(s21_cos(2.526624), cos(2.526624), 0.000001);
  ck_assert_double_eq_tol(s21_cos(-2.526624), cos(-2.526624), 0.000001);
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_nan(s21_cos(S21_INF));
}
END_TEST

START_TEST(suite_acos) {
  ck_assert_double_eq_tol(s21_acos(0.), acos(0.), 0.000001);
  ck_assert_double_eq_tol(s21_acos(-1.), acos(-1.), 0.000001);
  ck_assert_double_eq(s21_acos(1.), acos(1.));
  ck_assert_ldouble_nan(s21_acos(628));
  ck_assert_ldouble_nan(s21_acos(2.526624));
  ck_assert_ldouble_nan(s21_acos(-2.526624));
  ck_assert_ldouble_nan(s21_acos(S21_NAN));
  ck_assert_ldouble_nan(s21_acos(S21_INF));
  ck_assert_ldouble_nan(s21_acos(S21_N_INF));
}
END_TEST
START_TEST(suite_sin) {
  ck_assert_double_eq_tol(s21_sin(0.), sin(0.), 0.000001);
  ck_assert_double_eq_tol(s21_sin(1.), sin(1.), 0.000001);
  ck_assert_double_eq_tol(s21_sin(628), sin(628), 0.000001);
  ck_assert_double_eq_tol(s21_sin(2.526624), sin(2.526624), 0.000001);
  ck_assert_double_eq_tol(s21_sin(-2.526624), sin(-2.526624), 0.000001);
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
  ck_assert_ldouble_nan(s21_sin(S21_INF));
  ck_assert_ldouble_nan(s21_sin(S21_N_INF));
}
END_TEST

START_TEST(suite_asin) {
  ck_assert_double_eq_tol(s21_asin(0.), asin(0.), 0.000001);
  ck_assert_double_eq_tol(s21_asin(1.), asin(1.), 0.000001);
  ck_assert_ldouble_nan(s21_asin(628));
  ck_assert_ldouble_nan(s21_asin(2.526624));
  ck_assert_ldouble_nan(s21_asin(-2.526624));
  ck_assert_ldouble_nan(s21_asin(S21_NAN));
  ck_assert_ldouble_nan(s21_asin(S21_INF));
  ck_assert_ldouble_nan(s21_asin(S21_N_INF));
}
END_TEST

START_TEST(suite_log) {
  ck_assert_double_eq_tol(s21_log(1.), log(1.), 0.000001);
  ck_assert_ldouble_infinite(s21_log(0.));
  ck_assert_double_eq_tol(s21_log(628), log(628), 0.000001);
  ck_assert_ldouble_nan(s21_log(-2.526624));
  ck_assert_ldouble_nan(s21_log(-1));
  ck_assert_ldouble_nan(s21_log(S21_NAN));
  ck_assert_ldouble_infinite(s21_log(S21_INF));
  ck_assert_double_eq_tol(s21_log(2.526624), log(2.526624), 0.000001);
  ck_assert_double_eq_tol(s21_log(1.7976931348623158e+308),
                          log(1.7976931348623158e+308), 0.000001);
  ck_assert_double_eq_tol(s21_log(9999999999999999.0), log(9999999999999999.0),
                          0.000001);
  ck_assert_double_eq_tol(s21_log(0.0000006), log(0.0000006), 0.000001);
}
END_TEST

START_TEST(suite_tan) {
  ck_assert_double_eq_tol(s21_tan(0.), tan(0.), 0.000001);
  ck_assert_double_eq_tol(s21_tan(1.), tan(1.), 0.000001);
  ck_assert_double_eq_tol(s21_tan(628), tan(628), 0.000001);
  ck_assert_double_eq_tol(s21_tan(2.526624), tan(2.526624), 0.000001);
  ck_assert_double_eq_tol(s21_tan(-2.526624), tan(-2.526624), 0.000001);
  ck_assert_ldouble_nan(s21_tan(S21_NAN));
  ck_assert_ldouble_infinite(s21_tan(S21_PI / 2.));
  ck_assert_ldouble_infinite(s21_tan(-S21_PI / 2.));
  ck_assert_ldouble_nan(s21_tan(S21_INF));
  ck_assert_ldouble_nan(s21_tan(S21_N_INF));
}
END_TEST

START_TEST(suite_atan) {
  ck_assert_double_eq_tol(s21_atan(0.), atan(0.), 0.000001);
  ck_assert_double_eq_tol(s21_atan(1.), atan(1.), 0.000001);
  ck_assert_double_eq_tol(s21_atan(628), atan(628), 0.000001);
  ck_assert_double_eq_tol(s21_atan(2.526624), atan(2.526624), 0.000001);
  ck_assert_double_eq_tol(s21_atan(-2.526624), atan(-2.526624), 0.000001);
  ck_assert_ldouble_nan(s21_atan(S21_NAN));
  ck_assert_double_eq_tol(s21_atan(S21_INF), atan(S21_INF), 0.000001);
  ck_assert_double_eq_tol(s21_atan(S21_N_INF), atan(S21_N_INF), 0.000001);
}
END_TEST

START_TEST(suite_exp) {
  ck_assert_double_eq(s21_exp(0.), exp(0.));
  ck_assert_double_eq_tol(s21_exp(1.), exp(1.), 0.000001);
  ck_assert_double_eq_tol(s21_exp(2.526624), exp(2.526624), 0.000001);
  ck_assert_double_eq_tol(s21_exp(-2.526624), exp(-2.526624), 0.000001);
  ck_assert_double_eq_tol(s21_exp(20), exp(20), 0.000001);
  ck_assert_ldouble_infinite(s21_exp(9999999999999999.0));
  ck_assert_ldouble_infinite(s21_exp(1.7976931348623158e+308));
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_infinite(s21_exp(S21_INF));
  ck_assert_double_eq(s21_exp(S21_N_INF), exp(-INFINITY));
}
END_TEST

START_TEST(suite_floor) {
  ck_assert_double_eq(s21_floor(0.), floor(0.));
  ck_assert_double_eq(s21_floor(1.), floor(1.));
  ck_assert_double_eq(s21_floor(2.526624), floor(2.526624));
  ck_assert_double_eq(s21_floor(-2.526624), floor(-2.526624));
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
  ck_assert_ldouble_infinite(s21_floor(S21_INF));
  ck_assert_ldouble_infinite(s21_floor(S21_N_INF));
}
END_TEST

START_TEST(suite_ceil) {
  ck_assert_double_eq(s21_ceil(0.), ceil(0.));
  ck_assert_double_eq(s21_ceil(1.), ceil(1.));
  ck_assert_double_eq(s21_ceil(2.526624), ceil(2.526624));
  ck_assert_double_eq(s21_ceil(-2.526624), ceil(-2.526624));
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
  ck_assert_ldouble_infinite(s21_ceil(S21_INF));
  ck_assert_ldouble_infinite(s21_ceil(S21_N_INF));
}
END_TEST

START_TEST(suite_pow) {
  ck_assert_double_eq_tol(s21_pow(0., 0.), pow(0., 0.), 0.000001);
  ck_assert_double_eq_tol(s21_pow(1., 1.), pow(1., 1.), 0.000001);
  ck_assert_double_eq_tol(s21_pow(1., 2), pow(1., 2), 0.000001);
  ck_assert_double_eq_tol(s21_pow(2.526624, 0.), pow(2.526624, 0.), 0.000001);
  ck_assert_double_eq_tol(s21_pow(2.526624, 2.526624), pow(2.526624, 2.526624),
                          0.000001);
  ck_assert_double_eq_tol(s21_pow(1., S21_NAN), pow(1., S21_NAN), 0.000001);
  ck_assert_double_eq_tol(s21_pow(1., S21_INF), pow(1., S21_INF), 0.000001);
  ck_assert_double_eq_tol(s21_pow(1., S21_N_INF), pow(1., S21_N_INF), 0.000001);
  ck_assert_ldouble_nan(s21_pow(2.526624, S21_NAN));
  ck_assert_ldouble_infinite(s21_pow(2.526624, S21_INF));
  ck_assert_double_eq_tol(s21_pow(2.526624, S21_N_INF),
                          pow(2.526624, S21_N_INF), 0.000001);
  ck_assert_double_eq_tol(s21_pow(0., 2), pow(0., 2), 0.000001);
  ck_assert_ldouble_nan(s21_pow(0., S21_NAN));
  ck_assert_double_eq_tol(s21_pow(0., S21_INF), pow(0., S21_INF), 0.000001);
  ck_assert_ldouble_infinite(s21_pow(0., S21_N_INF));
  ck_assert_double_eq_tol(s21_pow(685, 3), pow(685, 3), 0.000001);
  ck_assert_double_eq_tol(s21_pow(-2.526624, 3), pow(-2.526624, 3), 0.000001);
  ck_assert_double_eq_tol(s21_pow(-2.526624, -3), pow(-2.526624, -3), 0.000001);
  ck_assert_double_eq_tol(s21_pow(2.526624, -3), pow(2.526624, -3), 0.000001);
  ck_assert_double_eq_tol(s21_pow(2.526624, 3), pow(2.526624, 3), 0.000001);
  ck_assert_double_eq_tol(s21_pow(2.526624, 3.5), pow(2.526624, 3.5), 0.000001);
  ck_assert_double_eq_tol(s21_pow(2.526624, -3.5), pow(2.526624, -3.5),
                          0.000001);
  ck_assert_ldouble_nan(s21_pow(S21_NAN, 2));
  ck_assert_ldouble_infinite(s21_pow(S21_INF, 2));
  ck_assert_ldouble_infinite(s21_pow(S21_N_INF, 2));
  ck_assert_ldouble_infinite(s21_pow(S21_N_INF, 2.5));
  ck_assert_ldouble_infinite(s21_pow(S21_INF, S21_INF));
  ck_assert_ldouble_infinite(s21_pow(1.7976931348623158e+308, 2));
  ck_assert_ldouble_infinite(s21_pow(2, 1.7976931348623158e+308));
  ck_assert_double_eq_tol(s21_pow(9999999999999999.0, 2),
                          pow(9999999999999999.0, 2), 0.000001);
}
END_TEST

START_TEST(suite_sqrt) {
  ck_assert_double_eq_tol(s21_sqrt(0.), sqrt(0.), 0.000001);
  ck_assert_double_eq_tol(s21_sqrt(1.), sqrt(1.), 0.000001);
  ck_assert_ldouble_nan(s21_sqrt(-1.));
  ck_assert_double_eq_tol(s21_sqrt(2.526624), sqrt(2.526624), 0.000001);
  ck_assert_double_eq_tol(s21_sqrt(9999999999999999.0),
                          sqrt(9999999999999999.0), 0.000001);
  ck_assert_ldouble_nan(s21_sqrt(-2.526624));
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_infinite(s21_sqrt(S21_INF));
  ck_assert_ldouble_nan(s21_sqrt(S21_N_INF));
  ck_assert_double_eq_tol(s21_sqrt(628), sqrt(628), 0.000001);
}
END_TEST

Suite *copying_suite_create(void) {
  Suite *suite = suite_create("Core");
  TCase *tcase_core = tcase_create("Core");
  tcase_add_test(tcase_core, suite_abs);
  tcase_add_test(tcase_core, suite_fabs);
  tcase_add_test(tcase_core, suite_floor);
  tcase_add_test(tcase_core, suite_fmod);
  tcase_add_test(tcase_core, suite_exp);
  tcase_add_test(tcase_core, suite_cos);
  tcase_add_test(tcase_core, suite_acos);
  tcase_add_test(tcase_core, suite_asin);
  tcase_add_test(tcase_core, suite_sin);
  tcase_add_test(tcase_core, suite_atan);
  tcase_add_test(tcase_core, suite_tan);
  tcase_add_test(tcase_core, suite_ceil);
  tcase_add_test(tcase_core, suite_log);
  tcase_add_test(tcase_core, suite_pow);
  tcase_add_test(tcase_core, suite_sqrt);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

int main(void) {
  Suite *suite = copying_suite_create();
  SRunner *suite_runner = srunner_create(suite);
  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}