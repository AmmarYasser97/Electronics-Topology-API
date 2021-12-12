#include "topology.h"

using namespace std;

Topology::Topology(string topologyID): id(topologyID){
    components = new vector <IComponent*>;
    memory = memory->getMemory();
}

bool Topology::readJSON(const string& filename){
    ifstream topologyFile(filename);
    json topologyJSON;

    topologyFile >> topologyJSON;
    memory->add(topologyJSON["id"], filename);

    for (const auto& component: topologyJSON.at("components")) {
        string type = component["type"];
        if (type == "resistor")
            this->components->push_back(new Resistance(component.at("id"), component.at("resistance"),component.at("netlist")));
        else if (type == "nmos")
            this->components->push_back(new Nmos(component.at("id"), component.at("m(l)"),component.at("netlist")));
        else
            return  false;
    }
    return false;
}

bool Topology::writeJSON(string topologyID, string file){
    json topology = memory->getFile(topologyID);

    ofstream outfile (file);
    outfile << setw(4) << topology << endl;
    return true;
}

vector<json> Topology::queryTopologies(){
    return memory->query();
}

bool Topology::deleteTopology(string topologyID){
    return memory->remove(topologyID);
}

vector<json> Topology::queryDevices(string topologyID){
    vector<json> result;

    json topology = memory->getFile(topologyID);
    for(const auto& device : topology.at("components")){
        result.push_back(device);
    }
    return result;
}

vector<string> Topology::queryDevicesWithNetlistNode(string topologyID,
                                                string netlistnodeID){
    vector<string> result;
    string node, value;

    json topology = memory->getFile(topologyID);
    for (const auto& component: topology.at("components")) {
        json netlist = component.at("netlist");
        for(auto& node: netlist.items()){
            this->nodesDatabase[node.value()] = component["id"];
        }
    }
    result.push_back(this->nodesDatabase[netlistnodeID]);

    return result;
}

Topology::~Topology() {
    delete components;
}

