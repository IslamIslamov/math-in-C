#include <check.h>

#include "s21_math.h"

//////////////////////////////////////////////////////
//***********************FABS**********************//

START_TEST(s21_fabs_test_1) { ck_assert_ldouble_eq(s21_fabs(1.0), fabs(1.0)); }
END_TEST
START_TEST(s21_fabs_test_2) {
  ck_assert_ldouble_eq(s21_fabs(-1.000005), fabs(-1.000005));
}
END_TEST
START_TEST(s21_fabs_test_3) {
  ck_assert_ldouble_eq(s21_fabs(-0.0), fabs(-0.0));
}
END_TEST
START_TEST(s21_fabs_test_4) {
  ck_assert_ldouble_eq(s21_fabs(s21_INF), fabs(s21_INF));
}
END_TEST
START_TEST(s21_fabs_test_5) {
  ck_assert_ldouble_eq(s21_fabs(-s21_INF), fabs(-s21_INF));
}
END_TEST
START_TEST(s21_fabs_test_6) { ck_assert_ldouble_nan(s21_fabs(s21_NAN)); }
END_TEST
START_TEST(s21_fabs_test_7) {
  ck_assert_ldouble_eq(s21_fabs(1364.088), fabs(1364.088));
}
END_TEST
START_TEST(s21_fabs_test_8) {
  ck_assert_ldouble_eq(s21_fabs(-1364.088), fabs(-1364.088));
}
END_TEST
START_TEST(s21_fabs_test_9) {
  ck_assert_ldouble_eq(s21_fabs(568745.168), fabs(568745.168));
}
END_TEST
START_TEST(s21_fabs_test_10) {
  ck_assert_ldouble_eq(s21_fabs(-568745.168), fabs(-568745.168));
}
END_TEST

//////////////////////////////////////////////////////
//***********************FLOOR**********************//

START_TEST(s21_floor_test_1) {
  ck_assert_ldouble_eq(s21_floor(1.5), floor(1.5));
}
END_TEST
START_TEST(s21_floor_test_2) {
  ck_assert_ldouble_eq(s21_floor(0.45), floor(0.45));
}
END_TEST
START_TEST(s21_floor_test_3) {
  ck_assert_ldouble_eq(s21_floor(-3.01), floor(-3.01));
}
END_TEST
START_TEST(s21_floor_test_4) {
  ck_assert_ldouble_eq(s21_floor(-0.0), floor(-0.0));
}
END_TEST
START_TEST(s21_floor_test_5) { ck_assert_uint_eq(s21_floor(-0), floor(-0)); }
END_TEST
START_TEST(s21_floor_test_6) {
  ck_assert_ldouble_eq(s21_floor(4.7323234567890765),
                       floor(4.7323234567890765));
}
END_TEST
START_TEST(s21_floor_test_7) {
  ck_assert_ldouble_eq(s21_floor(s21_INF), floor(s21_INF));
}
END_TEST
START_TEST(s21_floor_test_8) {
  ck_assert_ldouble_eq(s21_floor(-s21_INF), floor(-s21_INF));
}
END_TEST
START_TEST(s21_floor_test_9) {
  ck_assert_ldouble_eq(s21_floor(0.123456907912345), floor(0.123456907912345));
}
END_TEST
START_TEST(s21_floor_test_10) {
  ck_assert_uint_eq(s21_floor(1234), floor(1234));
}
END_TEST
START_TEST(s21_floor_test_11) { ck_assert_ldouble_nan(s21_floor(s21_NAN)); }
END_TEST

//////////////////////////////////////////////////////
//***********************FMOD**********************//

START_TEST(s21_fmod_test_1) {
  ck_assert_ldouble_eq_tol(s21_fmod(9.0, 3.5), fmod(9.0, 3.5), 1e-6);
}
END_TEST

START_TEST(s21_fmod_test_2) {
  ck_assert_ldouble_eq_tol(s21_fmod(0.0, 3.1), fmod(0.0, 3.1), 1e-6);
}
END_TEST

START_TEST(s21_fmod_test_3) { ck_assert_ldouble_nan(s21_fmod(s21_INF, 2.5)); }
END_TEST

START_TEST(s21_fmod_test_4) { ck_assert_ldouble_nan(s21_fmod(-s21_INF, 2.5)); }
END_TEST

START_TEST(s21_fmod_test_5) { ck_assert_ldouble_nan(s21_fmod(5.8, 0.0)); }
END_TEST

START_TEST(s21_fmod_test_6) { ck_assert_ldouble_nan(s21_fmod(2.8, -0.0)); }
END_TEST

START_TEST(s21_fmod_test_7) {
  ck_assert_ldouble_eq_tol(s21_fmod(9.8, s21_INF), fmod(9.8, s21_INF), 1e-6);
}
END_TEST

START_TEST(s21_fmod_test_8) {
  ck_assert_ldouble_eq_tol(s21_fmod(9.8, -s21_INF), fmod(9.8, -s21_INF), 1e-6);
}
END_TEST

START_TEST(s21_fmod_test_9) { ck_assert_ldouble_nan(s21_fmod(s21_NAN, 15.7)); }
END_TEST

START_TEST(s21_fmod_test_10) { ck_assert_ldouble_nan(s21_fmod(2.5, s21_NAN)); }
END_TEST

