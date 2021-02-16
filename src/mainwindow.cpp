#include <stdexcept>
#include "mainwindow.h"

MainWindow::MainWindow(
    BaseObjectType*                   cobject,
    const Glib::RefPtr<Gtk::Builder>& builder
) : Gtk::ApplicationWindow(cobject), builder(builder)
{
}

MainWindow* MainWindow::create()
{
    auto builder       = Gtk::Builder::create_from_resource(
                             "/uk/oddmatics/relive/editor/main-ui.glade"
                         );
    MainWindow* window = nullptr;

    builder->get_widget_derived(
        "main_window",
        window
    );

    if (!window)
    {
        throw std::runtime_error(
            "No main application window in main-ui.glade"
        );
    }

    return window;
}
