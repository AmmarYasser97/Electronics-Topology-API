#include "topology.h"

using namespace std;

Topology::Topology(string topologyID): id(topologyID){
    components = new vector <IComponent*>;
}
bool Topology::readJSON(const string& filename){
    ifstream topologyFile(filename);
    json topologyJSON;

    if(topologyFile >> topologyJSON)
    {
        for (auto component: topologyJSON.at("components")) {
            string type = component["type"];
            if (type == "resistor")
                this->components->push_back(new Resistance(component.at("id"), component.at("resistance"),component.at("netlist")));
            else if (type == "nmos")
                this->components->push_back(new Nmos(component.at("id"), component.at("m(l)"),component.at("netlist")));
            else
                return  false;
        }
        return true;
    }
}

bool Topology::writeJSON(string topologyID){
//    std::ofstream o("pretty.json");
//    o << std::setw(4) << j << std::endl;
}

vector<Topology> Topology::queryTopologies(){

}

bool Topology::deleteTopology(string topologyID){

}

vector<IComponent> * Topology::queryDevices(string topologyID){

}

vector<IComponent> * Topology::queryDevicesWithNetlistNode(string topologyID,
                                                string netlistnodeID){

}

Topology::~Topology() {

}