//////////////////////////////////////////////////////
//***********************LOG**********************//

START_TEST(s21_log_test_1) {
  ck_assert_ldouble_eq_tol(s21_log(3.2164), log(3.2164), 1e-6);
}
END_TEST

START_TEST(s21_log_test_2) {
  ck_assert_ldouble_eq_tol(s21_log(4.3234323e-43), log(4.3234323e-43), 1e-6);
}
END_TEST

START_TEST(s21_log_test_3) { ck_assert_ldouble_nan(s21_log(-3432.12)); }

START_TEST(s21_log_test_4) { ck_assert_ldouble_infinite(s21_log(0)); }

START_TEST(s21_log_test_5) {
  ck_assert_ldouble_eq_tol(log(1), s21_log(1), 1e-6);
}
END_TEST

START_TEST(s21_log_test_6) { ck_assert_ldouble_nan(s21_log(s21_NAN)); }

START_TEST(s21_log_test_7) { ck_assert_ldouble_nan(s21_log(-s21_NAN)); }

START_TEST(s21_log_test_8) { ck_assert_ldouble_infinite(s21_log(s21_INF)); }

START_TEST(s21_log_test_9) { ck_assert_ldouble_nan(s21_log(-s21_INF)); }

START_TEST(s21_log_test_10) {
  for (double i = -1.; i < 10; i += 0.1) {
    ck_assert_int_eq(s21_log(i), log(i));
  }
}
END_TEST

START_TEST(s21_log_test_11) {
  for (double i = 0.; i < 2; i += 0.01) {
    ck_assert_int_eq(s21_log(i), log(i));
  }
}
END_TEST

//////////////////////////////////////////////////////
//***********************POW**********************//

START_TEST(s21_pow_test_1) {
  ck_assert_ldouble_eq_tol(pow(532.5, 2.8), s21_pow(532.5, 2.8), 1e-6);
}
END_TEST

START_TEST(s21_pow_test_2) {
  ck_assert_ldouble_eq_tol(pow(532.5, 20.5e-34), s21_pow(532.5, 20.5e-34),
                           1e-6);
}
END_TEST

START_TEST(s21_pow_test_3) {
  ck_assert_ldouble_eq_tol(pow(532.5, -42.0), s21_pow(532.5, -42.0), 1e-6);
}
END_TEST

START_TEST(s21_pow_test_4) {
  ck_assert_ldouble_eq_tol(pow(-10.2, -3.0), s21_pow(-10.2, -3.0), 1e-6);
}
END_TEST

START_TEST(s21_pow_test_5) {
  ck_assert_ldouble_eq_tol(pow(-10.2, 2.0), s21_pow(-10.2, 2.0), 1e-6);
}
END_TEST

START_TEST(s21_pow_test_6) { ck_assert_ldouble_nan(s21_pow(-10.1, -1.5)); }
END_TEST

START_TEST(s21_pow_test_7) {
  double nums[6] = {1.12, -34.45, s21_NAN, -s21_NAN, s21_INF, -s21_INF};
  double p = 0;
  int i = _i;
  ck_assert_ldouble_eq_tol(pow(nums[i], p), s21_pow(nums[i], p), 1e-6);
}

START_TEST(s21_pow_test_8) {
  ck_assert_ldouble_eq_tol(pow(12.34, 1), s21_pow(12.34, 1), 1e-6);
}
END_TEST

START_TEST(s21_pow_test_9) {
  ck_assert_ldouble_infinite(s21_pow(0.123, -s21_INF));
  ck_assert_ldouble_infinite(pow(0.123, -s21_INF));
}
END_TEST

START_TEST(s21_pow_test_10) {
  ck_assert_ldouble_eq_tol(pow(0.123, s21_INF), s21_pow(0.123, s21_INF), 1e-6);
}
END_TEST

START_TEST(s21_pow_test_11) {
  ck_assert_ldouble_infinite(s21_pow(s21_INF, 12));
  ck_assert_ldouble_infinite(pow(s21_INF, 12));
}
END_TEST

START_TEST(s21_pow_test_12) {
  ck_assert_ldouble_eq_tol(pow(10.1, 0.123), s21_pow(10.1, 0.123), 1e-6);
}
END_TEST

START_TEST(s21_pow_test_13) {
  ck_assert_ldouble_eq_tol(pow(-2, -3), s21_pow(-2, -3), 1e-6);
}
END_TEST

//////////////////////////////////////////////////////
//***********************ABS**********************//

START_TEST(s21_abs_test_1) { ck_assert_int_eq(abs(-3 / 4), s21_abs(-3 / 4)); }
END_TEST

START_TEST(s21_abs_test_2) { ck_assert_int_eq(abs(1), s21_abs(1)); }
END_TEST

START_TEST(s21_abs_test_3) { ck_assert_int_eq(abs(-1), s21_abs(-1)); }
END_TEST

START_TEST(s21_abs_test_4) {
  ck_assert_int_eq(abs(-03), s21_abs(-03));
  ;
}
END_TEST

START_TEST(s21_abs_test_5) {
  ck_assert_int_eq(abs(100000000), s21_abs(100000000));
}
END_TEST

START_TEST(s21_abs_test_6) { ck_assert_int_eq(abs(-0), s21_abs(-0)); }
END_TEST

