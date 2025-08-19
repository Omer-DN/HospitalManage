#pragma once
#include <vector>
#include <string>
#include <map>
using namespace std;

class InjuryManager {
private:
   map<string, int> injuryWaitTimes;
   map<string, int> injuryTypes;

public:
    InjuryManager();
    int getInjuryType(const string& injury) const;
    vector<string> getInjuryList() const;
};
