#include "s21_math.h"

long double s21_fabs(double x) {
  long double res = 0;

  if (s21_is_nan(x)) {
    res = s21_NAN;
  } else if (s21_is_inf(x)) {
    res = s21_INF;
  } else if (x == 0.0 || x == -0.0) {
    res = 0.0;
  } else {
    res = x < 0 ? -x : x;
  }
  return res;
}

long double s21_floor(double x) {
  long double res = (long long int)x;

  if (s21_is_inf(x) || x == 0 || x == -0.0 || s21_is_nan(x)) {
    res = x;
  } else {
    if (s21_fabs(x - res) > 0.0 && s21_fabs(x) > 0.0)
      if (x < 0.0) {
        res -= 1;
      }
  }
  return res;
}

long double s21_fmod(double x, double y) {
  long double res = 0;
  if (y == 0 || x == s21_INF || x == -s21_INF) {
    return s21_NAN;
  }
  if (y == s21_INF || y == -s21_INF) {
    return x;
  }
  long long int mod = 0;
  mod = x / y;
  res = (long double)x - mod * (long double)y;
  if (x < 0 && res == 0.0) res = -0.0;
  return res;
}

long double s21_log(double x) {
  long double res = 0;

  if (x < 0 || s21_is_nan(x) || (s21_is_inf(x) && x < 0)) {
    res = s21_NAN;
  } else if (x == 0) {
    res = -s21_INF;
  } else if (s21_is_inf(x)) {
    res = s21_INF;
  } else if (x == 1) {
    res = 0;
  } else {
    int accuracy = 0;
    double match = 0;

    for (; x >= s21_EXP; x /= s21_EXP, accuracy++) {
      continue;
    }
    for (int i = 0; i < 100; i++) {
      match = res;
      res = match + 2 * (x - s21_exp(match)) / (x + s21_exp(match));
    }
    res = res + accuracy;
  }
  return res;
}

long double s21_pow(double base, double exp) {
  long double res = 0;
  int check = 0;

  if (base == 1 || exp == 0 || (base == -1 && (s21_is_inf(exp)))) {
    res = 1;
  } else if ((s21_fabs(base) < 1 && (s21_is_inf(exp) && exp < 0)) ||
             (s21_fabs(base) > 1 && s21_is_inf(exp))) {
    res = s21_INF;
  } else if ((base == 0 && exp > 0) ||
             (s21_fabs(base) > 1 && (s21_is_inf(exp) && exp < 0)) ||
             (s21_fabs(base) < 1 && s21_is_inf(exp))) {
    res = 0;
  } else if ((base < 0 && (int)exp - exp != 0) ||
             (base != base && exp != exp)) {
    res = s21_NAN;
  } else if (exp < 0 && base == 0) {
    res = s21_INF;
  } else if ((s21_is_inf(base) && base < 0) && (exp > 0 && (int)exp % 2 != 0)) {
    res = -s21_INF;
  } else {
    if (base < 0) {
      if ((int)exp % 2 != 0) {
        check = 1;
      }
      base = s21_fabs(base);
    }
    if (check == 1) {
      res = -s21_exp(exp * s21_log(base));
    } else {
      res = s21_exp(exp * s21_log(base));
    }
  }
  return res;
}

int s21_abs(int x) { return x >= 0 ? x : -x; }

long double s21_exp(double x) {
  long double res = 0.0;

  if (s21_is_inf(x)) {
    if (x < 0) {
      res = 0.0;
    } else {
      res = s21_INF;
    }
  } else if (s21_is_nan(x)) {
    res = s21_NAN;
  } else if (x >= 746) {
    res = s21_INF;
  } else if (x > -746 && x < 746) {
    long double term = 1.0;
    int n = 1;
    char is_negative = x < 0;
    if (is_negative) {
      x = -x;
    }
    while (term > s21_EPS) {
      res += term;
      term *= x / n;
      n++;
    }
    if (is_negative) {
      res = 1 / res;
    }
  }
  return res;
}