START_TEST(s21_abs_test_7) { ck_assert_int_eq(abs(-999999), s21_abs(-999999)); }
END_TEST

START_TEST(s21_abs_test_8) { ck_assert_int_eq(abs(-5), s21_abs(-5)); }
END_TEST

START_TEST(s21_abs_test_9) {
  ck_assert_int_eq(abs(INT32_MAX), s21_abs(INT32_MAX));
}
END_TEST

START_TEST(s21_abs_test_10) {
  ck_assert_int_eq(abs(INT32_MIN), s21_abs(INT32_MIN));
}
END_TEST

//////////////////////////////////////////////////////
//***********************EXP**********************//

START_TEST(s21_exp_test_1) { ck_assert_ldouble_infinite(s21_exp(s21_INF)); }
END_TEST

START_TEST(s21_exp_test_2) {
  ck_assert_ldouble_eq_tol(exp(2.0), s21_exp(2.0), ROUND_UP);
}
END_TEST

START_TEST(s21_exp_test_3) {
  ck_assert_ldouble_eq_tol(exp(-01000), s21_exp(-01000), ROUND_UP);
}
END_TEST

START_TEST(s21_exp_test_4) {
  ck_assert_ldouble_eq_tol(exp(7.345e-29), s21_exp(7.345e-29), 1e-6);
}

START_TEST(s21_exp_test_5) {
  ck_assert_ldouble_eq_tol(exp(0), s21_exp(0), ROUND_UP);
}
END_TEST

START_TEST(s21_exp_test_6) {
  ck_assert_ldouble_eq_tol(exp(-1 / 2), s21_exp(-1 / 2), ROUND_UP);
}
END_TEST

START_TEST(s21_exp_test_7) {
  ck_assert_ldouble_eq_tol(exp(-1000.0), s21_exp(-1000.0), ROUND_UP);
}
END_TEST

START_TEST(s21_exp_test_8) { ck_assert_ldouble_infinite(s21_exp(1000.0)); }
END_TEST

START_TEST(s21_exp_test_9) {
  ck_assert_ldouble_eq_tol(exp(0.00001), s21_exp(0.00001), ROUND_UP);
}
END_TEST

START_TEST(s21_exp_test_10) {
  ck_assert_ldouble_eq_tol(exp(1 / s21_PI), s21_exp(1 / s21_PI), ROUND_UP);
}
END_TEST

START_TEST(s21_exp_test_11) { ck_assert_ldouble_nan(s21_exp(s21_NAN)); }
END_TEST

START_TEST(s21_exp_test_12) {
  ck_assert_ldouble_eq(exp(s21_INF), s21_exp(s21_INF));
}
END_TEST

START_TEST(s21_exp_test_13) {
  ck_assert_ldouble_eq(exp(-s21_INF), s21_exp(-s21_INF));
}
END_TEST

//////////////////////////////////////////////////////
//***********************CEIL**********************//

START_TEST(s21_ceil_test_1) { ck_assert_int_eq(ceil(1.5), s21_ceil(1.5)); }
END_TEST

START_TEST(s21_ceil_test_2) { ck_assert_int_eq(ceil(0.45), s21_ceil(0.45)); }
END_TEST

START_TEST(s21_ceil_test_3) { ck_assert_int_eq(ceil(-3.01), s21_ceil(-3.01)); }
END_TEST

START_TEST(s21_ceil_test_4) { ck_assert_int_eq(ceil(-0), s21_ceil(-0)); }
END_TEST

START_TEST(s21_ceil_test_5) {
  ck_assert_int_eq(ceil(1234567), s21_ceil(1234567));
}
END_TEST

START_TEST(s21_ceil_test_6) {
  ck_assert_ldouble_nan(s21_ceil(s21_NAN));
  ck_assert_ldouble_nan(ceil(s21_NAN));
}
END_TEST

START_TEST(s21_ceil_test_7) {
  ck_assert_ldouble_eq(ceil(-s21_INF), s21_ceil(-s21_INF));
}
END_TEST

START_TEST(s21_ceil_test_8) { ck_assert_ldouble_nan(s21_ceil(s21_NAN)); }
END_TEST

START_TEST(s21_ceil_test_9) {
  ck_assert_ldouble_eq(ceil(14.7), s21_ceil(14.7));
}
END_TEST

START_TEST(s21_ceil_test_10) {
  ck_assert_ldouble_eq(ceil(s21_INF), s21_ceil(s21_INF));
}
END_TEST

//////////////////////////////////////////////////////
//***********************SIN**********************//

START_TEST(s21_sin_test_1) {
  ck_assert_ldouble_eq_tol(sin(2.5256), s21_sin(2.5256), ROUND_UP);
}
END_TEST

START_TEST(s21_sin_test_2) {
  ck_assert_ldouble_eq_tol(sin(-2.5256), s21_sin(-2.5256), ROUND_UP);
}
END_TEST

START_TEST(s21_sin_test_3) {
  ck_assert_ldouble_eq_tol(sin(923456789), s21_sin(923456789), ROUND_UP);
}
END_TEST

START_TEST(s21_sin_test_4) {
  ck_assert_ldouble_eq_tol(sin(-923456789), s21_sin(-923456789), ROUND_UP);
}
END_TEST

START_TEST(s21_sin_test_5) {
  ck_assert_ldouble_eq_tol(sin(0), s21_sin(0), ROUND_UP);
}
END_TEST

