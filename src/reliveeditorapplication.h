#ifndef RELIVEEDITORAPPLICATION_H
#define RELIVEEDITORAPPLICATION_H

#include <gtkmm.h>

class MainWindow;

class ReliveEditorApplication : public Gtk::Application
{
    protected:
        ReliveEditorApplication();

    public:
        static Glib::RefPtr<ReliveEditorApplication> create();

    protected:
        void on_activate() override;

    private:
        MainWindow* create_mainwindow();
        void        on_hide_window(
            Gtk::Window* window
        );
};

#endif // RELIVEEDITORAPPLICATION_H
