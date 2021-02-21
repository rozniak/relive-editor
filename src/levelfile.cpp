#include <gtkmm.h>
#include "levelfile.h"

LevelFile::LevelFile(
    Glib::RefPtr<Gio::File> file
) : lvlFile(file)
{
}

bool LevelFile::has_unsaved_data()
{
    return unsaved;
}

void LevelFile::select_path(
    int path_index
)
{

}
