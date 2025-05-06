/*!
 * \file
 * \brief Back headerfile.
 *
 * Включает в себя все библиотеки, структуры и функции объявления, используемые
 * в бэкенде проекта.
 */
#ifndef CALCULATE_H
#define CALCULATE_H

#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846
#define eps 1e-7

// stack
typedef struct Stack_s Stack_t;
/*!
 * \brief Структура, представляющая стек чисел и char
 *
 * \param data - char
 * \param value - значение
 * \param prev - указатель вершины стека
 */
struct Stack_s {
  char data;
  double value;
  Stack_t *prev;
};

/*!
 * \brief Функция для извлечения из стэка элемента
 */
void pop(Stack_t **stack, char *symb, double *num);
/*!
 * \brief Функция для помещения в стэк элемента
 */
void push(Stack_t **stack, char symb, double num);
/*!
 * \brief Переворачивает стек после добавления в него выражения
 */
void reverse_stack(Stack_t *old, Stack_t **new);
/*!
 * \brief Функция для очистки стэка
 */
void destroy_stack(Stack_t *st);

// calculate
/*!
 * \brief Функция для разбора корректности строки(примера) и записи элементов в
 * стэк. \param[in] str Введенная строка выражения. \param[out] stack Полученный
 * стэк элементов. \return Функция возвращает код состояния;  PARSING_ERROR 20 –
 * некорректное вводное выражение, 0 – корректное выражение и запись эленментов
 * в стэк.
 */
int pars(char *str, Stack_t **stack);
/*!
 * \brief Базовая функция для перевода из инфиксной нотации в польскую нотацию и
 * получения результата примера.
 * \param[in] stack Строка выражения.
 * \param[in] x Подстановочное значение переменной x double тип.
 * \param[out] answer Результат вычисления выражения double тип.
 * \return Функция возвращает код состояния;  0 – успешно, и другие макросы
 * ошибок вычисления.
 */
int calc(Stack_t *stack, double x, double *answer);
/*!
 * \brief Функция для вызова функций pars и calc.
 */
int solve_expression(char *expression, double x, double *answer);
/*!
 * \brief Макрос ошибки, когда степень нуля не определена для отрицательного
 * показателя
 */
#define POW_ZERO_NEG_ERROR 10
/*!
 * \brief Макрос ошибки, когда деление на ноль не определено
 */
#define DIVISION_ZERO_ERROR 11
/*!
 * \brief Макрос ошибки, когда извлечение корня из отрицательного числа не
 * допускается
 */
#define NEG_ROOT_ERROR 12
/*!
 * \brief Макрос ошибки, когда касательная не определена
 */
#define INF_TAN_ERROR 13
/*!
 * \brief Макрос ошибки, когда логарифм не определен для неположительных чисел
 */
#define NON_POS_LOG_ERROR 14
/*!
 * \brief Макрос ошибки, когда обратный косинус не определен для значений за
 * пределами [-1, 1]
 */
#define ARCCOS_RANGE_ERROR 15
/*!
 * \brief Макрос ошибки, когда обратный синус не определен для значений за
 * пределами [-1, 1]
 */
#define ARCSIN_RANGE_ERROR 16
/*!
 * \brief Макрос ошибки, когда введено слишком много аргументов для примера
 */
#define TOO_MUCH_ARGS_ERROR 17
/*!
 * \brief Макрос ошибки, когда введен неверный пример
 */
#define PARSING_ERROR 20

//////////////bonus 1//////////////
/*!
 * \brief Базовая функция для перевода из инфиксной нотации в польскую нотацию и
 * получения результата примера.
 * \param[in] sum Строка выражения.double тип.
 * \param[in] period Подстановочное значение переменной x
 * \param[in] bet Подстановочное значение переменной x
 * \param[in] flag Подстановочное значение переменной x
 * \param[in] payment_month Подстановочное значение переменной x
 * \param[out] overpayment Результат вычисления выражения double тип.
 * \param[out] total_payment Результат вычисления выражения double тип.
 * \return Функция возвращает код состояния;  0 – успешно, и другие макросы
 * ошибок вычисления.
 */
int calc_credit(double sum, int period, double bet, int flag,
                double *payment_month, double *overpayment,
                double *total_payment);

#define CREDIT_INPUT_ERROR 30
#endif