START_TEST(s21_sin_test_6) { ck_assert_ldouble_nan(s21_sin(s21_NAN)); }
END_TEST

START_TEST(s21_sin_test_7) { ck_assert_ldouble_nan(s21_sin(s21_INF)); }
END_TEST

START_TEST(s21_sin_test_8) {
  int i = _i;
  if (i != 0) {
    ck_assert_ldouble_eq_tol(sin(s21_PI / i), s21_sin(s21_PI / i), ROUND_UP);
  } else {
    ck_assert_ldouble_nan(s21_sin(s21_PI / i));
  }
}
END_TEST

START_TEST(s21_sin_test_9) {
  int i = _i;
  ck_assert_ldouble_eq_tol(sin(s21_PI * i), s21_sin(s21_PI * i), ROUND_UP);
}
END_TEST

START_TEST(s21_sin_test_10) {
  ck_assert_ldouble_eq_tol(sin(0.12345678901234567890),
                           s21_sin(0.12345678901234567890), ROUND_UP);
}
END_TEST

//////////////////////////////////////////////////////
//***********************COS**********************//

START_TEST(s21_cos_test_1) {
  ck_assert_ldouble_eq_tol(cos(0.8), s21_cos(0.8), ROUND_UP);
}
END_TEST

START_TEST(s21_cos_test_2) {
  ck_assert_ldouble_eq_tol(cos(-0.8), s21_cos(-0.8), ROUND_UP);
}
END_TEST

START_TEST(s21_cos_test_3) {
  ck_assert_ldouble_eq_tol(cos(1), s21_cos(1), ROUND_UP);
}
END_TEST

START_TEST(s21_cos_test_4) {
  ck_assert_ldouble_eq_tol(cos(-1), s21_cos(-1), ROUND_UP);
}
END_TEST

START_TEST(s21_cos_test_5) {
  ck_assert_ldouble_eq_tol(cos(598987986), s21_cos(598987986), ROUND_UP);
}
END_TEST

START_TEST(s21_cos_test_6) {
  ck_assert_ldouble_eq_tol(cos(-598987986), s21_cos(-598987986), ROUND_UP);
}
END_TEST

START_TEST(s21_cos_test_7) {
  ck_assert_ldouble_eq_tol(cos(0.123456789012345678901234567890),
                           s21_cos(0.123456789012345678901234567890), ROUND_UP);
}
END_TEST

START_TEST(s21_cos_test_8) {
  ck_assert_ldouble_eq_tol(cos(s21_PI), s21_cos(s21_PI), ROUND_UP);
}
END_TEST

START_TEST(s21_cos_test_9) { ck_assert_ldouble_nan(s21_cos(s21_INF)); }
END_TEST

START_TEST(s21_cos_test_10) { ck_assert_ldouble_nan(s21_cos(s21_NAN)); }
END_TEST

START_TEST(s21_cos_test_11) { ck_assert_ldouble_nan(s21_cos(-s21_INF)); }
END_TEST

START_TEST(s21_cos_test_12) {
  int i = _i;
  ck_assert_ldouble_eq_tol(cos(s21_PI * i), s21_cos(s21_PI * i), ROUND_UP);
}
END_TEST

//////////////////////////////////////////////////////
//***********************TAN************************//

START_TEST(s21_tan_test_1) {
  ck_assert_ldouble_eq_tol(tan(0.35), s21_tan(0.35), ROUND_UP);
}
END_TEST

START_TEST(s21_tan_test_2) {
  ck_assert_ldouble_eq_tol(tan(-0.35), s21_tan(-0.35), ROUND_UP);
}
END_TEST

START_TEST(s21_tan_test_3) {
  ck_assert_ldouble_eq_tol(tan(0), s21_tan(0), ROUND_UP);
}
END_TEST

START_TEST(s21_tan_test_4) {
  ck_assert_ldouble_eq_tol(tan(1), s21_tan(1), ROUND_UP);
}
END_TEST

START_TEST(s21_tan_test_5) {
  ck_assert_ldouble_eq_tol(tan(-1), s21_tan(-1), ROUND_UP);
}
END_TEST

START_TEST(s21_tan_test_6) {
  ck_assert_ldouble_eq_tol(tan(598987986), s21_tan(598987986), ROUND_UP);
}
END_TEST

START_TEST(s21_tan_test_7) {
  ck_assert_ldouble_eq_tol(tan(-598987986), s21_tan(-598987986), ROUND_UP);
}
END_TEST

START_TEST(s21_tan_test_8) {
  ck_assert_ldouble_eq_tol(tan(0.123456789012345678901234567890),
                           s21_tan(0.123456789012345678901234567890), 1e-6);
}
END_TEST

START_TEST(s21_tan_test_9) {
  ck_assert_ldouble_eq_tol(tan(s21_PI), s21_tan(s21_PI), ROUND_UP);
}
END_TEST

START_TEST(s21_tan_test_10) { ck_assert_ldouble_nan(s21_tan(s21_INF)); }
END_TEST

START_TEST(s21_tan_test_11) { ck_assert_ldouble_nan(s21_tan(s21_NAN)); }
END_TEST

START_TEST(s21_tan_test_12) { ck_assert_ldouble_nan(s21_tan(-s21_INF)); }
END_TEST

