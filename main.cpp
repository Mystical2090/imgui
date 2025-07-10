
#include <Geode/Geode.hpp>
#include <imgui-cocos.hpp>
// #include "imgui.h"
// ^ yes, useless it will crash if i use
// the normal version.
using namespace geode::prelude;

// player
bool noclipEnabled = false;
bool ignoreInputsEnabled = false;
bool jumpHackEnabled = false;
bool autoclickerEnabled = false;

// editor
bool verifyHackEnabled = false;
bool copyHackEnabled = false;
bool noCMarkEnabled = false;
bool customObjectsBypassEnabled = false;

// misc
float speedhackValue = 1.0f;
float noWavePulseValue = 1.0f;
bool practiceMusicHackEnabled = false;
bool hidePauseButtonEnabled = false;
bool layoutModeEnabled = false;
bool commentHistoryBypassEnabled = false;
bool autoPracticeEnabled = false;
bool iconHackEnabled = false;
bool colorHackEnabled = false;
bool noSolidsEnabled = false;
bool suicideEnabled = false;
bool showHitboxesEnabled = false;
bool showHitboxesOnDeathEnabled = false;
bool rainbowIconsEnabled = false;
bool everythingKillsYouEnabled = false;
bool safeModeEnabled = false;
bool instantCompleteEnabled = false;
bool basementBypassEnabled = false;
bool levelEditEnabled = false;
bool mainLevelBypassEnabled = false;
bool towerBypassEnabled = false;
bool noGlowEnabled = false;

