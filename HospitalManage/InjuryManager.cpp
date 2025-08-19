#include "InjuryManager.h"

// קונסטרקטור – אתחול הפציעות וזמני הדחיפות
InjuryManager::InjuryManager() {
    // אתחול זמני המתנה לכל פציעה (בדקות)
    injuryWaitTimes["Chest pain"] = 10;
    injuryWaitTimes["Sudden difficulty breathing"] = 10;
    injuryWaitTimes["Severe injury"] = 10;
    injuryWaitTimes["Severe bleeding"] = 10;
    injuryWaitTimes["Signs of stroke"] = 10;
    injuryWaitTimes["Seizures"] = 10;
    injuryWaitTimes["Suspected fractures"] = 60;
    injuryWaitTimes["Very high fever"] = 120;
    injuryWaitTimes["Poisoning"] = 10;
    injuryWaitTimes["Severe allergic reactions"] = 10;
    injuryWaitTimes["Persistent vomiting"] = 240;
    injuryWaitTimes["Severe abdominal pain"] = 120;
    injuryWaitTimes["Eye injuries"] = 120;
    injuryWaitTimes["Severe mental health crisis"] = 10;
    injuryWaitTimes["Loss of consciousness"] = 10;
    injuryWaitTimes["Sudden swelling or pain in limbs"] = 120;
    injuryWaitTimes["Animal or snake bites"] = 10;

    // אתחול סוגי הדחיפות לכל פציעה
    injuryTypes["Chest pain"] = 2;
    injuryTypes["Sudden difficulty breathing"] = 2;
    injuryTypes["Severe injury"] = 2;
    injuryTypes["Severe bleeding"] = 2;
    injuryTypes["Signs of stroke"] = 1;
    injuryTypes["Seizures"] = 3;
    injuryTypes["Suspected fractures"] = 3;
    injuryTypes["Very high fever"] = 2;
    injuryTypes["Poisoning"] = 1;
    injuryTypes["Severe allergic reactions"] = 1;
    injuryTypes["Persistent vomiting"] = 3;
    injuryTypes["Severe abdominal pain"] = 2;
    injuryTypes["Eye injuries"] = 2;
    injuryTypes["Severe mental health crisis"] = 3;
    injuryTypes["Loss of consciousness"] = 1;
    injuryTypes["Sudden swelling or pain in limbs"] = 3;
    injuryTypes["Animal or snake bites"] = 1;
}

// מחזיר את סוג הדחיפות (urgency) של פציעה
int InjuryManager::getInjuryType(const string& injury) const {
    auto it = injuryTypes.find(injury);
    if (it != injuryTypes.end()) {
        return it->second;
    }
    return -1; // אם הפציעה לא קיימת
}

// מחזיר רשימה של כל הפציעות הקיימות
vector<string> InjuryManager::getInjuryList() const {
    vector<std::string> injuryList;
    for (const auto& entry : injuryTypes) {
        injuryList.push_back(entry.first);
    }
    return injuryList;
}
