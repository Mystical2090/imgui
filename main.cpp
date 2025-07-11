#include <Geode/Geode.hpp>
#include <imgui-cocos.hpp>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace geode::prelude;
using json = nlohmann::json;

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
bool yes = false;
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

std::string getSettingsPath() {
    return (Mod::get()->getConfigDir() / "polo_settings.json").string();
}

void saveSettings() {
    json settings;
    
    // Player settings
    settings["player"]["noclip"] = noclipEnabled;
    settings["player"]["ignoreInputs"] = ignoreInputsEnabled;
    settings["player"]["jumpHack"] = jumpHackEnabled;
    settings["player"]["autoclicker"] = autoclickerEnabled;
    
    // Editor settings
    settings["editor"]["verifyHack"] = verifyHackEnabled;
    settings["editor"]["copyHack"] = copyHackEnabled;
    settings["editor"]["noCMark"] = noCMarkEnabled;
    settings["editor"]["customObjectsBypass"] = customObjectsBypassEnabled;
    
    // Misc settings
    settings["misc"]["speedhackValue"] = speedhackValue;
    settings["misc"]["noWavePulseValue"] = noWavePulseValue;
    settings["misc"]["practiceMusicHack"] = practiceMusicHackEnabled;
    settings["misc"]["hidePauseButton"] = hidePauseButtonEnabled;
    settings["misc"]["layoutMode"] = layoutModeEnabled;
    settings["misc"]["commentHistoryBypass"] = commentHistoryBypassEnabled;
    settings["misc"]["autoPractice"] = autoPracticeEnabled;
    settings["misc"]["iconHack"] = iconHackEnabled;
    settings["misc"]["colorHack"] = colorHackEnabled;
    settings["misc"]["noSolids"] = noSolidsEnabled;
    settings["misc"]["suicide"] = suicideEnabled;
    settings["misc"]["showHitboxes"] = showHitboxesEnabled;
    settings["misc"]["showHitboxesOnDeath"] = showHitboxesOnDeathEnabled;
    settings["misc"]["rainbowIcons"] = rainbowIconsEnabled;
    settings["misc"]["everythingKillsYou"] = everythingKillsYouEnabled;
    settings["misc"]["safeMode"] = safeModeEnabled;
    settings["misc"]["instantComplete"] = instantCompleteEnabled;
    settings["misc"]["basementBypass"] = basementBypassEnabled;
    settings["misc"]["levelEdit"] = levelEditEnabled;
    settings["misc"]["mainLevelBypass"] = mainLevelBypassEnabled;
    settings["misc"]["towerBypass"] = towerBypassEnabled;
    settings["misc"]["noGlow"] = noGlowEnabled;
    
    std::ofstream file(getSettingsPath());
    if (file.is_open()) {
        file << settings.dump(4);
        file.close();
    }
}

void loadSettings() {
    std::ifstream file(getSettingsPath());
    if (!file.is_open()) {
        return; // File doesn't exist, use defaults
    }
    
    try {
        json settings;
        file >> settings;
        file.close();
        
        // Player settings
        if (settings.contains("player")) {
            noclipEnabled = settings["player"].value("noclip", false);
            ignoreInputsEnabled = settings["player"].value("ignoreInputs", false);
            jumpHackEnabled = settings["player"].value("jumpHack", false);
            autoclickerEnabled = settings["player"].value("autoclicker", false);
        }
        
        // Editor settings
        if (settings.contains("editor")) {
            verifyHackEnabled = settings["editor"].value("verifyHack", false);
            copyHackEnabled = settings["editor"].value("copyHack", false);
            noCMarkEnabled = settings["editor"].value("noCMark", false);
            customObjectsBypassEnabled = settings["editor"].value("customObjectsBypass", false);
        }
        
        // Misc settings
        if (settings.contains("misc")) {
            speedhackValue = settings["misc"].value("speedhackValue", 1.0f);
            noWavePulseValue = settings["misc"].value("noWavePulseValue", 1.0f);
            practiceMusicHackEnabled = settings["misc"].value("practiceMusicHack", false);
            hidePauseButtonEnabled = settings["misc"].value("hidePauseButton", false);
            layoutModeEnabled = settings["misc"].value("layoutMode", false);
            commentHistoryBypassEnabled = settings["misc"].value("commentHistoryBypass", false);
            autoPracticeEnabled = settings["misc"].value("autoPractice", false);
            iconHackEnabled = settings["misc"].value("iconHack", false);
            colorHackEnabled = settings["misc"].value("colorHack", false);
            noSolidsEnabled = settings["misc"].value("noSolids", false);
            suicideEnabled = settings["misc"].value("suicide", false);
            showHitboxesEnabled = settings["misc"].value("showHitboxes", false);
            showHitboxesOnDeathEnabled = settings["misc"].value("showHitboxesOnDeath", false);
            rainbowIconsEnabled = settings["misc"].value("rainbowIcons", false);
            everythingKillsYouEnabled = settings["misc"].value("everythingKillsYou", false);
            safeModeEnabled = settings["misc"].value("safeMode", false);
            instantCompleteEnabled = settings["misc"].value("instantComplete", false);
            basementBypassEnabled = settings["misc"].value("basementBypass", false);
            levelEditEnabled = settings["misc"].value("levelEdit", false);
            mainLevelBypassEnabled = settings["misc"].value("mainLevelBypass", false);
            towerBypassEnabled = settings["misc"].value("towerBypass", false);
            noGlowEnabled = settings["misc"].value("noGlow", false);
        }
    } catch (const std::exception& e) {
        // If JSON parsing fails, use defaults
        log::error("Failed to load settings: {}", e.what());
    }
}

