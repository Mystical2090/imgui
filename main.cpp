#include <Geode/Geode.hpp>
#include <imgui-cocos.hpp>
// #include "imgui.h"
// ^ yes, useless it will crash if i use
// the normal version.
using namespace geode::prelude;

bool noclipEnabled = false;
bool jumpHackEnabled = false;
bool autoclickerEnabled = false;
float speedhackValue = 1.0f;

$on_mod(Loaded) {
	ImGuiCocos::get().setup([] {
		ImGui::StyleColorsDark();
	}).draw([] {
		ImGui::Begin("Polo", nullptr, ImGuiWindowFlags_NoCollapse);
		if (ImGui::BeginTabBar("Polo")) {
			if (ImGui::BeginTabItem("Global")) {
				ImGui::Text("speedhack");
				ImGui::SameLine();
#ifdef GEODE_IS_IOS
				ImGui::InputFloat("##speedhack", &speedhackValue, 0.0f, 0.0f, "%.5f", ImGuiInputTextFlags_CharsDecimal);
#else
				ImGui::InputFloat("##speedhack", &speedhackValue, 0.0f, 0.0f, "%.5f");
#endif
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Creator")) {
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Player")) {
				ImGui::Text("noclip");
				ImGui::SameLine();
				ImGui::Checkbox("##noclip", &noclipEnabled);
				
				ImGui::Text("jump hack");
				ImGui::SameLine();
				ImGui::Checkbox("##jumphack", &jumpHackEnabled);
				
				ImGui::Text("autoclicker");
				ImGui::SameLine();
				ImGui::Checkbox("##autoclicker", &autoclickerEnabled);
				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}
		ImGui::End();
	});
}

#ifndef GEODE_IS_IOS
#include <Geode/modify/CCKeyboardDispatcher.hpp>
class $modify(ImGuiKeybindHook, cocos2d::CCKeyboardDispatcher) {
	bool dispatchKeyboardMSG(cocos2d::enumKeyCodes key, bool isKeyDown, bool isKeyRepeat) {
		if (key == cocos2d::enumKeyCodes::KEY_Tab && isKeyDown) {
			ImGuiCocos::get().toggle();
		}
		return CCKeyboardDispatcher::dispatchKeyboardMSG(key, isKeyDown, isKeyRepeat);
	}
};
#endif
