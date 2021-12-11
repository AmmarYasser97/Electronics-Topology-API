#include "resistance.h"

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

}

string Resistance::getID(){

}

void Resistance::setComponentValue(componentValue value){

}

componentValue Resistance::getComponentValue(){

}

void Resistance::setNetlist(unordered_map<string, string> netlist){

}

unordered_map<string, string> Resistance::getNetlist(){

}