$on_mod(Loaded) {
    loadSettings(); // Load settings on mod startup
    
    ImGuiCocos::get().setup([] {
        ImGui::StyleColorsDark();
    }).draw([]() {
        bool settingsChanged = false;
        
        ImGui::Begin("Polo", nullptr, ImGuiWindowFlags_NoCollapse);
        if (ImGui::BeginTabBar("Polo")) {
            if (ImGui::BeginTabItem("Misc")) {
                ImGui::Text("speedhack");
                ImGui::SameLine();
#ifdef GEODE_IS_IOS
                if (ImGui::InputFloat("##speedhack", &speedhackValue, 0.0f, 0.0f, "%.5f", ImGuiInputTextFlags_CharsDecimal)) {
                    settingsChanged = true;
                }
#else
                if (ImGui::InputFloat("##speedhack", &speedhackValue, 0.0f, 0.0f, "%.5f")) {
                    settingsChanged = true;
                }
#endif
                
                ImGui::Text("no wave pulse");
                ImGui::SameLine();
#ifdef GEODE_IS_IOS
                if (ImGui::InputFloat("##nowavepulse", &noWavePulseValue, 0.0f, 0.0f, "%.5f", ImGuiInputTextFlags_CharsDecimal)) {
                    settingsChanged = true;
                }
#else
                if (ImGui::InputFloat("##nowavepulse", &noWavePulseValue, 0.0f, 0.0f, "%.5f")) {
                    settingsChanged = true;
                }
#endif
                
                ImGui::Text("practice music hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##practicemusichack", &practiceMusicHackEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("hide pause button");
                ImGui::SameLine();
                if (ImGui::Checkbox("##hidepausebutton", &hidePauseButtonEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("layout mode");
                ImGui::SameLine();
                if (ImGui::Checkbox("##layoutmode", &layoutModeEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("comment history bypass");
                ImGui::SameLine();
                if (ImGui::Checkbox("##commenthistorybypass", &commentHistoryBypassEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("auto practice");
                ImGui::SameLine();
                if (ImGui::Checkbox("##autopractice", &autoPracticeEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("icon hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##iconhack", &iconHackEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("color hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##colorhack", &colorHackEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("no solids");
                ImGui::SameLine();
                if (ImGui::Checkbox("##nosolids", &noSolidsEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("suicide");
                ImGui::SameLine();
                if (ImGui::Checkbox("##suicide", &suicideEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("show hitboxes");
                ImGui::SameLine();
                if (ImGui::Checkbox("##showhitboxes", &showHitboxesEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("show hitboxes on death");
                ImGui::SameLine();
                if (ImGui::Checkbox("##showhitboxesondeath", &showHitboxesOnDeathEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("rainbow icons");
                ImGui::SameLine();
                if (ImGui::Checkbox("##rainbowicons", &rainbowIconsEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("everything kills you");
                ImGui::SameLine();
                if (ImGui::Checkbox("##everythingkillsyou", &everythingKillsYouEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("safe mode");
                ImGui::SameLine();
                if (ImGui::Checkbox("##safemode", &safeModeEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("instant complete");
                ImGui::SameLine();
                if (ImGui::Checkbox("##instantcomplete", &instantCompleteEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("basement bypass");
                ImGui::SameLine();
                if (ImGui::Checkbox("##basementbypass", &basementBypassEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("level edit");
                ImGui::SameLine();
                if (ImGui::Checkbox("##leveledit", &levelEditEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("main level bypass");
                ImGui::SameLine();
                if (ImGui::Checkbox("##mainlevelbypass", &mainLevelBypassEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("tower bypass");
                ImGui::SameLine();
                if (ImGui::Checkbox("##towerbypass", &towerBypassEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("no glow");
                ImGui::SameLine();
                if (ImGui::Checkbox("##noglow", &noGlowEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Editor")) {
                ImGui::Text("verify hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##verifyhack", &verifyHackEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("copy hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##copyhack", &copyHackEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("no c mark");
                ImGui::SameLine();
                if (ImGui::Checkbox("##nocmark", &noCMarkEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("custom objects bypass");
                ImGui::SameLine();
                if (ImGui::Checkbox("##customobjectsbypass", &customObjectsBypassEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Player")) {
                ImGui::Text("noclip");
                ImGui::SameLine();
                if (ImGui::Checkbox("##noclip", &noclipEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("ignore inputs");
                ImGui::SameLine();
                if (ImGui::Checkbox("##ignoreinputs", &ignoreInputsEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("jump hack");
                ImGui::SameLine();
                if (ImGui::Checkbox("##jumphack", &jumpHackEnabled)) {
                    settingsChanged = true;
                }
                
                ImGui::Text("autoclicker");
                ImGui::SameLine();
                if (ImGui::Checkbox("##autoclicker", &autoclickerEnabled)) {
                    settingsChanged = true;
                }
                ImGui::EndTabItem();
            }
                
            if (ImGui::BeginTabItem("Credits")) {
                ImGui::Text("Gtxx9003, Developer, Features, more..");
                ImGui::Text("Mystical433, Leader Developer, Features, ui, more...");
                ImGui::Text("Speedyfriend67, Developer, Bug fixes");
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Info")) {
                ImGui::Text("Polo version v1.0.0");
                ImGui::Text("Nightly Release: ");
                ImGui::SameLine();
                ImGui::Text("False");
                
                ImGui::Separator();
                
                if (ImGui::Button("Save Settings")) {
                    saveSettings();
                }
                ImGui::SameLine();
                if (ImGui::Button("Load Settings")) {
                    loadSettings();
                }
                
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
        ImGui::End();
        
        // Auto-save when settings change
        if (settingsChanged) {
            saveSettings();
        }
    });
}

$on_mod(Unloaded) {
    saveSettings(); // Save settings when mod is unloaded
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
