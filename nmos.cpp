#include "nmos.h"

Nmos::Nmos(string id, json value, json netlist): nmosID(id)
{
    nmosValue.deafault =  value.at("default");
    nmosValue.min = value.at("min");
    nmosValue.max = value.at("max");

    for(auto& node: netlist.items()){
        nmosNetlist[node.key()] = node.value();
    }
}

void Nmos::setID(string id){
    this->nmosID = id;
}

string Nmos::getID(){
    return this->nmosID;
}

void Nmos::setComponentValue(componentValue value){
    this->nmosValue.deafault =  value.deafault;
    this->nmosValue.min = value.min;
    this->nmosValue.max = value.max;
}

componentValue Nmos::getComponentValue(){
    return this->nmosValue;
}

void Nmos::setNetlist(unordered_map<string, string> netlist){
    for(auto& node: netlist) {
        this->nmosNetlist[node.first] = node.second;
    }
}

unordered_map<string, string> Nmos::getNetlist(){
    return this->nmosNetlist;
}
