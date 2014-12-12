#include "event_handler.h"


using namespace std;

event_handler::event_handler()
{
    run = false;
    id = 0;
}

void event_handler::start_event_handler()
{
    run = true;
    event_wait();
}

void event_handler::stop_event_handler()
{
    run = false;
}

//Prenumererar på event
unsigned int event_handler::subscribe(function <void (SDL_Event)> callback)
{
    ++id;
    auto it = subscribers.end(); //hint till map insert för högsta insättningseffektivitet
    subscribers.insert(it, pair <unsigned int, std::function <void (SDL_Event)> >(id, callback));

    return id;
}

//Ej klar
//Tar bort prenumerationen
void event_handler::unsubscribe(unsigned int uid) //
{
    subscribers.erase(uid);
}

void event_handler::event_wait()
{
    int success = SDL_WaitEvent (&event); // returnerar 1 om det finns event, 0 vid timeout.


}
