// 参考 https://toshiocp.github.io/Gtk4-tutorial/sec4.html
// GTK4で文字を表示するGUIアプリ
// Ubuntu 22.04LTS
// sudo apt install libgtk-4-dev


#include <gtk/gtk.h>

static void
app_activate (GApplication *app) {
  GtkWidget *win;
  GtkWidget *lab;

  win = gtk_application_window_new (GTK_APPLICATION (app));
  gtk_window_set_title (GTK_WINDOW (win), "Hello GTK");
  gtk_window_set_default_size (GTK_WINDOW (win), 450, 300);

  lab = gtk_label_new ("Hello World!");
  gtk_window_set_child (GTK_WINDOW (win), lab);

  gtk_window_present (GTK_WINDOW (win));
}

int
main (int argc, char **argv) {
  GtkApplication *app;
  int stat;

  app = gtk_application_new ("com.hello", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (app_activate), NULL);
  stat =g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);
  return stat;
}

