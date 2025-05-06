#include "calculate.h"
#include "gtk_frontend.h"

int main(int argc, char **argv) {
  GtkApplication *app;

  gtk_init(&argc, &argv);

  int status;

  app = gtk_application_new("org.gtk.gui_calculator", G_APPLICATION_FLAGS_NONE);

  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}
