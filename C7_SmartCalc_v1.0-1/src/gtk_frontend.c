#include "gtk_frontend.h"

#include "calculate.h"

#define ROTATE 1
#define DONT_ROTATE 0

char input_buffer[SIZE] = {0};
char output_buffer[SIZE] = {0};
const char *expression;

Modal win_dialog;
Calc widget;
Credit credit;

/*отрисовка основного калькулятора*/
void activate(GtkApplication *app, gpointer user_data) {
  widget.window = gtk_application_window_new(app);
  gtk_window_set_position(GTK_WINDOW(widget.window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(widget.window), "SmartCalc v1.0");
  gtk_window_set_default_size(GTK_WINDOW(widget.window), 200, 300);
  gtk_container_set_border_width(GTK_CONTAINER(widget.window), 20);
  gtk_window_set_resizable(GTK_WINDOW(widget.window), FALSE);

  widget.grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(widget.window), widget.grid);

  widget.box = gtk_entry_new();
  gtk_editable_set_editable(GTK_EDITABLE(widget.box), FALSE);
  widget.button_x =
      gtk_spin_button_new_with_range(-G_MAXDOUBLE, G_MAXDOUBLE, 0.01);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(widget.button_x), 0.0);

  const gchar *text_label[] = {
      "x",    "AC",  "⌫",   "(", ")",           "7",           "8",
      "9",    "/",   "4",   "5", "6",           "*",           "1",
      "2",    "3",   "-",   "0", ",",           "mod",         "+",
      "sin",  "cos", "tan", "^", "acos",        "asin",        "atan",
      "sqrt", "ln",  "log", "=", "Credit calc", "Deposit calc"};
  for (int i = 0, k = 0; i <= 33; i++, k++) {
    widget.button[i] = gtk_button_new_with_label(text_label[k]);
  }

  gtk_grid_attach(GTK_GRID(widget.grid), widget.box, 0, 0, 4, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[0], 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button_x, 1, 1, 4, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[1], 0, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[2], 1, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[3], 2, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[4], 3, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[5], 0, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[6], 1, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[7], 2, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[8], 3, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[9], 0, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[10], 1, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[11], 2, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[12], 3, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[13], 0, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[14], 1, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[15], 2, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[16], 3, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[17], 0, 6, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[18], 1, 6, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[19], 2, 6, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[20], 3, 6, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[21], 0, 7, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[22], 1, 7, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[23], 2, 7, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[24], 3, 7, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[25], 0, 8, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[26], 1, 8, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[27], 2, 8, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[28], 0, 9, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[29], 1, 9, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[30], 2, 9, 1, 1);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[31], 3, 8, 1, 2);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[32], 0, 10, 2, 2);
  gtk_grid_attach(GTK_GRID(widget.grid), widget.button[33], 2, 10, 2, 2);

  g_signal_connect(widget.button[0], "clicked", G_CALLBACK(display), NULL);
  g_signal_connect(widget.button[1], "clicked", G_CALLBACK(button_delete),
                   NULL);
  g_signal_connect(widget.button[2], "clicked", G_CALLBACK(button_delete_char),
                   NULL);

  for (int j = 3; j <= 30; j++) {
    g_signal_connect(widget.button[j], "clicked", G_CALLBACK(display), NULL);
  }

  g_signal_connect(widget.button[31], "clicked", G_CALLBACK(button_calc), NULL);
  g_signal_connect(widget.button[32], "clicked", G_CALLBACK(credit_window),
                   NULL);

  gtk_widget_show_all(widget.window);
}

/*вывод расчетного выражения*/
void display(GtkButton *button, gpointer data) {
  const char *text = gtk_button_get_label(button);
  strncat(input_buffer, text, 4);
  gtk_entry_set_text(GTK_ENTRY(widget.box), input_buffer);
}

/*очистка поля*/
void button_delete() {
  gtk_entry_set_text(GTK_ENTRY(widget.box), "");
  memset(input_buffer, 0, strlen(input_buffer));
}

/*удаление одного символа в поле*/
void button_delete_char() {
  int input_size = strlen(input_buffer);
  if (input_size > 0) {
    input_buffer[input_size - 1] = '\0';
    gtk_entry_set_text(GTK_ENTRY(widget.box), (const gchar *)input_buffer);
  }
}