START_TEST(s21_tan_test_13) {
  int i = _i;
  ck_assert_ldouble_eq_tol(tan(s21_PI * i), s21_tan(s21_PI * i), ROUND_UP);
}
END_TEST

//////////////////////////////////////////////////////
//***********************SQRT************************//

START_TEST(s21_sqrt_test_1) {
  ck_assert_ldouble_eq_tol(sqrt(1), s21_sqrt(1), ROUND_UP);
}
END_TEST

START_TEST(s21_sqrt_test_2) {
  ck_assert_ldouble_eq_tol(sqrt(0.123456), s21_sqrt(0.123456), ROUND_UP);
}
END_TEST

START_TEST(s21_sqrt_test_3) {
  ck_assert_ldouble_eq_tol(sqrt(0.0), s21_sqrt(0.0), ROUND_UP);
}
END_TEST

START_TEST(s21_sqrt_test_4) {
  ck_assert_ldouble_eq_tol(sqrt(s21_PI / 3), s21_sqrt(s21_PI / 3), ROUND_UP);
}
END_TEST

START_TEST(s21_sqrt_test_5) {
  ck_assert_ldouble_eq_tol(sqrt(s21_PI / 6), s21_sqrt(s21_PI / 6), ROUND_UP);
}
END_TEST

START_TEST(s21_sqrt_test_6) {
  ck_assert_ldouble_eq_tol(sqrt(s21_PI / 2), s21_sqrt(s21_PI / 2), ROUND_UP);
}
END_TEST

START_TEST(s21_sqrt_test_7) {
  ck_assert_ldouble_eq_tol(sqrt(2 * s21_PI / 3), s21_sqrt(2 * s21_PI / 3),
                           ROUND_UP);
}
END_TEST

START_TEST(s21_sqrt_test_8) {
  ck_assert_ldouble_eq_tol(sqrt(s21_PI), s21_sqrt(s21_PI), ROUND_UP);
}
END_TEST

START_TEST(s21_sqrt_test_9) {
  ck_assert_ldouble_eq_tol(sqrt(4.163435e-34), s21_sqrt(4.163435e-34), 1e-6);
}
END_TEST

START_TEST(s21_sqrt_test_10) { ck_assert_ldouble_nan(s21_sqrt(s21_NAN)); }
END_TEST

START_TEST(s21_sqrt_test_11) {
  ck_assert_ldouble_eq(sqrt(s21_INF), s21_sqrt(s21_INF));
}
END_TEST

START_TEST(s21_sqrt_test_12) { ck_assert_ldouble_nan(s21_sqrt(-1)); }
END_TEST

//////////////////////////////////////////////////////
//***********************ATAN************************//

START_TEST(s21_atan_test_1) {
  ck_assert_ldouble_eq_tol(atan(0.45), s21_atan(0.45), ROUND_UP);
}
END_TEST

START_TEST(s21_atan_test_2) {
  ck_assert_ldouble_eq_tol(atan(-0.45), s21_atan(-0.45), ROUND_UP);
}
END_TEST

START_TEST(s21_atan_test_3) {
  ck_assert_ldouble_eq_tol(atan(0), s21_atan(0), ROUND_UP);
}
END_TEST

START_TEST(s21_atan_test_4) {
  ck_assert_ldouble_eq_tol(atan(-0.0), s21_atan(-0.0), ROUND_UP);
}
END_TEST

START_TEST(s21_atan_test_5) {
  ck_assert_ldouble_eq_tol(atan(-1), s21_atan(-1), ROUND_UP);
}
END_TEST

START_TEST(s21_atan_test_6) {
  ck_assert_ldouble_eq_tol(atan(0.923456789012345678901234567890),
                           s21_atan(0.923456789012345678901234567890),
                           ROUND_UP);
}
END_TEST

START_TEST(s21_atan_test_7) { ck_assert_ldouble_nan(s21_atan(s21_NAN)); }
END_TEST

START_TEST(s21_atan_test_8) {
  ck_assert_ldouble_eq_tol(atan(s21_INF), s21_atan(s21_INF), ROUND_UP);
}
END_TEST

START_TEST(s21_atan_test_9) {
  ck_assert_ldouble_eq_tol(atan(-s21_INF), s21_atan(-s21_INF), ROUND_UP);
}
END_TEST

START_TEST(s21_atan_test_10) {
  double i = _i;
  ck_assert_ldouble_eq_tol(atan(i / 20.0), s21_atan(i / 20.0), ROUND_UP);
}
END_TEST

//////////////////////////////////////////////////////
//***********************ASIN************************//

START_TEST(s21_asin_test_1) {
  ck_assert_ldouble_eq_tol(asin(0.2), s21_asin(0.2), ROUND_UP);
}
END_TEST

START_TEST(s21_asin_test_2) {
  ck_assert_ldouble_eq_tol(asin(-0.2), s21_asin(-0.2), ROUND_UP);
}
END_TEST

START_TEST(s21_asin_test_3) {
  ck_assert_ldouble_eq_tol(asin(0.0), s21_asin(0.0), ROUND_UP);
}
END_TEST

START_TEST(s21_asin_test_4) {
  ck_assert_ldouble_eq_tol(asin(-0.0), s21_asin(-0.0), ROUND_UP);
}
END_TEST