long double s21_ceil(double x) {
  long double res = (int)x;

  if (s21_is_inf(x) || x == 0 || s21_is_nan(x)) {
    res = x;
  } else {
    if (s21_fabs(x) > 0 && x != res) {
      if (x > 0) {
        res += 1;
      }
    }
  }
  return res;
}

long double s21_sqrt(double x) {
  long double res = 0;

  if (x < 0.0) {
    res = -s21_NAN;
  } else if (x == 0.0 || x == 1.0) {
    res = x;
  } else {
    res = s21_pow(x, 0.5);
  }
  return res;
}

long double s21_sin(double x) {
  long double res;

  if (s21_is_inf(x) || s21_is_nan(x)) {
    res = s21_NAN;
  } else {
    x = s21_fmod(x, 2 * s21_PI);
    while (x > s21_PI) {
      x -= 2 * s21_PI;
    }

    while (x < -s21_PI) {
      x += 2 * s21_PI;
    }

    res = x;
    int fact = 1;
    long double temp = x;
    while (s21_fabs(temp) > s21_EPS) {
      temp = (-temp * x * x) / ((2 * fact + 1) * (2 * fact));
      res += temp;
      fact++;
    }
  }
  return res;
}

long double s21_cos(double x) {
  double pow = 0.0;
  long double res = 1.0;
  long double num = 1.0;
  long double x_in_range = s21_fmod(x, 2.0 * s21_PI);

  if (s21_is_nan(x) || s21_fabs(x) == s21_INF) {
    res = s21_NAN;
  } else {
    while (s21_fabs(num / res) > s21_EPS) {
      pow = pow + 2.0;
      num = (-num * x_in_range * x_in_range) / ((pow - 1.0) * (pow));
      res += num;
    }
  }
  return res;
}

long double s21_tan(double x) {
  long double sin_val = s21_sin(x);
  long double cos_val = s21_cos(x);
  long double res = 0.0;

  if (!s21_is_inf(sin_val) && !s21_is_inf(cos_val) &&
      (!s21_is_nan(sin_val) && !s21_is_nan(cos_val))) {
    res = sin_val / cos_val;
  } else {
    res = s21_NAN;
  }
  return res;
}

long double s21_atan(double x) {
  long double res = 0.0;

  if (!s21_is_nan(x)) {
    if (!s21_is_inf(x)) {
      long double abs_x = s21_fabs(x);
      long double pow_x = s21_pow(x, 1);
      long double pow_neg_x = s21_pow(x, -1);
      long double sqrt_x_2 = s21_sqrt(s21_pow(x, 2));

      if (abs_x < 1) {
        int i = 0;
        while (i < 5000) {
          res += (s21_pow(-1, i) * pow_x) / (1 + 2 * i);
          pow_x *= x * x;
          i++;
        }
      } else {
        long double tmp = 0.0;
        int i = 0;
        while (i < 250000) {
          tmp += (s21_pow(-1, i) * pow_neg_x) / (1 + 2 * i);
          pow_neg_x /= x * x;
          i++;
        }
        res += ((s21_PI * sqrt_x_2) / (2 * x)) - tmp;
      }
    } else {
      if (x == s21_INF) {
        res = s21_PI / 2;
      } else {
        res = -s21_PI / 2;
      }
    }
  } else {
    res = s21_NAN;
  }
  return res;
}

long double s21_asin(double x) {
  double res = 0;

  if (x != x || x > 1.0 || x < -1.0) {
    res = s21_NAN;
  } else if (x == 1) {
    res = s21_PI / 2;
  } else if (x == -1) {
    res = -s21_PI / 2;
  } else {
    res = s21_atan(x / s21_sqrt(1 - x * x));
  }
  return res;
}

long double s21_acos(double x) {
  long double res = s21_NAN;

  if (x < -1 || x > 1) {
    res = s21_NAN;
  } else if (x == 1) {
    res = 0;
  } else if (x == -1) {
    res = s21_PI;
  } else if (x < 1 && x >= 0) {
    res = s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (x < 0 && x > -1) {
    res = s21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  }
  return res;
}