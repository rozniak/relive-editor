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

    protected:
        Glib::RefPtr<Gtk::Builder> builder;
};

#endif // MAINWINDOW_H
