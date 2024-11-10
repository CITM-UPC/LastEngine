#include "Menu.h"
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include "stdlib.h"

Menu::Menu() {}

void Menu::RenderMenuBar() {
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Exit", "Alt+F4")) {
                exit(0);
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("View")) {
            if (ImGui::MenuItem("Scene")) {}
            if (ImGui::MenuItem("Inspector")) {}
            if (ImGui::MenuItem("Hierarchy")) {}
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void Menu::RenderEditorWindows(MyWindow& window, Render* render, void(*renderSceneContent)(MyWindow&, Render*)) {
    // 1. Configurar ImGui
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    // 2. Renderizar el menú principal
    RenderMenuBar();

    // 3. Crear el espacio de trabajo (DockSpace) donde se colocarán las ventanas
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse;
    window_flags |= ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

    ImGui::Begin("DockSpace Demo", nullptr, window_flags);
    ImGui::PopStyleVar(3);

    ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_None);

    // 4. Renderizar las ventanas del editor
    RenderSceneWindow(window, render, renderSceneContent);
    RenderInspectorWindow();
    RenderHierarchyWindow();
    RenderPerformanceWindow();

    ImGui::End();
}

void Menu::RenderSceneWindow(MyWindow& window, Render* renderer, void(*renderSceneContent)(MyWindow&, Render*)) {
    ImGui::Begin("Scene");

    ImVec2 contentRegion = ImGui::GetContentRegionAvail();
    if (contentRegion.x > 0 && contentRegion.y > 0) {
        window.resizeFramebuffer(static_cast<int>(contentRegion.x), static_cast<int>(contentRegion.y));

        window.bindFramebuffer();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        renderSceneContent(window, renderer);
        window.unbindFramebuffer();

        ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(window.getRenderedTexture())), contentRegion);
    }

    ImGui::End();
}

void Menu::RenderInspectorWindow() {
    ImGui::Begin("Inspector");
    // Draw inspector contents here
    inspector.DrawInspectorWindow();
    ImGui::End();
}

void Menu::RenderHierarchyWindow() {
    ImGui::Begin("Hierarchy");
    // Draw hierarchy contents here
    hierarchy.DrawHierarchyWindow();
    ImGui::End();
}

void Menu::RenderPerformanceWindow() {
    ImGui::Begin("Performance Monitor");
    // Draw performance contents here
    performance.DrawPerformanceWindow();
    ImGui::End();
}
