#include <exception>
#include <iostream>
#include <string>
#include "mainwindow.h"
#include "reliveeditorapplication.h"
#include "alive_api.hpp"

ReliveEditorApplication::ReliveEditorApplication()
: Gtk::Application("uk.oddmatics.relive.editor", Gio::APPLICATION_HANDLES_OPEN)
{
}

Glib::RefPtr<ReliveEditorApplication> ReliveEditorApplication::create()
{
    return Glib::RefPtr<ReliveEditorApplication>(new ReliveEditorApplication);
}

MainWindow* ReliveEditorApplication::create_mainwindow()
{
    auto window = MainWindow::create();

    add_window(*window);

    window->signal_hide().connect(
        sigc::bind<Gtk::Window*>(
            sigc::mem_fun(
                *this,
                &ReliveEditorApplication::on_hide_window
            ),
            window
        )
    );

    window->set_title(
        Glib::ustring::format(AliveAPI::GetAPIVersion())
    );

    return window;
}

void ReliveEditorApplication::on_activate()
{
    try
    {
        auto window = create_mainwindow();

        window->present();
    }
    catch (const Glib::Error ex)
    {
        std::cerr << "ReliveEditorApplication::on_activate(): " << ex.what() << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "ReliveEditorApplication::on_activate(): " << ex.what() << std::endl;
    }
}

void ReliveEditorApplication::on_open(
    const Gio::Application::type_vec_files& files,
    const Glib::ustring&                    hint
)
{
    for (const auto& file : files)
    {
        auto window = create_mainwindow();

        window->present();

        window->open_level(file);
    }
}

void ReliveEditorApplication::on_hide_window(
    Gtk::Window *window
)
{
    delete window;
}