START_TEST(s21_asin_test_5) {
  ck_assert_ldouble_eq_tol(asin(-1), s21_asin(-1), ROUND_UP);
}
END_TEST

START_TEST(s21_asin_test_6) { ck_assert_ldouble_nan(s21_asin(5)); }
END_TEST

START_TEST(s21_asin_test_7) { ck_assert_ldouble_nan(s21_asin(-5)); }
END_TEST

START_TEST(s21_asin_test_8) {
  ck_assert_ldouble_eq_tol(asin(0.123456789012345678901234567890),
                           s21_asin(0.123456789012345678901234567890),
                           ROUND_UP);
}
END_TEST

START_TEST(s21_asin_test_9) { ck_assert_ldouble_nan(s21_asin(s21_NAN)); }
END_TEST

START_TEST(s21_asin_test_10) { ck_assert_ldouble_nan(s21_asin(s21_INF)); }
END_TEST

//////////////////////////////////////////////////////
//***********************ACOS************************//

START_TEST(s21_acos_test_1) {
  ck_assert_ldouble_eq_tol(acos(0.999), s21_acos(0.999), ROUND_UP);
}
END_TEST

START_TEST(s21_acos_test_2) {
  ck_assert_ldouble_eq_tol(acos(1), s21_acos(1), ROUND_UP);
}
END_TEST

START_TEST(s21_acos_test_3) { ck_assert_ldouble_nan(s21_acos(3.0)); }
END_TEST

START_TEST(s21_acos_test_4) {
  ck_assert_ldouble_eq_tol(acos(0), s21_acos(0), ROUND_UP);
}
END_TEST

START_TEST(s21_acos_test_5) {
  ck_assert_ldouble_eq_tol(acos(-0.001), s21_acos(-0.001), ROUND_UP);
}
END_TEST

START_TEST(s21_acos_test_6) {
  ck_assert_ldouble_eq_tol(acos(-0.999), s21_acos(-0.999), ROUND_UP);
}
END_TEST

START_TEST(s21_acos_test_7) {
  ck_assert_ldouble_eq_tol(acos(-1 - 1e-16), s21_acos(-1 - 1e-16), ROUND_UP);
}
END_TEST

START_TEST(s21_acos_test_8) { ck_assert_ldouble_nan(s21_acos(1.001)); }
END_TEST

START_TEST(s21_acos_test_9) { ck_assert_ldouble_nan(s21_acos(-1.1)); }
END_TEST

START_TEST(s21_acos_test_10) { ck_assert_ldouble_nan(s21_acos(s21_NAN)); }
END_TEST

START_TEST(s21_acos_test_11) { ck_assert_ldouble_nan(s21_acos(s21_INF)); }
END_TEST

