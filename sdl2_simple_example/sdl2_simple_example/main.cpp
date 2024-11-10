#include <GL/glew.h>
#include <chrono>
#include <thread>
#include <exception>
#include <glm/glm.hpp>
#include "MyWindow.h"
#include "ModelLoader.h"
#include "Render.h"
#include "imgui_impl_sdl2.h"
#include <iostream>

using namespace std;

using hrclock = chrono::high_resolution_clock;
using u8vec4 = glm::u8vec4;
using ivec2 = glm::ivec2;
using vec3 = glm::dvec3;

static const ivec2 WINDOW_SIZE(512, 512);
static const unsigned int FPS = 60;
static const auto FRAME_DT = 1.0s / FPS;

static void init_openGL() {
    glewInit();
    if (!GLEW_VERSION_3_0) throw exception("OpenGL 3.0 API is not available.");
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5, 0.5, 0.5, 1.0);
}

static bool processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            return false;
        default:
            ImGui_ImplSDL2_ProcessEvent(&event);
            break;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    MyWindow window("SDL2 Simple Example", WINDOW_SIZE.x, WINDOW_SIZE.y);
    init_openGL();

    Render renderer;
    renderer.init();
    renderer.setupCamera();

    ModelLoader modelLoader;
    Mesh mesh;

    if (modelLoader.loadModel("Assets/BakerHouse.fbx", mesh)) {
        std::cout << "Modelo cargado exitosamente y datos impresos en consola." << std::endl;
    }
    else {
        std::cerr << "Error cargando el modelo." << std::endl;
    }

    while (window.processEvents() && window.isOpen()) {
        const auto t0 = hrclock::now();
        renderer.clearBuffers();
        renderer.drawMesh(mesh);
        window.swapBuffers();
        const auto t1 = hrclock::now();
        const auto dt = t1 - t0;
        if (dt < FRAME_DT) this_thread::sleep_for(FRAME_DT - dt);
    }

    return 0;
}
