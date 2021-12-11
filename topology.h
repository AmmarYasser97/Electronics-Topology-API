#ifndef TOPOLOGY_H
#define TOPOLOGY_H

#include "nlohmann/json.hpp"
#include "icomponent.h"

using namespace std;
using json = nlohmann::json;

class Topology {
private:
  string id;
  vector <IComponent> *components{};

public:
  Topology(string id);
  bool readJSON(const string filename);
  bool writeJSON(string topologyID);
  vector<Topology> queryTopologies();
  bool deleteTopology(string topologyID);
  vector<IComponent> *queryDevices(string topologyID);
  vector<IComponent> *queryDevicesWithNetlistNode(string topologyID,
                                                 string netlistnodeID);
  ~Topology();
};

#endif // TOPOLOGY_H
