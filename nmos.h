#ifndef NMOS_H
#define NMOS_H

#include "icomponent.h"

class Nmos : public IComponent {
private:
  string nmosID;
  componentValue nmosValue;
  unordered_map<string, string> nmosNetlist;

public:
  Nmos(string id, json value, json netlist);
  void setID(string id);
  string getID();
  void setComponentValue(componentValue value);
  componentValue getComponentValue();
  void setNetlist(unordered_map<string, string> netlist);
  unordered_map<string, string> getNetlist();
};

#endif // NMOS_H
