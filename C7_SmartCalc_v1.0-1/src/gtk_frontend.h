/*!
 * \file
 * \brief Front headerfile.
 *
 * Включает в себя все библиотеки, структуры и функции объявления, используемые
 * в бэкенде проекта.
 */
#ifndef GTK_FRONTEND_H
#define GTK_FRONTEND_H

#include <cairo.h>
#include <ctype.h>
#include <gtk/gtk.h>
#include <locale.h>
#include <pango/pangocairo.h>

#define SIZE 256
#define WIDTH 600
#define HEIGHT 600

/*!
 * \brief Структура, для хранения виджетов GTK.
 *
 * \param window - GtkWidget объект для главного окна.
 * \param grid - Объект GtkWidget для макета сетки.
 * \param box - Объект GtkWidget для ввода выражения.
 * \param button - Массив указателей на объекты GtkWidget для кнопок.
 * \param button_x - Объект GtkWidget для ввода параметра Х.
 */
typedef struct {
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *box;
  GtkWidget *button[35];
  GtkWidget *button_x;
} Calc;
/*!
 * \brief Структура, для хранения виджетов GTK модального окна построения
 * графика.
 *
 * \param dialog - GtkWidget объект для модального окна.
 * \param grid_1 - Объект GtkWidget для макета сетки.
 * \param x_min - Объект GtkWidget для выбора отображаемой области графика.
 * \param x_max - Объект GtkWidget для выбора отображаемой области графика.
 * \param у_min - Объект GtkWidget для выбора отображаемой области графика.
 * \param у_max - Объект GtkWidget для выбора отображаемой области графика.
 * \param content_area - Область содержимого диалога.
 * \param drawing_area - Область для рисования графика.
 * \param button_b - Кнопка для перерисовки графика с заданными параметрами x и
 * у. \param entry - GtkWidget объект для отображения названия функции.
 */
typedef struct {
  GtkWidget *dialog;
  GtkWidget *grid_1;
  GtkWidget *x_min;
  GtkWidget *x_max;
  GtkWidget *y_min;
  GtkWidget *y_max;
  GtkWidget *content_area;
  GtkWidget *drawing_area;
  GtkWidget *button_b;
  GtkWidget *entry;
} Modal;
/*!
 * \brief Структура, для хранения свойств графика при отрисовки графика.
 *
 * \param cr - Объявляем контекст Cairo.
 * \param x_min - Заданное минимальное значение для оси Х.
 * \param x_max - Заданное максимальное значение для оси Х.
 * \param у_min - Заданное минимальное значение для оси У.
 * \param у_max - Заданное минимальное значение для оси У.
 * \param dx - Масштабирование оси х.
 * \param dy - Масштабирование оси у.
 * \param right_limit - Правая граница при отрисовки графика.
 * \param left_limit - Левая граница при отрисовки графика.
 * \param lower_limit - Нижняя граница при отрисовки графика.
 * \param upper_limit - Верхняя граница при отрисовки графика.
 */
typedef struct {
  cairo_t *cr;
  gdouble min_x;
  gdouble max_x;
  gdouble min_y;
  gdouble max_y;
  gdouble dx;
  gdouble dy;
  gdouble right_limit;
  gdouble left_limit;
  gdouble lower_limit;
  gdouble upper_limit;
} Graph_properties;

///////////////////////////bonus 1
/*!
 * \brief Структура, для хранения параметров кредитного калькулятора.
 *
 * \param flag - Флаг, для определения типа ежемесячных платежей.
 * \param payment_month - Массив для хранения ежемесячных платежей.
 * \param overpayment_field - Поле для отображения переплаты.
 * \param total_payment_field - Поле для отображения итогового платежа.
 * \param payment_month_field - Поле ежемесячный платеж.
 * \param total_amount - Поле для установки значения суммы кредита.
 * \param term - Поле для установки значения срока кредита.
 * \param interest - Поле для установки значения процентной ставки.
 * \param calculate - Кнопка для запуска расчета.
 */
typedef struct {
  int flag;
  double payment_month[601];
  GtkTextBuffer *text_field;
  GtkWidget *overpayment_field;
  GtkWidget *total_payment_field;
  GtkWidget *payment_month_field;
  GtkWidget *total_amount;
  GtkWidget *term;
  GtkWidget *interest;
  GtkWidget *calculate;
} Credit;

///////////////////////////window_calc
/*!
 * \brief Функция обратного вызова для сигнала активации GtkApplication
 */
void activate(GtkApplication *app, gpointer data);
/*!
 * \brief Функция открытия диалогового окна
 */
void modal_window();
/*!
 * \brief Функция обратного вызова для отображения нажатых кнопок???
 */
void display(GtkButton *button, gpointer data);
/*!
 * \brief Функция обратного вызова для решения выражения(примера)
 */
void button_calc(GtkWidget *box, gpointer data);
/*!
 * \brief Функция обратного вызова для очистки дисплея
 */
void button_delete();
/*!
 * \brief Функция обратного вызова для удаления одного символа с дисплея
 */
void button_delete_char();

///////////////////////////graph
/*!
 * \brief Базовая функция обратного вызова для отрисовки графика
 */
gboolean on_draw(GtkWidget *widget, cairo_t *cairo);
/*!
 * \brief Функция для отрисовки осей графика
 */
void draw_axis(Graph_properties *gp);
/*!
 * \brief Функция для отрисовки линии графика
 */
void draw_line_graph(Graph_properties *gp);
/*!
 * \brief Функция для отрисовки текстa осей на графике
 */
void draw_axis_text(Graph_properties *gp, gdouble value, int rotate);
/*!
 * \brief Функция для установки шага на оси
 */
gdouble set_axis_step(Graph_properties *gp);

///////////////////////////bonus 1
/*!
 * \brief Функция для отрисовки окна кредитного калькулятора
 */
void credit_window();
/*!
 * \brief Функция для расчета
 */
void credit_calculate(GtkWidget *widget, gpointer data);
/*!
 * \brief Функция для определения типа расчета
 */
void radio_button_toggled(GtkToggleButton *button, gpointer data);
#endif
