#ifndef MENU_H
#define MENU_H

#include "InspectorPanel.h"
#include "HierarchyPanel.h"
#include "PerformancePanel.h"
#include "Render.h"
#include "MyWindow.h"

class Menu {
public:
    Menu();
    void RenderEditorWindows(MyWindow& window, Render* importer,
        void(*renderSceneContent)(MyWindow&, Render*));

    void RenderMenuBar();

    void RenderSceneWindow(MyWindow& window, Render* importer,
        void(*renderSceneContent)(MyWindow&, Render*));

    void RenderInspectorWindow();
    void RenderHierarchyWindow();
    void RenderAssetsWindow();
    void RenderPerformanceWindow();

private:
    HierarchyPanel hierarchy;
    InspectorPanel inspector;
    PerformancePanel performance;
};

#endif // MENU_H
