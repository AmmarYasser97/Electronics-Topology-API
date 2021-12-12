#include "Memory.h"

Memory::Memory() {};

Memory *Memory::getMemory() {
    if(!memory)
        memory = new Memory;
    return memory;
}

bool Memory::add(const string& id, json file){
    this->blocks[id] = file;
    this->size++;
    return true;
}

bool Memory::remove(const json& fileID){
    if(this->size < 1)
        return false;

    for(auto& block: this->blocks){
        if(block.first == fileID) {
            this->blocks.erase(fileID);
            size --;
            return true;
        }
    }
    return false;
}

json Memory::getFile(string fileID) {
    for (auto &block: this->blocks) {
        if (block.first == fileID) {
            return block.second;
        }
    }
}

vector<json> Memory::query(){
    vector<json> result;
    for(const auto& block: this->blocks){
        result.push_back(block.second);
    }
    return result;
}

Memory *Memory:: memory = 0;