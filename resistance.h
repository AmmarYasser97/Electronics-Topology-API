#ifndef RESISTANCE_H
#define RESISTANCE_H

#include "icomponent.h"

class Resistance : IComponent {
private:
  string resID;
  string resType;
  componentValue resValue;
  unordered_map<string, string> netlist;

public:
  Resistance();
  void setType(string type);
  string getType();
  void setID(string id);
  string getID();
  void setComponentValue(componentValue value);
  componentValue getComponentValue();
  void setNetlist(unordered_map<string, string> netlist);
  unordered_map<string, string> getNetlist();
};

#endif // RESISTANCE_H
