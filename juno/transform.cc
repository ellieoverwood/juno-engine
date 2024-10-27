#include "transform.h"
#include "standard.h"
#include <imgui.h>

namespace juno {
FACET_DECL(transform);

transform::transform() {
	position = glm::vec3(0, 0, 0);
	rotation = glm::vec3(1, 0, 0);
	scale    = glm::vec3(1, 1, 1);
}

transform::transform(glm::vec3 _position) {
	transform();
	position = _position;
}

transform::transform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale) {
	position = _position;
	rotation = _rotation;
	scale    = _scale;
}

void transform::ui(entity self) {
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.5f, 0.0f, 0.0f, 1.0f));
	ImGui::DragFloat3("position", glm::value_ptr(position), 1.0f);
    ImGui::PopStyleColor();

    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.0f, 0.5f, 0.0f, 1.0f));
	ImGui::DragFloat3("rotation", glm::value_ptr(rotation), 1.0f);
    ImGui::PopStyleColor();

    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.0f, 0.0f, 0.5f, 1.0f));
	ImGui::DragFloat3("scale", glm::value_ptr(scale), 1.0f);
    ImGui::PopStyleColor();
}
}
