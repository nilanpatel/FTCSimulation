#include "application.h"

#include <jni.h>

static float timer = 0.0f;
static float updateTimer = 0.0f;
static float updateTick = 1.0f / 60.0f;
static uint frames = 0;
static uint updates = 0;

Application::Application() {
    m_framesPerSecond = 0;
    m_updatesPerSecond = 0;
}

Application::~Application() {
    delete m_timer;
}

void Application::create() {
    m_timer = new Timer();
    m_timer->reset();

    m_renderer = new Renderer2D();
    m_renderer->initialize();
}

void Application::change(int width, int height) {
    m_renderer->setViewport(0, 0, width, height);
}

void Application::run() {
    m_renderer->clear();

    if (m_timer->elapsed() - updateTimer > updateTick) {
        updates++;
        update();
        updateTimer += updateTick;
    }

    render();
    frames++;

    if (m_timer->elapsed() - timer > 1.0f) {
        timer += 1.0f;
        m_framesPerSecond = frames;
        m_updatesPerSecond = updates;
        frames = 0;
        updates = 0;
        tick();
    }
}

void Application::tick() {

}

void Application::update() {
	
}

void Application::render() {
	
}

Application app;

extern "C"
JNIEXPORT void JNICALL
Java_com_malepati_vikas_ftcsimulation_platform_android_AndroidRenderer_nativeSurfaceCreate(JNIEnv *env,
        jobject instance) {

    app.create();
}


extern "C"
JNIEXPORT void JNICALL
Java_com_malepati_vikas_ftcsimulation_platform_android_AndroidRenderer_nativeSurfaceChange(JNIEnv *env,
        jobject instance,
        jint width,
        jint height) {

    app.change(width, height);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_malepati_vikas_ftcsimulation_platform_android_AndroidRenderer_nativeRenderFrame(JNIEnv *env,
        jobject instance) {

    app.run();
}