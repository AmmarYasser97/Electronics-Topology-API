#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include <bits/stdc++.h>
#include <unordered_map>
#include <string>
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

struct componentValue {
  float deafault;
  float min;
  float max;
};

class IComponent {
public:
//  IComponent();
  virtual void setID(string id) = 0;
  virtual string getID() = 0;
  virtual void setComponentValue(componentValue value) = 0;
  virtual componentValue getComponentValue() = 0;
  virtual void setNetlist(unordered_map<string, string> netlist) = 0;
  virtual unordered_map<string, string> getNetlist() = 0;

};

#endif // ICOMPONENT_H
