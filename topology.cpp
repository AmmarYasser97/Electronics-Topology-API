#include "topology.h"

using namespace std;

Topology::Topology(string topologyID): id(topologyID){
    components = new vector <IComponent*>;
    memory = memory->getMemory();
}

int Topology::readJSON(const string& filename){
    ifstream topologyFile(filename);
    json topologyJSON;

    topologyFile >> topologyJSON;

    for (const auto& component: topologyJSON.at("components")) {
        string type = component["type"];
        if (type == "resistor")
            this->components->push_back(new Resistance(component.at("id"), component.at("resistance"),component.at("netlist")));
        else if (type == "nmos")
            this->components->push_back(new Nmos(component.at("id"), component.at("m(l)"),component.at("netlist")));
    }
    return memory->add(topologyJSON["id"], topologyJSON);
}

bool Topology::writeJSON(string file){
    json topology = memory->getFile(this->id);

    ofstream outfile (file);
    outfile << setw(4) << topology << endl;
    return true;
}

vector<json> Topology::queryTopologies(){
    return memory->query();
}

bool Topology::deleteTopology(){
    return memory->remove(this->id);
}

vector<json> Topology::queryDevices(){
    vector<json> result;

    json topology = memory->getFile(this->id);
    for(const auto& device : topology.at("components")){
        result.push_back(device);
    }
    return result;
}

vector<string> Topology::queryDevicesWithNetlistNode(string netlistnodeID){
    vector<string> result;
    string node, value;

    json topology = memory->getFile(this->id);
    for (const auto& component: topology.at("components")) {
        json netlist = component.at("netlist");
        for(auto& node: netlist.items()){
            this->nodesDatabase.insert(pair<string, string>(node.value(),component["id"]));
        }
    }

    pair<MMAPIterator, MMAPIterator> values = this->nodesDatabase.equal_range(netlistnodeID);
    for (MMAPIterator it = values.first; it != values.second; it++){
        result.push_back(it->second);
    }
    return result;
}

Topology::~Topology() {
    delete components;
}

