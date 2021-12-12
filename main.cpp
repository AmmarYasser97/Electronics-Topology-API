#include <iostream>
#include "topology.h"

using namespace std;

int main() {
    Topology top1("top1");

    cout << top1.readJSON("/home/ammar/CLionProjects/topologyAPI/topology.json") << endl;

    top1.queryDevices();
    top1.queryDevicesWithNetlistNode("n1");
    top1.deleteTopology();

    return 0;
}

// component.dump(2)