/*функцуия расчета*/
void button_calc(GtkWidget *box, gpointer data) {
  const char *text;
  double answer;
  gtk_entry_set_text(GTK_ENTRY(widget.box), text);
  strncat(input_buffer, text, strlen(text - 1));
  double param =
      (double)gtk_spin_button_get_value(GTK_SPIN_BUTTON(widget.button_x));
  int rc = solve_expression(input_buffer, param, &answer);
  switch (rc) {
    case 0: {
      sprintf(output_buffer, "%.7lf", answer);
      if ((strchr(input_buffer, 's') != NULL &&
           strchr(input_buffer, 'x') != NULL) ||
          (strchr(input_buffer, 'c') != NULL &&
           strchr(input_buffer, 'x') != NULL) ||
          (strchr(input_buffer, 't') != NULL &&
           strchr(input_buffer, 'x') != NULL) ||
          (strchr(input_buffer, 'l') != NULL &&
           strchr(input_buffer, 'x') != NULL) ||
          strchr(input_buffer, 'x') != NULL) {
        modal_window();
      }
      break;
    }
    case 10: {
      g_strlcpy(output_buffer,
                "Степень нуля не определена для отрицательной степени!",
                sizeof(output_buffer));
      break;
    }
    case 11: {
      g_strlcpy(output_buffer, "Деление на ноль запрещено!",
                sizeof(output_buffer));
      break;
    }
    case 12: {
      g_strlcpy(output_buffer,
                "Извлекать корень из отрицательного числа запрещено!",
                sizeof(output_buffer));
      break;
    }
    case 13: {
      g_strlcpy(output_buffer, "На данный момент касательная не определена!",
                sizeof(output_buffer));
      break;
    }
    case 14: {
      g_strlcpy(output_buffer,
                "Логарифм не определен для неположительных чисел!",
                sizeof(output_buffer));
      break;
    }
    case 15: {
      g_strlcpy(output_buffer,
                "Обратный косинус не определен за пределами [-1, 1]!",
                sizeof(output_buffer));
      break;
    }
    case 16: {
      g_strlcpy(output_buffer,
                "Обратный синус не определен за пределами [-1, 1]!",
                sizeof(output_buffer));
      break;
    }
    case 17: {
      g_strlcpy(output_buffer, "Слишком много аргументов!",
                sizeof(output_buffer));
      break;
    }
    default: {
      g_strlcpy(output_buffer, "Некорректное выражение!",
                sizeof(output_buffer));
      break;
    }
  }
  gtk_entry_set_text(GTK_ENTRY(widget.box), output_buffer);
}

void button_draw_clicked(GtkWidget *button, gpointer data) {
  sprintf((char *)expression, "%s",
          gtk_entry_get_text((GtkEntry *)win_dialog.entry));
  gtk_widget_queue_draw(win_dialog.drawing_area);
}

