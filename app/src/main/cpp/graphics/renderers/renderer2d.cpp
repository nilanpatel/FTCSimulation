#include "renderer2d.h"

Renderer2D::Renderer2D() {

}

Renderer2D::~Renderer2D() {

}

void Renderer2D::initialize() {
    int width, height;
    uint bits;
    loadImage("test.png", &width, &height, &bits);
}

void Renderer2D::setClearColor(const vec4 &color) {
    m_clearColor = color;
}

void Renderer2D::clear() {
    GLCall(glClearColor(m_clearColor.x, m_clearColor.y, m_clearColor.z, m_clearColor.w));
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void Renderer2D::setViewport(uint x, uint y, uint width, uint height) {
    GLCall(glViewport(x, y, width, height));
}