#include "mediaApp.h"
#include "event.h"
#include "render.h"
#include "window.h"


void miniPaint()
{
    bool quit = false;

    Event event = {};
    Window win(640, 480, "miniPaint");
    Render rend(win);

    rend.refresh();
    while (!quit) {

        mediaApp::delay(10);
        event.poll();
        switch (event.getType()){
        case EVENT_QUIT:
            quit = true;
            break;

        default:
            break;
        }

    }
}


int main()
{
    mediaApp app(INIT_VIDEO);
    app.start(miniPaint);

    return 0;
}
