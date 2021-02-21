#ifndef ALIVEAPIERROR_H
#define ALIVEAPIERROR_H

#include "alive_api.hpp"

class AliveApiError
{
    public:
        static Glib::ustring get_string(
            const AliveAPI::Error& err
        );

    private:
        AliveApiError();
};

#endif
