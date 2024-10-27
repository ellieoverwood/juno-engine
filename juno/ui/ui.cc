#include "ui.h"
#include "../window.h"
#include <imgui.h>
#include "../entity.h"
#include "../standard.h"
#include <string>

bool demo_window = false;

void menu_bar() {
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Quit")) { 
                juno::state::window->to_terminate = true;
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Debug")) {
            if (ImGui::MenuItem("ImGui Demo")) {
                demo_window = true;
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void game_window() {
    ImGui::Begin("Game");
    ImGui::End();
}

void scene() {
    ImGui::Begin("Scene", NULL, ImGuiWindowFlags_None);

    if (ImGui::BeginTable("Entities", 2, ImGuiTableFlags_Borders)) {
    std::vector<juno::entity>* entities = juno::entity::entity_list();
    for (int i = 0; i < entities->size(); i ++) {
        bool a = false;
        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        ImGui::Selectable(std::to_string((*entities)[i].id).c_str(), &a);
        ImGui::TableNextColumn();
        ImGui::Text((*entities)[i].name());
    }
    }
    ImGui::EndTable();
    ImGui::End();
}

void demo_window_fn() {
    if (demo_window) ImGui::ShowDemoWindow(&demo_window);
}

namespace juno::ui {
    void update() {
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport()->ID);

        menu_bar();
        demo_window_fn();
        scene();
        game_window();
    }
}