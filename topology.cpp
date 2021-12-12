#include "topology.h"

using namespace std;

/**
 * Initialize the topology class instance by passing the topology id.
 * @param topologyID unique identifier for the topology
 */
Topology::Topology(string topologyID): id(topologyID){
    components = new vector <IComponent*>;
    memory = memory->getMemory();
}

/**
 * Read topology JSON file from passed filename by the help of third-party JSON library
 * Add the topology in the memory for future use
 * @param filename
 * @return integer value represent the address of the stored file in the memory
 */
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

/**
 * Given a existing file name with getting the topology id from the current instance
 * @param file
 * @return boolean value indicates if this file found in the memory or not
 */
bool Topology::writeJSON(string file){
    json topology = memory->getFile(this->id);

    ofstream outfile (file);
    outfile << setw(4) << topology << endl;
    return true;
}

/**
 * Query all the topologies that currently in the memory
 * @return List of topologies
 */
vector<json> Topology::queryTopologies(){
    return memory->query();
}

/**
 * Delete given topology id (the topology id from the current instance)
 * @return boolean value indicates if the topology found in the memory
 */
bool Topology::deleteTopology(){
    return memory->remove(this->id);
}

/**
 * Query all the devices of passed topology (the topology from the current instance)
 * @return List of the topology's devices
 */
vector<json> Topology::queryDevices(){
    vector<json> result;

    json topology = memory->getFile(this->id);
    for(const auto& device : topology.at("components")){
        result.push_back(device);
    }
    return result;
}

/**
 * For every device in a given topology (the topology from the current instance),
 * store all its nodes from netlist into multi value hash table as (nodelistvalue, device ID) then
 * search with the netlistnodeID in the hashtable and return a vector of the devices connected to this node.
 * @param netlistnodeID node unique id
 * @return vector of the devices connected to passed nodeID
 */
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

/**
 * Class destructor deletes the components pointer
 */
Topology::~Topology() {
    delete components;
}

