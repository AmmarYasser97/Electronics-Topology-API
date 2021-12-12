#ifndef TOPOLOGYAPI_MEMORY_H
#define TOPOLOGYAPI_MEMORY_H

#include <bits/stdc++.h>
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class Memory {
private:
    static Memory *memory;
    int size;
    unordered_map<string, json> blocks;
    Memory();

public:
    static Memory *getMemory();
    bool add(const string& id, json file);
    bool remove(const json& fileID);
    json getFile(string fileID);
    vector<json> query();
};


#endif //TOPOLOGYAPI_MEMORY_H
