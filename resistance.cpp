#include "resistance.h"

/**
 *
 * @param id
 * @param value
 * @param netlist
 */
Resistance::Resistance(string id, json value, json netlist): resID(id)
{
    resValue.deafault =  value.at("default");
    resValue.min = value.at("min");
    resValue.max = value.at("max");

    for(auto& node: netlist.items()){
        resNetlist[node.key()] = node.value();
    }
}

void Resistance::setID(string id){
    this->resID = id;
}

string Resistance::getID(){
    return this->resID;
}

void Resistance::setComponentValue(componentValue value){
    this->resValue.deafault =  value.deafault;
    this->resValue.min = value.min;
    this->resValue.max = value.max;
}

componentValue Resistance::getComponentValue(){
    return this->resValue;
}

void Resistance::setNetlist(unordered_map<string, string> netlist){
    for(auto& node: netlist) {
        this->resNetlist[node.first] = node.second;
    }
}

unordered_map<string, string> Resistance::getNetlist(){
    return this->resNetlist;
}

