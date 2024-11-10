#pragma once

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Render.h"

class IEventProcessor {
public:
	virtual void processEvent(const SDL_Event& event) = 0;
};

class MyWindow {

private:
	SDL_Window* _window = nullptr;
	void* _ctx = nullptr;

	unsigned short _width = 800;
	unsigned short _height = 600;

    // Camera properties
    GLfloat cameraX = 0.0f;
    GLfloat cameraY = 5.0f;
    GLfloat cameraZ = 10.0f;
    GLfloat cameraSpeed = 0.1f;

    GLfloat cameraAngleX = 0.0f;
    GLfloat cameraAngleY = 0.0f;
    GLfloat cameraAngleZ = 0.0f;
    bool rotatingCamera = false;
    bool movingCamera = false;
    bool movingCameraWithMouse = false;

    GLfloat targetX = 0.0f;
    GLfloat targetY = 0.0f;
    GLfloat targetZ = 0.0f;
    GLfloat orbitRadius = 10.0f;
    GLfloat orbitAngleHorizontal = 0.0f;
    GLfloat orbitAngleVertical = 30.0f;

    // Private camera methods
    void MoveCamera(const Uint8* keystate);
    void MoveCameraWithMouse(int xrel, int yrel);

    void RotateCamera(int xrel, int yrel);
    void FocusOnObject();


public:
    glm::vec3 GetCameraPosition() const { return glm::vec3(cameraX, cameraY, cameraZ); }
    glm::vec3 GetTargetPosition() const { return glm::vec3(targetX, targetY, targetZ); }

	int width() const { return _width; }
	int height() const { return _height; }
	double aspect() const { return static_cast<double>(_width) / _height; }

	auto* windowPtr() const { return _window; }
	auto* contextPtr() const { return _ctx; }

	MyWindow(const char* title, unsigned short width, unsigned short height);
	MyWindow(MyWindow&&) noexcept = delete;
	MyWindow(const MyWindow&) = delete;
	MyWindow& operator=(const MyWindow&) = delete;
	GLuint getRenderedTexture() const;
	~MyWindow();


	//framebuffer
	void resizeFramebuffer(int width, int height);
	void initFramebuffer(unsigned short width, unsigned short height);
	void unbindFramebuffer();
	void bindFramebuffer();

	void open(const char* title, unsigned short width, unsigned short height);
	void close();
	bool isOpen() const { return _window; }

	bool processEvents(IEventProcessor* event_processor = nullptr);
	void swapBuffers() const;

private:
	GLuint framebuffer = 0;
	GLuint renderedTexture = 0;
	GLuint depthRenderbuffer = 0;

	int _viewportWidth = 0;
	int _viewportHeight = 0;

};