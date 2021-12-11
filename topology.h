#ifndef TOPOLOGY_H
#define TOPOLOGY_H

#include "memory.h"
#include "icomponent.h"
#include "resistance.h"
#include "nmos.h"


class Topology {
private:
  string id;
  vector <IComponent*> *components;
  static Memory memory;

public:
  Topology(string id);
  bool readJSON(const string& filename);
  bool writeJSON(string topologyID);
  vector<Topology> queryTopologies();
  bool deleteTopology(string topologyID);
  vector<IComponent> *queryDevices(string topologyID);
  vector<IComponent> *queryDevicesWithNetlistNode(string topologyID,
                                                 string netlistnodeID);
  ~Topology();
};

#endif // TOPOLOGY_H
