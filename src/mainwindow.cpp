#include <stdexcept>
#include "mainwindow.h"

MainWindow::MainWindow(
    BaseObjectType*                   cobject,
    const Glib::RefPtr<Gtk::Builder>& builder
) : Gtk::ApplicationWindow(cobject), builder(builder)
{
    builder->get_widget(
        "menu_file_open_path",
        fileOpenPathMenuItem
    );

    fileOpenPathMenuItem->signal_activate().connect(
        sigc::mem_fun(
            *this,
            &MainWindow::on_file_open_path_item_clicked
        )
    );
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

    window->signal_show().connect(
        sigc::bind<Gtk::Window*>(
            sigc::mem_fun(
                *window,
                &MainWindow::on_show
            ),
            window
        )
    );

    return window;
}

void MainWindow::on_show(
    Gtk::Window *window
)
{
}

void MainWindow::on_file_open_path_item_clicked()
{
    auto dialog = new Gtk::MessageDialog("wow", false, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, true);

    dialog->set_secondary_text("check it out");

    dialog->run();

    delete dialog;

    // File filter
    // 
    auto filter = Gtk::FileFilter::create();

    filter->add_pattern("*.lvl");
    filter->set_name("Abe's Oddysee/Exoddus levels");

    // File chooser stuff
    //
    auto openFileDialog =
        new Gtk::FileChooserDialog(
            *this,
            "Open level",
            Gtk::FILE_CHOOSER_ACTION_OPEN
        );

    openFileDialog->add_filter(filter);

    openFileDialog->add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    openFileDialog->add_button("_Open", Gtk::RESPONSE_OK);

    openFileDialog->run();

    delete openFileDialog;
}