$on_mod(Loaded) {
    ImGuiCocos::get().setup([] {
        ImGui::StyleColorsDark();
    }).draw([]() {
        ImGui::Begin("Polo", nullptr, ImGuiWindowFlags_NoCollapse);
        if (ImGui::BeginTabBar("Polo")) {
            if (ImGui::BeginTabItem("Misc")) {
                ImGui::Text("speedhack");
                ImGui::SameLine();
#ifdef GEODE_IS_IOS
                ImGui::InputFloat("##speedhack", &speedhackValue, 0.0f, 0.0f, "%.5f", ImGuiInputTextFlags_CharsDecimal);
#else
                ImGui::InputFloat("##speedhack", &speedhackValue, 0.0f, 0.0f, "%.5f");
#endif
                
                ImGui::Text("no wave pulse");
                ImGui::SameLine();
#ifdef GEODE_IS_IOS
                ImGui::InputFloat("##nowavepulse", &noWavePulseValue, 0.0f, 0.0f, "%.5f", ImGuiInputTextFlags_CharsDecimal);
#else
                ImGui::InputFloat("##nowavepulse", &noWavePulseValue, 0.0f, 0.0f, "%.5f");
#endif
                
                ImGui::Text("practice music hack");
                ImGui::SameLine();
                ImGui::Checkbox("##practicemusichack", &practiceMusicHackEnabled);
                
                ImGui::Text("hide pause button");
                ImGui::SameLine();
                ImGui::Checkbox("##hidepausebutton", &hidePauseButtonEnabled);
                
                ImGui::Text("layout mode");
                ImGui::SameLine();
                ImGui::Checkbox("##layoutmode", &layoutModeEnabled);
                
                ImGui::Text("comment history bypass");
                ImGui::SameLine();
                ImGui::Checkbox("##commenthistorybypass", &commentHistoryBypassEnabled);
                
                ImGui::Text("auto practice");
                ImGui::SameLine();
                ImGui::Checkbox("##autopractice", &autoPracticeEnabled);
                
                ImGui::Text("icon hack");
                ImGui::SameLine();
                ImGui::Checkbox("##iconhack", &iconHackEnabled);
                
                ImGui::Text("color hack");
                ImGui::SameLine();
                ImGui::Checkbox("##colorhack", &colorHackEnabled);
                
                ImGui::Text("no solids");
                ImGui::SameLine();
                ImGui::Checkbox("##nosolids", &noSolidsEnabled);
                
                ImGui::Text("suicide");
                ImGui::SameLine();
                ImGui::Checkbox("##suicide", &suicideEnabled);
                
                ImGui::Text("show hitboxes");
                ImGui::SameLine();
                ImGui::Checkbox("##showhitboxes", &showHitboxesEnabled);
                
                ImGui::Text("show hitboxes on death");
                ImGui::SameLine();
                ImGui::Checkbox("##showhitboxesondeath", &showHitboxesOnDeathEnabled);
                
                ImGui::Text("rainbow icons");
                ImGui::SameLine();
                ImGui::Checkbox("##rainbowicons", &rainbowIconsEnabled);
                
                ImGui::Text("everything kills you");
                ImGui::SameLine();
                ImGui::Checkbox("##everythingkillsyou", &everythingKillsYouEnabled);
                
                ImGui::Text("safe mode");
                ImGui::SameLine();
                ImGui::Checkbox("##safemode", &safeModeEnabled);
                
                ImGui::Text("instant complete");
                ImGui::SameLine();
                ImGui::Checkbox("##instantcomplete", &instantCompleteEnabled);
                
                ImGui::Text("basement bypass");
                ImGui::SameLine();
                ImGui::Checkbox("##basementbypass", &basementBypassEnabled);
                
                ImGui::Text("level edit");
                ImGui::SameLine();
                ImGui::Checkbox("##leveledit", &levelEditEnabled);
                
                ImGui::Text("main level bypass");
                ImGui::SameLine();
                ImGui::Checkbox("##mainlevelbypass", &mainLevelBypassEnabled);
                
                ImGui::Text("tower bypass");
                ImGui::SameLine();
                ImGui::Checkbox("##towerbypass", &towerBypassEnabled);
                
                ImGui::Text("no glow");
                ImGui::SameLine();
                ImGui::Checkbox("##noglow", &noGlowEnabled);
                
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Editor")) {
                ImGui::Text("verify hack");
                ImGui::SameLine();
                ImGui::Checkbox("##verifyhack", &verifyHackEnabled);
                
                ImGui::Text("copy hack");
                ImGui::SameLine();
                ImGui::Checkbox("##copyhack", &copyHackEnabled);
                
                ImGui::Text("no c mark");
                ImGui::SameLine();
                ImGui::Checkbox("##nocmark", &noCMarkEnabled);
                
                ImGui::Text("custom objects bypass");
                ImGui::SameLine();
                ImGui::Checkbox("##customobjectsbypass", &customObjectsBypassEnabled);
                
                ImGui::EndTabItem();
            }
            // Replace the Player tab section with this:
if (ImGui::BeginTabItem("Player")) {
    ImGui::Text("noclip");
    ImGui::SameLine();
    ImGui::Checkbox("##noclip", &noclipEnabled);
    
    ImGui::Text("ignore inputs");
    ImGui::SameLine();
    ImGui::Checkbox("##ignoreinputs", &ignoreInputsEnabled);
    
    ImGui::Text("jump hack");
    ImGui::SameLine();
    ImGui::Checkbox("##jumphack", &jumpHackEnabled);
    
    ImGui::Text("autoclicker");
    ImGui::SameLine();
    ImGui::Checkbox("##autoclicker", &autoclickerEnabled);
    
    ImGui::EndTabItem();
}

// Add Settings as a separate main tab:
if (ImGui::BeginTabItem("Settings")) {
    ImGui::Text("Theme Settings");
    ImGui::Separator();

    ImGui::Text("Select Theme:");
    if (ImGui::Combo("##theme_selector", &currentTheme, themeNames, IM_ARRAYSIZE(themeNames))) {
        applyTheme(currentTheme);
    }
    
    ImGui::Spacing();

    if (ImGui::Button("Open Theme Editor")) {
        showThemeEditor = true;
    }
    
    ImGui::Spacing();
    ImGui::Separator();

    ImGui::Text("Quick Theme Preview:");
    ImGui::Columns(4, nullptr, false);
    
    if (ImGui::Button("Dark")) {
        currentTheme = 0;
        applyTheme(currentTheme);
    }
    ImGui::NextColumn();
    
    if (ImGui::Button("Light")) {
        currentTheme = 1;
        applyTheme(currentTheme);
    }
    ImGui::NextColumn();
    
    if (ImGui::Button("Classic")) {
        currentTheme = 2;
        applyTheme(currentTheme);
    }
    ImGui::NextColumn();
    
    if (ImGui::Button("Cherry")) {
        currentTheme = 3;
        applyTheme(currentTheme);
    }
    
    ImGui::Columns(1);
    ImGui::Spacing();
    
    ImGui::Columns(4, nullptr, false);
    
    if (ImGui::Button("Dracula")) {
        currentTheme = 4;
        applyTheme(currentTheme);
    }
    ImGui::NextColumn();
    
    if (ImGui::Button("Cyberpunk")) {
        currentTheme = 5;
        applyTheme(currentTheme);
    }
    ImGui::NextColumn();
    
    if (ImGui::Button("Ocean")) {
        currentTheme = 6;
        applyTheme(currentTheme);
    }
    ImGui::NextColumn();
    
    if (ImGui::Button("Custom")) {
        currentTheme = 7;
        applyTheme(currentTheme);
        showThemeEditor = true;
    }
    
    ImGui::Columns(1);
    ImGui::Spacing();
    ImGui::Separator();

    ImGui::Text("Current Theme: %s", themeNames[currentTheme]);

    if (currentTheme == 7) {
        ImGui::Spacing();
        ImGui::Text("Custom Theme Controls:");
        
        if (ImGui::Button("Reset to Default Dark")) {
            applyDarkTheme();
            initializeCustomColors();
            ImGuiStyle& style = ImGui::GetStyle();
            for (int i = 0; i < ImGuiCol_COUNT; i++) {
                customColors[i] = style.Colors[i];
            }
        }
        ImGui::SameLine();
        
        if (ImGui::Button("Save Current as Custom")) {
            initializeCustomColors();
            ImGuiStyle& style = ImGui::GetStyle();
            for (int i = 0; i < ImGuiCol_COUNT; i++) {
                customColors[i] = style.Colors[i];
            }
        }
    }
    
    ImGui::EndTabItem();
}
            }
            ImGui::EndTabBar();
        }
        ); ImGui::End();
        
        renderThemeEditor();
    };

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
