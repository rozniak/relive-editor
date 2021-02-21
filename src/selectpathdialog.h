#ifndef SELECTPATHDIALOG_H
#define SELECTPATHDIALOG_H

#include <gtkmm.h>
#include "alive_api.hpp"

class SelectPathDialog : public Gtk::Dialog
{
    public:
        SelectPathDialog(
            BaseObjectType*                   cobject,
            const Glib::RefPtr<Gtk::Builder>& builder
        );

        static SelectPathDialog* create_for_level(
            const Glib::ustring& filepath
        );

        void bind_model(
            const AliveAPI::EnumeratePathsResult& model
        );

    protected:
        Glib::RefPtr<Gtk::Builder> builder;

    private:
        Gtk::ListBox*                  path_list_box;
        AliveAPI::EnumeratePathsResult paths_model;
};

#endif // SELECTPATHDIALOG_H