/*отрисовка окна построения графика*/
void modal_window() {
  GtkWidget *label_x_min;
  GtkWidget *label_x_max;
  GtkWidget *label_y_min;
  GtkWidget *label_y_max;
  GtkWidget *fx;

  win_dialog.dialog = gtk_dialog_new();
  gtk_window_set_title(GTK_WINDOW(win_dialog.dialog),
                       "Построение графика функции");
  gtk_window_set_default_size(GTK_WINDOW(win_dialog.dialog), WIDTH, HEIGHT);
  gtk_container_set_border_width(GTK_CONTAINER(win_dialog.dialog), 10);
  gtk_window_set_resizable(GTK_WINDOW(win_dialog.dialog), FALSE);

  win_dialog.content_area =
      gtk_dialog_get_content_area(GTK_DIALOG(win_dialog.dialog));
  win_dialog.grid_1 = gtk_grid_new();
  gtk_grid_set_row_spacing(GTK_GRID(win_dialog.grid_1), 5);
  gtk_grid_set_column_spacing(GTK_GRID(win_dialog.grid_1), 5);
  gtk_container_add(GTK_CONTAINER(win_dialog.content_area), win_dialog.grid_1);

  label_x_min = gtk_label_new("X_min");
  gtk_grid_attach(GTK_GRID(win_dialog.grid_1), label_x_min, 0, 0, 1, 1);
  win_dialog.x_min = gtk_spin_button_new_with_range(-1000000, 1000000, 1);
  gtk_grid_attach(GTK_GRID(win_dialog.grid_1), win_dialog.x_min, 1, 0, 1, 1);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(win_dialog.x_min), -15);

  label_x_max = gtk_label_new("X_max");
  gtk_grid_attach(GTK_GRID(win_dialog.grid_1), label_x_max, 2, 0, 1, 1);
  win_dialog.x_max = gtk_spin_button_new_with_range(-1000000, 1000000, 1);
  gtk_grid_attach(GTK_GRID(win_dialog.grid_1), win_dialog.x_max, 3, 0, 1, 1);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(win_dialog.x_max), 15);

  label_y_min = gtk_label_new("Y_min");
  gtk_grid_attach(GTK_GRID(win_dialog.grid_1), label_y_min, 0, 1, 1, 1);
  win_dialog.y_min = gtk_spin_button_new_with_range(-1000000, 1000000, 1);
  gtk_grid_attach(GTK_GRID(win_dialog.grid_1), win_dialog.y_min, 1, 1, 1, 1);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(win_dialog.y_min), -15);

  label_y_max = gtk_label_new("Y_max");
  gtk_grid_attach(GTK_GRID(win_dialog.grid_1), label_y_max, 2, 1, 1, 1);
  win_dialog.y_max = gtk_spin_button_new_with_range(-1000000, 1000000, 1);
  gtk_grid_attach(GTK_GRID(win_dialog.grid_1), win_dialog.y_max, 3, 1, 1, 1);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(win_dialog.y_max), 15);

  fx = gtk_label_new("f(x)");
  gtk_grid_attach(GTK_GRID(win_dialog.grid_1), fx, 0, 2, 1, 1);
  win_dialog.entry = gtk_entry_new();
  gtk_entry_set_text(GTK_ENTRY(win_dialog.entry), input_buffer);
  gtk_editable_set_editable(GTK_EDITABLE(win_dialog.entry), FALSE);
  gtk_grid_attach(GTK_GRID(win_dialog.grid_1), win_dialog.entry, 1, 2, 1, 1);

  win_dialog.button_b = gtk_button_new_with_label("Build");
  gtk_grid_attach(GTK_GRID(win_dialog.grid_1), win_dialog.button_b, 2, 2, 2, 1);

  win_dialog.drawing_area = gtk_drawing_area_new();
  gtk_widget_set_size_request(win_dialog.drawing_area, WIDTH, HEIGHT);
  gtk_container_add(GTK_CONTAINER(win_dialog.content_area),
                    win_dialog.drawing_area);

  g_signal_connect(G_OBJECT(win_dialog.drawing_area), "draw",
                   G_CALLBACK(on_draw), NULL);

  g_signal_connect(G_OBJECT(win_dialog.button_b), "clicked",
                   G_CALLBACK(button_draw_clicked), G_OBJECT(win_dialog.entry));

  gtk_widget_show_all(win_dialog.dialog);

  gtk_dialog_run(GTK_DIALOG(win_dialog.dialog));

  gtk_widget_destroy(win_dialog.dialog);
}

/*функции для отрисовки графика*/
gboolean on_draw(GtkWidget *widget, cairo_t *cairo) {
  Graph_properties gp = {};
  double x_middle;
  double y_middle;
  double x_range;
  double y_range;

  gp.cr = cairo;

  cairo_set_source_rgb(gp.cr, 0.9, 0.9, 0.9);
  cairo_paint(gp.cr);
  cairo_device_to_user_distance(gp.cr, &gp.dx, &gp.dy);

  gp.max_x = gtk_spin_button_get_value(GTK_SPIN_BUTTON(win_dialog.x_max));
  gp.max_y = gtk_spin_button_get_value(GTK_SPIN_BUTTON(win_dialog.y_max));
  gp.min_x = gtk_spin_button_get_value(GTK_SPIN_BUTTON(win_dialog.x_min));
  gp.min_y = gtk_spin_button_get_value(GTK_SPIN_BUTTON(win_dialog.y_min));

  gp.right_limit = gp.min_x > gp.min_y ? gp.min_y : gp.min_x;
  gp.left_limit = gp.max_x < gp.max_y ? gp.max_y : gp.max_x;

  gp.lower_limit = -gp.max_y > -gp.max_x ? -gp.max_x : -gp.max_y;
  gp.upper_limit = -gp.min_y < -gp.min_x ? -gp.min_x : -gp.min_y;

  x_range = gp.left_limit - gp.right_limit;
  y_range = gp.upper_limit - gp.lower_limit;

  gp.dx = (x_range) / WIDTH;
  gp.dy = (x_range) / HEIGHT;

  x_middle = (fabs(gp.right_limit) / (x_range)) * WIDTH;
  y_middle = (fabs(gp.lower_limit)) / (y_range)*HEIGHT;

  cairo_translate(gp.cr, x_middle, y_middle);

  cairo_scale(gp.cr, 1 / gp.dx, 1 / gp.dy);

  draw_axis(&gp);

  draw_line_graph(&gp);

  return FALSE;
}

