#include "reliveeditorapplication.h"

int main(
    int   argc,
    char* argv[]
)
{
    auto app = ReliveEditorApplication::create();

    return app->run(argc, argv);
}