Suite *lib_suite(void) {
  Suite *s;
  s = suite_create("Func Check");

  TCase *tc_fabs;
  TCase *tc_floor;
  TCase *tc_fmod;
  TCase *tc_log;
  TCase *tc_pow;

  TCase *tc_abs;
  TCase *tc_exp;
  TCase *tc_ceil;
  TCase *tc_sin;
  TCase *tc_cos;
  TCase *tc_tan;
  TCase *tc_sqrt;
  TCase *tc_atan;
  TCase *tc_asin;
  TCase *tc_acos;

  tc_fabs = tcase_create("Fabs func");
  suite_add_tcase(s, tc_fabs);
  tcase_add_test(tc_fabs, s21_fabs_test_1);
  tcase_add_test(tc_fabs, s21_fabs_test_2);
  tcase_add_test(tc_fabs, s21_fabs_test_3);
  tcase_add_test(tc_fabs, s21_fabs_test_4);
  tcase_add_test(tc_fabs, s21_fabs_test_5);
  tcase_add_test(tc_fabs, s21_fabs_test_6);
  tcase_add_test(tc_fabs, s21_fabs_test_7);
  tcase_add_test(tc_fabs, s21_fabs_test_8);
  tcase_add_test(tc_fabs, s21_fabs_test_9);
  tcase_add_test(tc_fabs, s21_fabs_test_10);

  tc_floor = tcase_create("Floor func");
  suite_add_tcase(s, tc_floor);
  tcase_add_test(tc_floor, s21_floor_test_1);
  tcase_add_test(tc_floor, s21_floor_test_2);
  tcase_add_test(tc_floor, s21_floor_test_3);
  tcase_add_test(tc_floor, s21_floor_test_4);
  tcase_add_test(tc_floor, s21_floor_test_5);
  tcase_add_test(tc_floor, s21_floor_test_6);
  tcase_add_test(tc_floor, s21_floor_test_7);
  tcase_add_test(tc_floor, s21_floor_test_8);
  tcase_add_test(tc_floor, s21_floor_test_9);
  tcase_add_test(tc_floor, s21_floor_test_10);
  tcase_add_test(tc_floor, s21_floor_test_11);

  tc_fmod = tcase_create("Fmod func");
  suite_add_tcase(s, tc_fmod);
  tcase_add_test(tc_fmod, s21_fmod_test_1);
  tcase_add_test(tc_fmod, s21_fmod_test_2);
  tcase_add_test(tc_fmod, s21_fmod_test_3);
  tcase_add_test(tc_fmod, s21_fmod_test_4);
  tcase_add_test(tc_fmod, s21_fmod_test_5);
  tcase_add_test(tc_fmod, s21_fmod_test_6);
  tcase_add_test(tc_fmod, s21_fmod_test_7);
  tcase_add_test(tc_fmod, s21_fmod_test_8);
  tcase_add_test(tc_fmod, s21_fmod_test_9);
  tcase_add_test(tc_fmod, s21_fmod_test_10);

  tc_log = tcase_create("Log func");
  suite_add_tcase(s, tc_log);
  tcase_add_test(tc_log, s21_log_test_1);
  tcase_add_test(tc_log, s21_log_test_2);
  tcase_add_test(tc_log, s21_log_test_3);
  tcase_add_test(tc_log, s21_log_test_4);
  tcase_add_test(tc_log, s21_log_test_5);
  tcase_add_test(tc_log, s21_log_test_6);
  tcase_add_test(tc_log, s21_log_test_7);
  tcase_add_test(tc_log, s21_log_test_8);
  tcase_add_test(tc_log, s21_log_test_9);
  tcase_add_test(tc_log, s21_log_test_10);
  tcase_add_test(tc_log, s21_log_test_11);

  tc_pow = tcase_create("Pow func");
  suite_add_tcase(s, tc_pow);
  tcase_add_test(tc_pow, s21_pow_test_1);
  tcase_add_test(tc_pow, s21_pow_test_2);
  tcase_add_test(tc_pow, s21_pow_test_3);
  tcase_add_test(tc_pow, s21_pow_test_4);
  tcase_add_test(tc_pow, s21_pow_test_5);
  tcase_add_test(tc_pow, s21_pow_test_6);
  tcase_add_test(tc_pow, s21_pow_test_7);
  tcase_add_test(tc_pow, s21_pow_test_8);
  tcase_add_test(tc_pow, s21_pow_test_9);
  tcase_add_test(tc_pow, s21_pow_test_10);
  tcase_add_test(tc_pow, s21_pow_test_11);
  tcase_add_test(tc_pow, s21_pow_test_12);
  tcase_add_test(tc_pow, s21_pow_test_13);

  tc_abs = tcase_create("Abs func");
  suite_add_tcase(s, tc_abs);
  tcase_add_test(tc_abs, s21_abs_test_1);
  tcase_add_test(tc_abs, s21_abs_test_2);
  tcase_add_test(tc_abs, s21_abs_test_3);
  tcase_add_test(tc_abs, s21_abs_test_4);
  tcase_add_test(tc_abs, s21_abs_test_5);
  tcase_add_test(tc_abs, s21_abs_test_6);
  tcase_add_test(tc_abs, s21_abs_test_7);
  tcase_add_test(tc_abs, s21_abs_test_8);
  tcase_add_test(tc_abs, s21_abs_test_9);
  tcase_add_test(tc_abs, s21_abs_test_10);

  tc_exp = tcase_create("Exp func");
  suite_add_tcase(s, tc_exp);
  tcase_add_test(tc_exp, s21_exp_test_1);
  tcase_add_test(tc_exp, s21_exp_test_2);
  tcase_add_test(tc_exp, s21_exp_test_3);
  tcase_add_test(tc_exp, s21_exp_test_4);
  tcase_add_test(tc_exp, s21_exp_test_5);
  tcase_add_test(tc_exp, s21_exp_test_6);
  tcase_add_test(tc_exp, s21_exp_test_7);
  tcase_add_test(tc_exp, s21_exp_test_8);
  tcase_add_test(tc_exp, s21_exp_test_9);
  tcase_add_test(tc_exp, s21_exp_test_10);
  tcase_add_test(tc_exp, s21_exp_test_11);
  tcase_add_test(tc_exp, s21_exp_test_12);
  tcase_add_test(tc_exp, s21_exp_test_13);

  tc_ceil = tcase_create("Ceil func");
  suite_add_tcase(s, tc_ceil);
  tcase_add_test(tc_ceil, s21_ceil_test_1);
  tcase_add_test(tc_ceil, s21_ceil_test_2);
  tcase_add_test(tc_ceil, s21_ceil_test_3);
  tcase_add_test(tc_ceil, s21_ceil_test_4);
  tcase_add_test(tc_ceil, s21_ceil_test_5);
  tcase_add_test(tc_ceil, s21_ceil_test_6);
  tcase_add_test(tc_ceil, s21_ceil_test_7);
  tcase_add_test(tc_ceil, s21_ceil_test_8);
  tcase_add_test(tc_ceil, s21_ceil_test_9);
  tcase_add_test(tc_ceil, s21_ceil_test_10);

  tc_sin = tcase_create("Sin func");
  suite_add_tcase(s, tc_sin);
  tcase_add_test(tc_sin, s21_sin_test_1);
  tcase_add_test(tc_sin, s21_sin_test_2);
  tcase_add_test(tc_sin, s21_sin_test_3);
  tcase_add_test(tc_sin, s21_sin_test_4);
  tcase_add_test(tc_sin, s21_sin_test_5);
  tcase_add_test(tc_sin, s21_sin_test_6);
  tcase_add_test(tc_sin, s21_sin_test_7);
  tcase_add_loop_test(tc_sin, s21_sin_test_8, -10, 10);
  tcase_add_loop_test(tc_sin, s21_sin_test_9, -10, 10);
  tcase_add_test(tc_sin, s21_sin_test_10);

  tc_cos = tcase_create("Cos func");
  suite_add_tcase(s, tc_cos);
  tcase_add_test(tc_cos, s21_cos_test_1);
  tcase_add_test(tc_cos, s21_cos_test_2);
  tcase_add_test(tc_cos, s21_cos_test_3);
  tcase_add_test(tc_cos, s21_cos_test_4);
  tcase_add_test(tc_cos, s21_cos_test_5);
  tcase_add_test(tc_cos, s21_cos_test_6);
  tcase_add_test(tc_cos, s21_cos_test_7);
  tcase_add_test(tc_cos, s21_cos_test_8);
  tcase_add_test(tc_cos, s21_cos_test_9);
  tcase_add_test(tc_cos, s21_cos_test_10);
  tcase_add_test(tc_cos, s21_cos_test_11);
  tcase_add_loop_test(tc_cos, s21_cos_test_12, -10, 10);

  tc_tan = tcase_create("Tan func");
  suite_add_tcase(s, tc_tan);
  tcase_add_test(tc_tan, s21_tan_test_1);
  tcase_add_test(tc_tan, s21_tan_test_2);
  tcase_add_test(tc_tan, s21_tan_test_3);
  tcase_add_test(tc_tan, s21_tan_test_4);
  tcase_add_test(tc_tan, s21_tan_test_5);
  tcase_add_test(tc_tan, s21_tan_test_6);
  tcase_add_test(tc_tan, s21_tan_test_7);
  tcase_add_test(tc_tan, s21_tan_test_8);
  tcase_add_test(tc_tan, s21_tan_test_9);
  tcase_add_test(tc_tan, s21_tan_test_10);
  tcase_add_test(tc_tan, s21_tan_test_11);
  tcase_add_test(tc_tan, s21_tan_test_12);
  tcase_add_loop_test(tc_tan, s21_tan_test_13, -10, 10);

  tc_sqrt = tcase_create("Sqrt func");
  suite_add_tcase(s, tc_sqrt);
  tcase_add_test(tc_sqrt, s21_sqrt_test_1);
  tcase_add_test(tc_sqrt, s21_sqrt_test_2);
  tcase_add_test(tc_sqrt, s21_sqrt_test_3);
  tcase_add_test(tc_sqrt, s21_sqrt_test_4);
  tcase_add_test(tc_sqrt, s21_sqrt_test_5);
  tcase_add_test(tc_sqrt, s21_sqrt_test_6);
  tcase_add_test(tc_sqrt, s21_sqrt_test_7);
  tcase_add_test(tc_sqrt, s21_sqrt_test_8);
  tcase_add_test(tc_sqrt, s21_sqrt_test_9);
  tcase_add_test(tc_sqrt, s21_sqrt_test_10);
  tcase_add_test(tc_sqrt, s21_sqrt_test_11);
  tcase_add_test(tc_sqrt, s21_sqrt_test_12);

  tc_atan = tcase_create("Atan func");
  suite_add_tcase(s, tc_atan);
  tcase_add_test(tc_atan, s21_atan_test_1);
  tcase_add_test(tc_atan, s21_atan_test_2);
  tcase_add_test(tc_atan, s21_atan_test_3);
  tcase_add_test(tc_atan, s21_atan_test_4);
  tcase_add_test(tc_atan, s21_atan_test_5);
  tcase_add_test(tc_atan, s21_atan_test_6);
  tcase_add_test(tc_atan, s21_atan_test_7);
  tcase_add_test(tc_atan, s21_atan_test_8);
  tcase_add_test(tc_atan, s21_atan_test_9);
  tcase_add_loop_test(tc_atan, s21_atan_test_10, -10, 10);

  tc_asin = tcase_create("Asin func");
  suite_add_tcase(s, tc_asin);
  tcase_add_test(tc_asin, s21_asin_test_1);
  tcase_add_test(tc_asin, s21_asin_test_2);
  tcase_add_test(tc_asin, s21_asin_test_3);
  tcase_add_test(tc_asin, s21_asin_test_4);
  tcase_add_test(tc_asin, s21_asin_test_5);
  tcase_add_test(tc_asin, s21_asin_test_6);
  tcase_add_test(tc_asin, s21_asin_test_7);
  tcase_add_test(tc_asin, s21_asin_test_8);
  tcase_add_test(tc_asin, s21_asin_test_9);
  tcase_add_test(tc_asin, s21_asin_test_10);

  tc_acos = tcase_create("Acos func");
  suite_add_tcase(s, tc_acos);
  tcase_add_test(tc_acos, s21_acos_test_1);
  tcase_add_test(tc_acos, s21_acos_test_2);
  tcase_add_test(tc_acos, s21_acos_test_3);
  tcase_add_test(tc_acos, s21_acos_test_4);
  tcase_add_test(tc_acos, s21_acos_test_5);
  tcase_add_test(tc_acos, s21_acos_test_6);
  tcase_add_test(tc_acos, s21_acos_test_7);
  tcase_add_test(tc_acos, s21_acos_test_8);
  tcase_add_test(tc_acos, s21_acos_test_9);
  tcase_add_test(tc_acos, s21_acos_test_10);
  tcase_add_test(tc_acos, s21_acos_test_11);

  return s;
}

int main(void) {
  Suite *s;
  SRunner *sr;

  s = lib_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  srunner_free(sr);
  return 0;
}