#include <gtk/gtk.h>

static int _g_frame_count = 0;

gboolean _label_update(gpointer args)
{
  GtkLabel* label = (GtkLabel*)args;
  GString* buffer = g_string_new(NULL);
  g_string_printf(buffer, "FrameCount: %d", _g_frame_count);
  gtk_label_set_label(label, buffer->str);
  g_string_free(buffer, TRUE);
  _g_frame_count++;
  return 1;
}

void activate(GtkApplication *app, gpointer user_data)
{
  GtkWidget *window;
  window = gtk_application_window_new(app);

  gtk_window_set_title(GTK_WINDOW(window), "Gamers");
  gtk_window_set_default_size(GTK_WINDOW(window), 400,400);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  gtk_widget_add_events(GTK_WIDGET(window), GDK_CONFIGURE);
  GtkWidget* label = gtk_label_new("initial frame");
  gtk_container_add(GTK_CONTAINER(window), label);

  g_timeout_add_seconds(1, _label_update, label);

  gtk_widget_show_all(window);
}

int main(int argc, char** argv) {
  GtkApplication* app;
  int status;

  app = gtk_application_new("dev.cam.game",
                            G_APPLICATION_FLAGS_NONE);

  g_signal_connect(app, "activate",
                   G_CALLBACK(activate), NULL);

  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return (status);
}