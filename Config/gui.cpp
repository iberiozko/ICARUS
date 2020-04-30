#include "gui.h"
#include "validators.h"
namespace ICARUS {
namespace Config {

bool GUIScreen::parseJsonValue(rapidjson::Value doc) {
    bool result = true;
    result = validateBool(enabled, doc, "gui.screens[].", "enabled", false) && result;
    result = validateBool(fullScreen, doc, "gui.screens[].", "fullScreen", false) && result;
    result = validateInt(screenId, doc, "gui.screens[].", "screenId", false, 0, std::numeric_limits<int>::max()) && result;
    result = validateInt(x, doc, "gui.screens[].", "x", false, 0, std::numeric_limits<int>::max()) && result;
    result = validateInt(y, doc, "gui.screens[].", "y", false, 0, std::numeric_limits<int>::max()) && result;
    result = validateInt(width, doc, "gui.screens[].", "width", false, 0, std::numeric_limits<int>::max()) && result;
    result = validateInt(height, doc, "gui.screens[].", "height", false, 0, std::numeric_limits<int>::max()) && result;
    result = validateString(bootstrap, doc, "gui.screens[].", "bootstrap", false) && result;
    result = validateString(application, doc, "gui.screens[].", "application", false) && result;
    return result;
}

QVariant GUIScreen::toVariant() {
    QVariantMap map;
    map.insert("enabled", enabled);
    map.insert("fullScreen", fullScreen);
    map.insert("screenId", screenId);
    map.insert("x", x);
    map.insert("y", y);
    map.insert("width", width);
    map.insert("height", height);
    map.insert("bootstrap", QString(bootstrap.c_str()));
    map.insert("application", QString(application.c_str()));
    return QVariant(map);
}

bool GUI::parseJsonValue(rapidjson::Value doc) {
    bool result = true;
    result = validateBool(enabled, doc, "gui.", "enabled", false) && result;
    if (checkObject(doc, "gui.", "workerCfg", false)) { result = workerCfg.parseJsonValue(doc["workerCfg"].GetObject()) && result; }
    if (checkList(doc, "gui.", "screens", false)) {
        rapidjson::Value scr = doc["screens"].GetArray();
        for (rapidjson::SizeType i = 0; i < scr.Size(); i++) {
            if (!scr[i].IsObject()) { LOG_F(ERROR, "Configuration: gui.screens[%d] should be of type: object", i); result = false; }
            else {
                GUIScreen screen;
                if (screen.parseJsonValue(scr[i].GetObject())) { screens.push_back(screen); }
                else { LOG_F(ERROR, "Configuration: gui.screens[%d] has wrong configuration", i); result = false; }
            }
        }
    }
    return result;
}

QVariant GUI::toVariant() {
    QVariantMap map;
    map.insert("enabled", enabled);
    map.insert("workerCfg", workerCfg.toVariant());
    QVariantList scr;
    for (auto it = screens.begin(); it != screens.end(); ++it) { scr.push_back(it->toVariant()); }
    map.insert("screens", scr);
    return QVariant(map);
}

} // namespace Config
} // namespace ICARUS
