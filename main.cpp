#include <Geode/Geode.hpp>
#include <imgui-cocos.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

static bool noclipEnabled = false;
static bool jumpHackEnabled = false;
static bool autoclickerEnabled = false;
static float speedhackValue = 1.0f;

class $modify(NoclipHack, PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* object) {
        if (!noclipEnabled) {
            PlayLayer::destroyPlayer(player, object);
        }
    }
};

class $modify(Speedhack, GJBaseGameLayer) {
public:
    void update(float dt) {
        GJBaseGameLayer::update(dt * speedhackValue);
    }
};
$on_mod(Loaded) {
	ImGuiCocos::get().setup([] {
		ImGui::StyleColorsLight();
	}).draw([] {
		ImGui::Begin("Polo", nullptr, ImGuiWindowFlags_NoCollapse);
		if (ImGui::BeginTabBar("Polo")) {
			if (ImGui::BeginTabItem("Global")) {
				ImGui::Text("speedhack");
				ImGui::SliderFloat("##speedhack", &speedhackValue, 0.0001f, 10000.0f, "%.5f");
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