void draw_line_graph(Graph_properties *gp) {
  int vector = -1;
  int flag = 0;
  cairo_set_source_rgb(gp->cr, 0.0, 0.0, 0.0);
  cairo_set_line_width(gp->cr, 2 * gp->dx);
  gdouble step = gp->dx / 10;
  expression = gtk_entry_get_text(GTK_ENTRY(win_dialog.entry));
  for (gdouble x = gp->min_x; x < gp->max_x; x += step) {
    gdouble y_value;
    solve_expression((char *)expression, x, &y_value);
    if (y_value > gp->max_y) {
      if (flag == 1) cairo_line_to(gp->cr, x, vector * gp->max_y);
      cairo_move_to(gp->cr, x, vector * gp->max_y);
      flag = 0;
    } else if ((y_value < gp->min_y)) {
      if (flag == 1) cairo_line_to(gp->cr, x, vector * gp->min_y);
      cairo_move_to(gp->cr, x, vector * gp->min_y);
      flag = 0;
    } else if (isnan(y_value) || isnan(x)) {
      flag = 2;
    } else if (flag < 2) {
      cairo_line_to(gp->cr, x, vector * y_value);
      flag = 1;
    } else {
      cairo_move_to(gp->cr, x, vector * y_value);
      flag = 1;
    }
  }
  cairo_stroke(gp->cr);
}

void round_two_digits(gdouble *step) {
  char buffer[64];
  sprintf(buffer, "%lf", *step);
  for (int i = 1; i < strlen(buffer); i++) {
    if (buffer[i] != '.') buffer[i] = '0';
  }
  sscanf(buffer, "%lf", step);
}

gdouble set_axis_step(Graph_properties *gp) {
  gdouble step = 20 * gp->dx;
  if (step > 10) {
    round_two_digits(&step);
  } else if (step > 5) {
    step = 10;
  } else if (step > 2) {
    step = 5;
  } else if (step > 1) {
    step = 2;
  } else {
    for (gdouble i = 0.1; i <= 1; i += 0.1) {
      if (step < i) {
        step = i;
        break;
      }
    }
  }
  return step;
}

void draw_axis_text(Graph_properties *gp, gdouble value, int rotate) {
  char buffer[64];
  sprintf(buffer, "%g", value);
  if (rotate) {
    cairo_rotate(gp->cr, -1);
    cairo_show_text(gp->cr, buffer);
    cairo_rotate(gp->cr, 1);
  } else {
    cairo_show_text(gp->cr, buffer);
  }
}

void draw_axis(Graph_properties *gp) {
  char buffer[64];
  gdouble step = set_axis_step(gp);
  gdouble text_offset = 2 * gp->dx;
  int vector = -1;

  cairo_set_source_rgb(gp->cr, 0.0, 0.0, 0.0);
  cairo_set_line_width(gp->cr, gp->dx / 10);

  cairo_select_font_face(gp->cr, "Arial", CAIRO_FONT_SLANT_NORMAL,
                         CAIRO_FONT_WEIGHT_NORMAL);
  cairo_set_font_size(gp->cr, 10 * gp->dx);

  for (gdouble i = 0; i < gp->left_limit; i += step) {
    cairo_move_to(gp->cr, i, gp->lower_limit);
    cairo_line_to(gp->cr, i, gp->upper_limit);
    cairo_move_to(gp->cr, i, gp->upper_limit - text_offset);
    draw_axis_text(gp, i, ROTATE);
  }
  for (gdouble i = 0; i > gp->right_limit; i -= step) {
    cairo_move_to(gp->cr, i, gp->lower_limit);
    cairo_line_to(gp->cr, i, gp->upper_limit);
    cairo_move_to(gp->cr, i, gp->upper_limit - text_offset);
    draw_axis_text(gp, i, ROTATE);
  }
  for (gdouble i = 0; i < gp->upper_limit; i += step) {
    cairo_move_to(gp->cr, gp->right_limit, i);
    cairo_line_to(gp->cr, gp->left_limit, i);
    cairo_move_to(gp->cr, gp->right_limit, i);
    draw_axis_text(gp, vector * i, DONT_ROTATE);
  }

  for (gdouble i = 0; i > gp->lower_limit; i -= step) {
    cairo_move_to(gp->cr, gp->right_limit, i);
    cairo_line_to(gp->cr, gp->left_limit, i);
    cairo_move_to(gp->cr, gp->right_limit, i);
    draw_axis_text(gp, vector * i, DONT_ROTATE);
  }

  cairo_stroke(gp->cr);

  cairo_set_line_width(gp->cr, gp->dx / 2);
  cairo_move_to(gp->cr, gp->right_limit, 0);
  cairo_line_to(gp->cr, gp->left_limit, 0);
  cairo_move_to(gp->cr, 0, gp->lower_limit);
  cairo_line_to(gp->cr, 0, gp->upper_limit);

  cairo_set_font_size(gp->cr, 15 * gp->dx);
  cairo_move_to(gp->cr, gp->left_limit - 15 * gp->dx, 0 + 15 * gp->dx);
  sprintf(buffer, "X");
  cairo_show_text(gp->cr, buffer);
  cairo_move_to(gp->cr, 0 + 5 * gp->dx, gp->lower_limit + 15 * gp->dx);
  sprintf(buffer, "Y");
  cairo_show_text(gp->cr, buffer);

  cairo_stroke(gp->cr);
}

