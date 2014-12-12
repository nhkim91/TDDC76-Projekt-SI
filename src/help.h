#ifndef HELP_H
#define HELP_H
#include "render.h"

class help
{
public:
    help() = default;
    ~help() = default;

    void show_help();
    void set_renderer(render*);

private:
    render* renderer;
};

#endif // HELP_H
