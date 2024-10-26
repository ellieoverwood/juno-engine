#include "dev_menu.h"
#include <imgui.h>

bool active = true;

namespace juno::debug::dev {
    void update() {
        ImGui::Begin("Scene", &active, ImGuiWindowFlags_None);
        ImGui::Text("Hello World");
        ImGui::End();
    }
}