////////////////////////bonus1/////////////////////
/*отрисовка кредитного калькулятора*/
void credit_window() {
  GtkWidget *credit_dialog;
  GtkWidget *content_credit;
  GtkWidget *grid_credit;
  GtkWidget *label_total_amount;
  GtkWidget *label_term;
  GtkWidget *label_interest;
  GtkWidget *label_inter;
  GtkWidget *label_type;
  GtkWidget *label_total;
  GtkWidget *annuity;
  GtkWidget *differentiated;

  credit_dialog = gtk_dialog_new();
  gtk_window_set_title(GTK_WINDOW(credit_dialog), "Кредитный калькулятор");
  gtk_window_set_default_size(GTK_WINDOW(credit_dialog), 600, 400);
  gtk_container_set_border_width(GTK_CONTAINER(credit_dialog), 10);
  gtk_window_set_resizable(GTK_WINDOW(credit_dialog), FALSE);

  content_credit = gtk_dialog_get_content_area(GTK_DIALOG(credit_dialog));
  grid_credit = gtk_grid_new();
  gtk_grid_set_row_spacing(GTK_GRID(grid_credit), 2);
  gtk_grid_set_column_spacing(GTK_GRID(grid_credit), 2);
  gtk_container_add(GTK_CONTAINER(content_credit), grid_credit);

  label_total_amount = gtk_label_new("Oбщая сумма кредита");
  gtk_grid_attach(GTK_GRID(grid_credit), label_total_amount, 0, 0, 1, 1);
  credit.total_amount = gtk_spin_button_new_with_range(1, 1000000, 1);
  gtk_grid_attach(GTK_GRID(grid_credit), credit.total_amount, 1, 0, 1, 1);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(credit.total_amount), 1000);

  label_term = gtk_label_new("Срок, в месяцах");
  gtk_grid_attach(GTK_GRID(grid_credit), label_term, 0, 1, 1, 1);
  credit.term = gtk_spin_button_new_with_range(1, 600, 1);
  gtk_grid_attach(GTK_GRID(grid_credit), credit.term, 1, 1, 1, 1);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(credit.term), 1);

  label_interest = gtk_label_new("Процентная ставка");
  gtk_grid_attach(GTK_GRID(grid_credit), label_interest, 0, 2, 1, 1);
  credit.interest = gtk_spin_button_new_with_range(1, 999, 1);
  gtk_grid_attach(GTK_GRID(grid_credit), credit.interest, 1, 2, 1, 1);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(credit.interest), 1);
  label_inter = gtk_label_new("%");
  gtk_grid_attach(GTK_GRID(grid_credit), label_inter, 2, 2, 1, 1);

  label_type = gtk_label_new("Тип ежемесячных платежей");
  gtk_grid_attach(GTK_GRID(grid_credit), label_type, 0, 3, 1, 1);
  annuity = gtk_radio_button_new_with_label(NULL, "Аннуитетные");
  differentiated = gtk_radio_button_new_with_label_from_widget(
      GTK_RADIO_BUTTON(annuity), "Дифференцированные");
  gtk_grid_attach(GTK_GRID(grid_credit), annuity, 1, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid_credit), differentiated, 1, 4, 1, 1);

  g_signal_connect(G_OBJECT(annuity), "toggled",
                   G_CALLBACK(radio_button_toggled), NULL);
  g_signal_connect(G_OBJECT(differentiated), "toggled",
                   G_CALLBACK(radio_button_toggled), NULL);

  credit.calculate = gtk_button_new_with_label("РАССЧИТАТЬ");
  gtk_grid_attach(GTK_GRID(grid_credit), credit.calculate, 1, 5, 1, 1);

  g_signal_connect(G_OBJECT(credit.calculate), "clicked",
                   G_CALLBACK(credit_calculate), NULL);

  label_total = gtk_label_new("Итог:");
  gtk_grid_attach(GTK_GRID(grid_credit), label_total, 0, 6, 1, 1);

  credit.total_payment_field = gtk_label_new(NULL);
  gtk_grid_attach(GTK_GRID(grid_credit), credit.total_payment_field, 0, 7, 1,
                  1);

  credit.overpayment_field = gtk_label_new(NULL);
  gtk_grid_attach(GTK_GRID(grid_credit), credit.overpayment_field, 0, 8, 1, 1);

  credit.payment_month_field = gtk_label_new(NULL);
  gtk_grid_attach(GTK_GRID(grid_credit), credit.payment_month_field, 0, 9, 1,
                  1);

  GtkWidget *textView = gtk_text_view_new();
  credit.text_field = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textView));
  gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(textView), GTK_WRAP_WORD);
  gtk_text_view_set_editable(GTK_TEXT_VIEW(textView), FALSE);

  GtkWidget *scroll = gtk_scrolled_window_new(NULL, NULL);
  gtk_container_add(GTK_CONTAINER(scroll), textView);
  gtk_widget_set_size_request(scroll, 300, 150);
  gtk_grid_attach(GTK_GRID(grid_credit), scroll, 0, 10, 1, 1);

  gtk_widget_show_all(credit_dialog);
  gtk_dialog_run(GTK_DIALOG(credit_dialog));
  gtk_widget_destroy(credit_dialog);
}

