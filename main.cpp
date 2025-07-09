
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

// Theme variables
int currentTheme = 0;
const char* themeNames[] = { "Dark", "Light", "Classic", "Cherry", "Dracula", "Cyberpunk", "Ocean", "Custom" };
bool showThemeEditor = false;
ImVec4 customColors[ImGuiCol_COUNT];
bool customColorsInitialized = false;

// Theme functions
void applyDarkTheme() {
    ImGui::StyleColorsDark();
}

void applyLightTheme() {
    ImGui::StyleColorsLight();
}

void applyClassicTheme() {
    ImGui::StyleColorsClassic();
}

void applyCherryTheme() {
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 5.3f;
    style.GrabRounding = 2.3f;
    style.FrameRounding = 2.3f;
    style.ScrollbarRounding = 5.0f;
    style.TabRounding = 4.0f;
    
    ImVec4* colors = style.Colors;
    colors[ImGuiCol_Text] = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.86f, 0.93f, 0.89f, 0.58f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
    colors[ImGuiCol_Border] = ImVec4(0.54f, 0.20f, 0.31f, 1.00f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.54f, 0.20f, 0.31f, 0.78f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.54f, 0.20f, 0.31f, 1.00f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.54f, 0.20f, 0.31f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.20f, 0.22f, 0.27f, 0.75f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.20f, 0.22f, 0.27f, 0.47f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.54f, 0.20f, 0.31f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.54f, 0.20f, 0.31f, 0.78f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.54f, 0.20f, 0.31f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.54f, 0.20f, 0.31f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.54f, 0.20f, 0.31f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.54f, 0.20f, 0.31f, 1.00f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.54f, 0.20f, 0.31f, 0.86f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.54f, 0.20f, 0.31f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.54f, 0.20f, 0.31f, 0.76f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.54f, 0.20f, 0.31f, 0.86f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.54f, 0.20f, 0.31f, 1.00f);
    colors[ImGuiCol_Tab] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.54f, 0.20f, 0.31f, 0.86f);
    colors[ImGuiCol_TabActive] = ImVec4(0.54f, 0.20f, 0.31f, 1.00f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.54f, 0.20f, 0.31f, 0.57f);
}

void applyDraculaTheme() {
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 5.3f;
    style.GrabRounding = 2.3f;
    style.FrameRounding = 2.3f;
    style.ScrollbarRounding = 5.0f;
    style.TabRounding = 4.0f;
    
    ImVec4* colors = style.Colors;
    colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.36f, 0.42f, 0.47f, 1.00f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.12f, 0.20f, 0.28f, 1.00f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.09f, 0.12f, 0.14f, 1.00f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.09f, 0.12f, 0.14f, 0.65f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.39f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.18f, 0.22f, 0.25f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.09f, 0.21f, 0.31f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.37f, 0.61f, 1.00f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.20f, 0.25f, 0.29f, 0.55f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_Tab] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
    colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
}

void applyCyberpunkTheme() {
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 0.0f;
    style.GrabRounding = 0.0f;
    style.FrameRounding = 0.0f;
    style.ScrollbarRounding = 0.0f;
    style.TabRounding = 0.0f;
    
    ImVec4* colors = style.Colors;
    colors[ImGuiCol_Text] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.00f, 0.40f, 0.41f, 1.00f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.94f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.94f);
    colors[ImGuiCol_Border] = ImVec4(0.00f, 1.00f, 1.00f, 0.50f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.44f, 0.80f, 0.80f, 0.18f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.44f, 0.80f, 0.80f, 0.27f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.44f, 0.81f, 0.86f, 0.66f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.14f, 0.18f, 0.21f, 0.73f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.27f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.20f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.22f, 0.29f, 0.30f, 0.71f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.00f, 1.00f, 1.00f, 0.44f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.74f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 1.00f, 1.00f, 0.68f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.00f, 1.00f, 1.00f, 0.36f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.76f);
    colors[ImGuiCol_Button] = ImVec4(0.00f, 0.65f, 0.65f, 0.46f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.01f, 1.00f, 1.00f, 0.43f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.62f);
    colors[ImGuiCol_Header] = ImVec4(0.00f, 1.00f, 1.00f, 0.33f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.42f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
    colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.50f, 0.50f, 0.33f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.42f);
    colors[ImGuiCol_TabActive] = ImVec4(0.00f, 0.75f, 0.75f, 0.54f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.00f, 0.25f, 0.25f, 0.33f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.00f, 0.50f, 0.50f, 0.54f);
}

