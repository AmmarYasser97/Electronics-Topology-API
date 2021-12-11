#include "topology.h"

using namespace std;

Topology::Topology(string tobologyID): id(tobologyID){
    vector <IComponent> *components = new vector<IComponent>;
}

bool Topology::readJSON(const string filename){
}

bool Topology::writeJSON(string topologyID){

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
