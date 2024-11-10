#ifndef RENDER_H
#define RENDER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Components/Mesh.h"

class Render {
public:
    void init();

    void setupCamera();

    void drawMesh(Mesh& mesh);

    void clearBuffers();
};

#endif
