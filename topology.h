#ifndef TOPOLOGY_H
#define TOPOLOGY_H

#include "icomponent.h"
#include "resistance.h"
#include "nmos.h"
#include "Memory.h"


class Topology {
private:
  string id;
  vector <IComponent*> *components;
  unordered_map<string, string> nodesDatabase;
  Memory *memory;

public:
  explicit Topology(string id);
  bool readJSON(const string& filename);
  bool writeJSON(string topologyID, string file);
  vector<json> queryTopologies();
  bool deleteTopology(string topologyID);
  vector<json> queryDevices(string topologyID);
  vector<string> queryDevicesWithNetlistNode(string topologyID,
                                                 string netlistnodeID);
  ~Topology();
};

#endif // TOPOLOGY_H