/*расчет*/
void credit_calculate(GtkWidget *widget, gpointer data) {
  double overpayment;
  double total_payment;
  (void)widget;

  gtk_text_buffer_set_text(credit.text_field, "", -1);
  double sum =
      (double)gtk_spin_button_get_value(GTK_SPIN_BUTTON(credit.total_amount));
  int period = (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(credit.term));
  double bet =
      (double)gtk_spin_button_get_value(GTK_SPIN_BUTTON(credit.interest));
  int rc = calc_credit(sum, period, bet, credit.flag, credit.payment_month,
                       &overpayment, &total_payment);
  if (!rc) {
    for (int i = 0; i < period; ++i) {
      char elem[100];
      sprintf(elem, "%d:  %.2f\n", i + 1, credit.payment_month[i]);

      GtkTextIter iter;
      gtk_text_buffer_get_end_iter(credit.text_field, &iter);
      gtk_text_buffer_insert(credit.text_field, &iter, elem, -1);
    }
    char overpayment_str[100];
    char total_payment_str[100];
    sprintf(total_payment_str, "Ввсего к оплате: %.2f", total_payment);
    sprintf(overpayment_str, "Переплата по кредиту: %.2f", overpayment);

    gtk_label_set_text(GTK_LABEL(credit.total_payment_field),
                       total_payment_str);
    gtk_label_set_text(GTK_LABEL(credit.overpayment_field), overpayment_str);
    gtk_label_set_text(GTK_LABEL(credit.payment_month_field),
                       "Ежемесячный платеж:");
  }
}

/*статус кнопок*/
void radio_button_toggled(GtkToggleButton *button, gpointer data) {
  if (gtk_toggle_button_get_active(button)) {
    const gchar *label = gtk_button_get_label(GTK_BUTTON(button));
    size_t text_1_len = strlen(label);
    const char *found =
        strstr(label + (text_1_len - strlen("Дифференцированные")),
               "Дифференцированные");
    if (found != NULL &&
        found == label + (text_1_len - strlen("Дифференцированные"))) {
      credit.flag = 1;

    } else {
      credit.flag = 0;
    }
  }
}
