#include "Render.h"
#include <iostream>

void Render::init() {
    glewInit();
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void Render::setupCamera() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, 1.0, 0.1, 100.0);
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

void drawGrid(int gridSize, float spacing) {
    glBegin(GL_LINES);

    // Configurar el color del grid
    glColor3f(1.0f, 0.0f, 0.0f);

    // Dibujar eje y
    for (int i = -gridSize; i <= gridSize; ++i) {
        glVertex3f(i * spacing, 0.0f, -gridSize * spacing);
        glVertex3f(i * spacing, 0.0f, gridSize * spacing);
    }

    // Dibujar eje x
    for (int j = -gridSize; j <= gridSize; ++j) {
        glVertex3f(-gridSize * spacing, 0.0f, j * spacing);
        glVertex3f(gridSize * spacing, 0.0f, j * spacing);
    }

    drawGrid(10, 1.0f);  // Grid de 20x20 con espacio de 1 unidad entre líneas

    glEnd();

}