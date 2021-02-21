#include <gtkmm.h>
#include "alive_api.hpp"
#include "aliveapierror.h"

Glib::ustring AliveApiError::get_string(
    const AliveAPI::Error& err
)
{
    switch (err)
    {
        case (AliveAPI::Error::None):
        {
            return "The operation completed successfully.";
        }

        case (AliveAPI::Error::JsonFileNeedsUpgrading):
        {
            return "The JSON for this path must be upgraded before editing.";
        }

        case (AliveAPI::Error::JsonFileWriteError):
        {
            return "Failed to write the path JSON back to the disk.";
        }

        case (AliveAPI::Error::JsonFileReadError):
        {
            return "Failed to read the path JSON.";
        }

        case (AliveAPI::Error::LvlFileReadEror):
        {
            return "Failed to read the level file.";
        }

        case (AliveAPI::Error::PathResourceNotFound):
        {
            return "Unable to read path data from the level.";
        }

        case (AliveAPI::Error::RequiredResourceNotFoundInAnyLvl):
        {
            return "A resource used in the path could not be found in any level.";
        }

        default:
        {
            return "An unknown error occurred.";
        }
    }
}
