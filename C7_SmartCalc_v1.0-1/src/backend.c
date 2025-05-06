#include "calculate.h"

int solve_expression(char *expression, double x, double *answer) {
  int return_code = EXIT_SUCCESS;
  Stack_t *stack = NULL;
  return_code = pars(expression, &stack);
  if (!return_code) {
    Stack_t *reversed_stack = NULL;
    reverse_stack(stack, &reversed_stack);
    return_code = calc(reversed_stack, x, answer);
    destroy_stack(reversed_stack);
  }
  destroy_stack(stack);
  return return_code;
}

int calc(Stack_t *stack, double x, double *answer) {
  char symb;
  double num;
  Stack_t *ptr = stack;
  Stack_t *temp_stack = NULL;
  int rc = EXIT_SUCCESS;
  while (ptr != NULL) {
    num = ptr->value;
    symb = ptr->data;
    switch (symb) {
      case '+': {
        double num1, num2;
        char symb1, symb2;
        pop(&temp_stack, &symb1, &num1);
        if (!temp_stack) {
          rc = PARSING_ERROR;
          ptr = NULL;
          break;
        }
        pop(&temp_stack, &symb2, &num2);
        push(&temp_stack, 'd', num1 + num2);
        break;
      }
      case '-': {
        double num1, num2;
        char symb1, symb2;
        pop(&temp_stack, &symb1, &num1);
        if (!temp_stack) {
          rc = PARSING_ERROR;
          ptr = NULL;
          break;
        }
        pop(&temp_stack, &symb2, &num2);
        push(&temp_stack, 'd', num2 - num1);
        break;
      }
      case '_': {
        double num1;
        char symb1;
        if (!temp_stack) {
          rc = PARSING_ERROR;
          ptr = NULL;
          break;
        }
        pop(&temp_stack, &symb1, &num1);
        push(&temp_stack, 'd', -num1);
        break;
      }
      case '&': {
        double num1;
        char symb1;
        if (!temp_stack) {
          rc = PARSING_ERROR;
          ptr = NULL;
          break;
        }
        pop(&temp_stack, &symb1, &num1);
        push(&temp_stack, 'd', +num1);
        break;
      }
      case '*': {
        double num1, num2;
        char symb1, symb2;
        pop(&temp_stack, &symb1, &num1);
        if (!temp_stack) {
          rc = PARSING_ERROR;
          ptr = NULL;
          break;
        }
        pop(&temp_stack, &symb2, &num2);
        push(&temp_stack, 'd', num1 * num2);
        break;
      }
      case '^': {
        double num1, num2;
        char symb1, symb2;
        pop(&temp_stack, &symb1, &num1);
        if (!temp_stack) {
          rc = PARSING_ERROR;
          ptr = NULL;
          break;
        }
        pop(&temp_stack, &symb2, &num2);
        if (fabs(num2) < eps && num1 < 0) {
          rc = POW_ZERO_NEG_ERROR;
          ptr = NULL;
          break;
        }
        push(&temp_stack, 'd', pow(num2, num1));
        break;
      }
      case '/': {
        double num1, num2;
        char symb1, symb2;
        pop(&temp_stack, &symb1, &num1);
        if (!temp_stack) {
          rc = PARSING_ERROR;
          ptr = NULL;
          break;
        }
        pop(&temp_stack, &symb2, &num2);
        if (fabs(num1) < eps) {
          rc = DIVISION_ZERO_ERROR;
          ptr = NULL;
          break;
        }
        push(&temp_stack, 'd', num2 / num1);
        break;
      }
      case 'm': {
        double num1, num2;
        char symb1, symb2;
        pop(&temp_stack, &symb1, &num1);
        if (!temp_stack) {
          rc = PARSING_ERROR;
          ptr = NULL;
          break;
        }
        pop(&temp_stack, &symb2, &num2);
        if (fabs(num1) < eps) {
          rc = DIVISION_ZERO_ERROR;
          ptr = NULL;
          break;
        }
        push(&temp_stack, 'd', fmod(num2, num1));
        break;
      }
      case 's': {
        double num1;
        char symb1;
        if (!temp_stack) {
          rc = PARSING_ERROR;
          ptr = NULL;
          break;
        }
        pop(&temp_stack, &symb1, &num1);
        push(&temp_stack, 'd', sin(num1));
        break;
      }
      case 'q': {
        double num1;
        char symb1;
        if (!temp_stack) {
          rc = PARSING_ERROR;
          ptr = NULL;
          break;
        }
        pop(&temp_stack, &symb1, &num1);
        if (num1 < 0.0) {
          rc = NEG_ROOT_ERROR;
          ptr = NULL;
          break;
        }
        push(&temp_stack, 'd', sqrt(num1));
        break;
      }
      case 't': {
        double num1;
        char symb1;
        if (!temp_stack) {
          rc = PARSING_ERROR;
          ptr = NULL;
          break;
        }
        pop(&temp_stack, &symb1, &num1);
        if (fabs(fmod(num1, PI) - PI / 2) < eps ||
            fabs(fmod(num1, PI) + PI / 2) < eps) {
          rc = INF_TAN_ERROR;
          ptr = NULL;
          break;
        }
        push(&temp_stack, 'd', tan(num1));
        break;
      }
      case 'n': {
        double num1;
        char symb1;
        if (!temp_stack) {
          rc = PARSING_ERROR;
          ptr = NULL;
          break;
        }
        pop(&temp_stack, &symb1, &num1);
        if (num1 <= 0.0) {
          rc = NON_POS_LOG_ERROR;
          ptr = NULL;
          break;
        }
        push(&temp_stack, 'd', log(num1));
        break;
      }
      case 'c': {
        double num1;
        char symb1;
        if (!temp_stack) {
          rc = PARSING_ERROR;
          ptr = NULL;
          break;
        }
        pop(&temp_stack, &symb1, &num1);
        push(&temp_stack, 'd', cos(num1));
        break;
      }
      case 'a': {
        double num1;
        char symb1;
        if (!temp_stack) {
          rc = PARSING_ERROR;
          ptr = NULL;
          break;
        }
        pop(&temp_stack, &symb1, &num1);
        if (num1 > 1.0) {
          rc = ARCSIN_RANGE_ERROR;
          ptr = NULL;
          break;
        }
        push(&temp_stack, 'd', asin(num1));
        break;
      }
      case 'k': {
        double num1;
        char symb1;
        if (!temp_stack) {
          rc = PARSING_ERROR;
          ptr = NULL;
          break;
        }
        pop(&temp_stack, &symb1, &num1);
        if (fabs(num1) > 1.0) {
          rc = ARCCOS_RANGE_ERROR;
          ptr = NULL;
          break;
        }
        push(&temp_stack, 'd', acos(num1));
        break;
      }
      case 'g': {
        double num1;
        char symb1;
        if (!temp_stack) {
          rc = PARSING_ERROR;
          ptr = NULL;
          break;
        }
        pop(&temp_stack, &symb1, &num1);
        push(&temp_stack, 'd', atan(num1));
        break;
      }
      case 'l': {
        double num1;
        char symb1;
        if (!temp_stack) {
          rc = PARSING_ERROR;
          ptr = NULL;
          break;
        }
        pop(&temp_stack, &symb1, &num1);
        if (num1 <= 0.0) {
          rc = NON_POS_LOG_ERROR;
          ptr = NULL;
          break;
        }
        push(&temp_stack, 'd', log10(num1));
        break;
      }
      case 'd': {
        push(&temp_stack, 'd', num);
        break;
      }
      case 'x': {
        push(&temp_stack, 'd', x);
        break;
      }
    }
    if (ptr) ptr = ptr->prev;
  }
  if (!rc) pop(&temp_stack, &symb, &num);
  *answer = num;
  destroy_stack(temp_stack);
  return rc;
}

//////////////////bonus1/////////////////
int calc_credit(double sum, int period, double bet, int flag,
                double *payment_month, double *overpayment,
                double *total_payment) {
  if ((flag != 0 && flag != 1) || sum <= 0 || bet <= 0.0 || period <= 0 ||
      period > 600)
    return CREDIT_INPUT_ERROR;
  double monthly_interest_rate = bet / 100.0 / 12;
  if (flag == 0) {
    double pow_factor = pow(1 + monthly_interest_rate, period);
    double p_month =
        sum * monthly_interest_rate * pow_factor / (pow_factor - 1);
    for (int i = 0; i < period; ++i) payment_month[i] = p_month;
    *total_payment = *payment_month * period;
    *overpayment = *total_payment - sum;
  } else {
    *payment_month = 0.0;
    *total_payment = 0.0;
    *overpayment = 0.0;
    double principal_payment = sum / period;
    for (int i = 0; i < period; i++) {
      double interest_payment = sum * monthly_interest_rate;
      sum -= principal_payment;
      payment_month[i] = principal_payment + interest_payment;
      *overpayment += interest_payment;
      *total_payment += payment_month[i];
    }
  }
  return EXIT_SUCCESS;
}
