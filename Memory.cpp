#include "Memory.h"

Memory::Memory()= default;

bool Memory::addToMemory(const string& id, json file){
    this->blocks[id] = file;
}

bool Memory::removeFromMemory(const json& fileID){
    for(auto& block: this->blocks){
        if(block.first == fileID)
            this->blocks.erase(fileID);
    }
}

unordered_map<string ,json> Memory::queryMemory(){
    for(const auto& block: this->blocks){
        cout << "Memory ID" << block.first << endl << block.second.dump(2)<<endl;
        cout << "=================================================================="<<endl;
    }
}