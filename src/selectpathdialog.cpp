#include <gtkmm.h>
#include <stdexcept>
#include "selectpathdialog.h"
#include "alive_api.hpp"

SelectPathDialog::SelectPathDialog(
    BaseObjectType* cobject,
    const Glib::RefPtr<Gtk::Builder>& builder
) : Gtk::Dialog(cobject), builder(builder)
{
    builder->get_widget(
        "path_list_box",
        path_list_box
    );
}

SelectPathDialog* SelectPathDialog::create_for_level(
    const Glib::ustring& filepath
)
{
    auto enumResult = AliveAPI::EnumeratePaths(filepath);

    if (enumResult.mResult != AliveAPI::Error::None)
    {
        // FIXME: Handle error here! 
        //
        //return nullptr;
    }

    // Paths enum'd okay - spawn the dialog
    //
    auto              builder = Gtk::Builder::create_from_resource(
                                    "/uk/oddmatics/relive/editor/path-list-dialog.glade"
                                );
    SelectPathDialog* dialog  = nullptr;

    builder->get_widget_derived(
        "path_list_dialog",
        dialog
    );

    if (!dialog)
    {
        throw std::runtime_error(
            "No UI XML for select path dialog in path-list-dialog.glade"
        );
    }

    dialog->bind_model(enumResult);

    return dialog;
}

void SelectPathDialog::bind_model(
    const AliveAPI::EnumeratePathsResult& model
)
{
    paths_model = model;
}