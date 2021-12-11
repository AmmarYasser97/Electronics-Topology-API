#include "nmos.h"

Nmos::Nmos(string id, json value, json netlist): nmosID(id)
{
    nmosValue.deafault =  value.at("defaultx");
    nmosValue.min = value.at("min");
    nmosValue.max = value.at("max");

    for(auto& node: netlist.items()){
        nmosNetlist[node.key()] = node.value();
    }
}

void Nmos::setID(string id){

}

string Nmos::getID(){

}

void Nmos::setComponentValue(componentValue value){

}

componentValue Nmos::getComponentValue(){

}

void Nmos::setNetlist(unordered_map<string, string> netlist){

}

unordered_map<string, string> Nmos::getNetlist(){

}
