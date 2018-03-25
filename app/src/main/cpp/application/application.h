#pragma once

#include "../types.h"
#include "../system/console.h"
#include "../system/timer.h"
#include "../graphics/renderers/renderer2d.h"

class Application {
private:
    uint m_framesPerSecond, m_updatesPerSecond;

    Timer *m_timer;

    Renderer2D *m_renderer;
public:
    Application();
    ~Application();

    /* JNI Required Functions */
    void create();

    void change(int width, int height);

    void run();
private:
    void tick();
    void update();
    void render();
};