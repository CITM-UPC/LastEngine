#include "Render.h"
#include <iostream>

void Render::init() {
    glewInit();
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
}

void Render::setupCamera() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 2.0, 5.0,  // Posición de la cámara
        0.0, 0.0, 0.0,  // Punto de mira
        0.0, 1.0, 0.0); // Vector de arriba
}

void Render::drawMesh(Mesh& mesh) {
    mesh.render();
}


void Render::clearBuffers() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
