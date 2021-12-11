#ifndef NMOS_H
#define NMOS_H

#include "icomponent.h"

class Nmos : IComponent {
private:
  string nmosID;
  string nmostype;
  componentValue nmosvalue;
  unordered_map<string, string> netlist;

public:
  Nmos();
  void setType(string type);
  string getType();
  void setID(string id);
  string getID();
  void setComponentValue(componentValue value);
  componentValue getComponentValue();
  void setNetlist(unordered_map<string, string> netlist);
  unordered_map<string, string> getNetlist();
};

#endif // NMOS_H
