#include "ui.h"
#include "../window.h"
#include <imgui.h>
#include "../entity.h"
#include "../standard.h"
#include "../../config.h"
#include <vector>
#include <string>

bool demo_window = false;
juno::entity inspected;

struct log_entry {
    char* text;
    bool has_color;
    ImVec4 color;
};
std::vector<log_entry> entries;

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
    char buffer[7 + NAME_CAP];

    std::vector<juno::entity>* entities = juno::entity::entity_list();
    for (int i = 0; i < entities->size(); i ++) {
        bool a = false;
        char* name = (*entities)[i].name();
        if (name[0]) {
            snprintf(buffer, 7 + NAME_CAP, "%05d: %s", (*entities)[i].id, (*entities)[i].name());
        } else {
            snprintf(buffer, 7 + NAME_CAP, "%05d", (*entities)[i].id);
        }
        ImGui::Selectable(buffer, &a);
        if (a) juno::ui::inspect((*entities)[i]);
    }
    
    ImGui::End();
}

bool autoscroll = true;

void console() {
    ImGui::Begin("Console", NULL);

    ImGui::Checkbox("Autoscroll", &autoscroll);
    ImGui::Separator();

    if (ImGui::BeginChild("ScrollingRegion", ImVec2(0, -10), ImGuiChildFlags_NavFlattened, ImGuiWindowFlags_HorizontalScrollbar)) {

        for (int i = 0; i < entries.size(); i ++) {
            log_entry e = entries[i];
            if (e.has_color) ImGui::PushStyleColor(ImGuiCol_Text, e.color);
            ImGui::TextUnformatted(e.text);
            if (e.has_color) ImGui::PopStyleColor();
        }

        if (autoscroll) ImGui::SetScrollHereY(1.0f);
        ImGui::EndChild();
    }

    ImGui::End();
}

void inspector() {
    ImGui::Begin("Inspect", NULL);
    
    char buffer[7 + NAME_CAP];
    char* name = inspected.name();
    if (name[0]) {
        snprintf(buffer, 7 + NAME_CAP, "%05d: %s", inspected.id, inspected.name());
    } else {
        snprintf(buffer, 7 + NAME_CAP, "%05d", inspected.id);
    }

    ImGui::Text(buffer);
    ImGui::End();
}

void demo_window_fn() {
    if (demo_window) ImGui::ShowDemoWindow(&demo_window);
}

namespace juno::ui {
    void log(char* text, bool has_color, ImVec4 color) {
        entries.push_back((log_entry){text, has_color, color});
    }

    void logf(bool has_color, ImVec4 color, char* fmt, ...) {
        char* buf = (char*)malloc(sizeof(char) * 256);
        va_list va;
        va_start(va, fmt);
        vsnprintf(buf, 256, fmt, va);
        va_end(va);

        log(buf, has_color, color);
    }

    void inspect(entity e) {
        inspected = e;
    }

    void update() {
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport()->ID);

        menu_bar();
        demo_window_fn();
        scene();
        game_window();
        console();
        inspector();
    }
}