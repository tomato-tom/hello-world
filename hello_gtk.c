// Ubuntu 24.04LTS
// sudo apt install libgtk-4-dev
// gcc $( pkg-config --cflags gtk4 ) -o hello_gtk hello_gtk.c $( pkg-config --libs gtk4 )

#include <gtk/gtk.h>

void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *label;

    // 新しいウィンドウを作成
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Hello GTK+ 4");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // ラベルを作成し、ウィンドウに追加
    label = gtk_label_new("Hello World!");
    gtk_window_set_child(GTK_WINDOW(window), label);

    // ウィンドウを表示
    gtk_widget_set_visible(window, TRUE);
}

int main(int argc, char *argv[]) {
    GtkApplication *app;
    GtkWidget *window;
    GtkWidget *label;

    // GTKアプリケーションを初期化
    app = gtk_application_new("com.hello", G_APPLICATION_DEFAULT_FLAGS);
    
    // アプリケーションの「activate」シグナルにコールバック関数を接続
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    // アプリケーションを実行
    return g_application_run(G_APPLICATION(app), argc, argv);
}
