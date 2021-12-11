#ifndef TOPOLOGYAPI_MEMORY_H
#define TOPOLOGYAPI_MEMORY_H

#include <bits/stdc++.h>
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class Memory {
private:
    unordered_map<string, json> blocks;

public:
    Memory();
    bool addToMemory(const string& id, json file);
    bool removeFromMemory(const json& fileID);
    unordered_map<string ,json> queryMemory();
};


#endif //TOPOLOGYAPI_MEMORY_H
