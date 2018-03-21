#include <jni.h>
#include "renderer2d.h"
#include <android/log.h>

#define LOG_TAG "FTCSimulation"
#define LOGI(fmt, args...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, fmt, ##args)
#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, ##args)
#define LOGE(fmt, args...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, fmt, ##args)

Renderer2D::Renderer2D() {

}

Renderer2D::~Renderer2D() {

}

void Renderer2D::create() {
	glClearColor(0.0f, 0.1f, 0.2f, 0.0f);

	glEnable(GL_DEPTH_TEST);
}

void Renderer2D::change(int width, int height) {
	glViewport(0, 0, width, height);
}

void Renderer2D::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

Renderer2D renderer;

extern "C"
JNIEXPORT void JNICALL
Java_com_malepati_vikas_ftcsimulation_platform_android_AndroidRenderer_nativeSurfaceCreate(JNIEnv *env,
	jobject instance) {

	renderer.create();
}


extern "C"
JNIEXPORT void JNICALL
Java_com_malepati_vikas_ftcsimulation_platform_android_AndroidRenderer_nativeSurfaceChange(JNIEnv *env,
	jobject instance,
	jint width,
	jint height) {

	renderer.change(width, height);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_malepati_vikas_ftcsimulation_platform_android_AndroidRenderer_nativeRenderFrame(JNIEnv *env,
	jobject instance) {
	renderer.render();
}