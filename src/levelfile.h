#ifndef LEVELFILE_H
#define LEVELFILE_H

#include <gtkmm.h>

class LevelFile
{
    public:
        LevelFile(
            Glib::RefPtr<Gio::File> file
        );

    public:
        bool has_unsaved_data();

        void select_path(
            int path_index
        );

    private:
        Glib::RefPtr<Gio::File> lvlFile;
        bool                    unsaved = false;
};

#endif // LEVELFILE_H
