#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H
#include <SDL2/SDL_events.h>
#include <SDL2/SDL.h>
#include <map>
#include <functional>

class event_handler
{
public:
    event_handler();
    ~event_handler() = default;

    void start_event_handler();
    void stop_event_handler();
    void push_event();
    unsigned int subscribe(std::function <void (SDL_Event)>);
    void unsubscribe(unsigned int);

private:
    void event_wait();
    bool run;
    SDL_Event event;
    unsigned int id;
    std::map <unsigned int, std::function <void (SDL_Event)> > subscribers; // id och vilken funktion som subscrieba

};

#endif // EVENT_HANDLER_H
