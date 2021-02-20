#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm.h>

class MainWindow : public Gtk::ApplicationWindow
{
    public:
        MainWindow(
            BaseObjectType*                   cobject,
            const Glib::RefPtr<Gtk::Builder>& builder
        );

        static MainWindow* create();

        void open_level(
            const Glib::RefPtr<Gio::File> file
        );

    protected:
        Glib::RefPtr<Gtk::Builder> builder;
        void on_show(
            Gtk::Window* window
        );

    private:
        Gtk::MenuItem* fileOpenPathMenuItem;
        void on_file_open_path_item_clicked();
};

#endif // MAINWINDOW_H
