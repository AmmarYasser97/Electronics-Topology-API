#ifndef RESISTANCE_H
#define RESISTANCE_H

#include "icomponent.h"

class Resistance : public IComponent {
private:
  string resID;
  componentValue resValue;
  unordered_map<string, string> resNetlist;

public:
  Resistance(string id, json value, json netlist);
  void setID(string id);
  string getID();
  void setComponentValue(componentValue value);
  componentValue getComponentValue();
  void setNetlist(unordered_map<string, string> netlist);
  unordered_map<string, string> getNetlist();
};

#endif // RESISTANCE_H
