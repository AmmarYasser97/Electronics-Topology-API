#ifndef TOPOLOGY_H
#define TOPOLOGY_H

#include "icomponent.h"
#include "resistance.h"
#include "nmos.h"
#include "Memory.h"

typedef multimap<string, string>::iterator MMAPIterator;

class Topology {
private:
  string id;
  vector <IComponent*> *components;
  multimap<string, string> nodesDatabase;
  Memory *memory;

public:
  explicit Topology(string id);
  int readJSON(const string& filename);
  bool writeJSON(string file);
  vector<json> queryTopologies();
  bool deleteTopology();
  vector<json> queryDevices();
  vector<string> queryDevicesWithNetlistNode(string netlistnodeID);
  ~Topology();
};

#endif // TOPOLOGY_H
