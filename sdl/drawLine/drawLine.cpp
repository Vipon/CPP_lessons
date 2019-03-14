#include "mediaApp.h"
#include "event.h"
#include "render.h"
#include "window.h"


void drawLine()
{
    bool quit = false;
    bool drawing = false;

    Event event = {};
    Window win(640, 480, "drawLine");
    Render rend(win);

    Point2D p0 = {};
    Point2D p1 = {};

    rend.refresh();
    while (!quit) {

        mediaApp::delay(10);
        event.poll();
        switch (event.getType()){
        case EVENT_QUIT:
            quit = true;
            break;

        case EVENT_MOUSEBUTTONDOWN:
            event.setPoint2D(p0);
            event.setPoint2D(p1);
            drawing = true;
            break;

        case EVENT_MOUSEMOTION:
            if (drawing) {
                event.setPoint2D(p1);
            }
            break;

        case EVENT_MOUSEBUTTONUP:
            drawing = false;
            rend.setDrawColor(0, 255, 0);
            rend.drawLine(p0, p1);
            rend.update();
            break;

        default:
            break;
        }

    }
}


int main()
{
    mediaApp app(INIT_VIDEO);
    app.start(drawLine);

    return 0;
}