void applyOceanTheme() {
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 7.0f;
    style.GrabRounding = 3.0f;
    style.FrameRounding = 3.0f;
    style.ScrollbarRounding = 7.0f;
    style.TabRounding = 5.0f;
    
    ImVec4* colors = style.Colors;
    colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.36f, 0.42f, 0.47f, 1.00f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.11f, 0.15f, 0.25f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.15f, 0.18f, 0.30f, 1.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.15f, 0.94f);
    colors[ImGuiCol_Border] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.25f, 0.40f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.12f, 0.20f, 0.45f, 1.00f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.09f, 0.12f, 0.35f, 1.00f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.09f, 0.12f, 0.20f, 0.65f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.08f, 0.10f, 0.25f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.15f, 0.18f, 0.30f, 1.00f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.10f, 0.39f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.25f, 0.40f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.18f, 0.22f, 0.35f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.09f, 0.21f, 0.50f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.37f, 0.61f, 1.00f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.20f, 0.25f, 0.40f, 1.00f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.20f, 0.25f, 0.40f, 0.55f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_Tab] = ImVec4(0.11f, 0.15f, 0.25f, 1.00f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
    colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.25f, 0.40f, 1.00f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.11f, 0.15f, 0.25f, 1.00f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.11f, 0.15f, 0.25f, 1.00f);
}

void applyCustomTheme() {
    ImGuiStyle& style = ImGui::GetStyle();
    for (int i = 0; i < ImGuiCol_COUNT; i++) {
        style.Colors[i] = customColors[i];
    }
}

void initializeCustomColors() {
    if (!customColorsInitialized) {
        ImGuiStyle& style = ImGui::GetStyle();
        for (int i = 0; i < ImGuiCol_COUNT; i++) {
            customColors[i] = style.Colors[i];
        }
        customColorsInitialized = true;
    }
}

void applyTheme(int theme) {
    switch (theme) {
        case 0: applyDarkTheme(); break;
        case 1: applyLightTheme(); break;
        case 2: applyClassicTheme(); break;
        case 3: applyCherryTheme(); break;
        case 4: applyDraculaTheme(); break;
        case 5: applyCyberpunkTheme(); break;
        case 6: applyOceanTheme(); break;
        case 7: applyCustomTheme(); break;
    }
}

void renderThemeEditor() {
    if (!showThemeEditor) return;
    
    ImGui::Begin("Theme Editor", &showThemeEditor);
    
    ImGui::Text("Theme Selection:");
    if (ImGui::Combo("##theme", &currentTheme, themeNames, IM_ARRAYSIZE(themeNames))) {
        applyTheme(currentTheme);
    }
    
    ImGui::Separator();
    
    if (currentTheme == 7) { // Custom theme
        ImGui::Text("Custom Theme Editor:");
        initializeCustomColors();
        
        if (ImGui::Button("Reset to Current Style")) {
            ImGuiStyle& style = ImGui::GetStyle();
            for (int i = 0; i < ImGuiCol_COUNT; i++) {
                customColors[i] = style.Colors[i];
            }
        }
        
        ImGui::BeginChild("ColorEditor", ImVec2(0, 300), true);
        for (int i = 0; i < ImGuiCol_COUNT; i++) {
            ImGui::PushID(i);
            ImGui::ColorEdit4(ImGui::GetStyleColorName(i), (float*)&customColors[i],
                             ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_AlphaPreview);
            ImGui::PopID();
        }
        ImGui::EndChild();
        
        if (ImGui::Button("Apply Custom Theme")) {
            applyCustomTheme();
        }
    } else {
        ImGui::Text("Selected Theme: %s", themeNames[currentTheme]);
        ImGui::Text("Use the dropdown above to switch between themes.");
        ImGui::Text("Select 'Custom' to create your own theme.");
    }
    
    ImGui::End();
}

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
        ) ImGui::End();
        
        renderThemeEditor();
    });
)
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
