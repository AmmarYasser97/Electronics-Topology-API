#include <iostream>
#include "topology.h"

using namespace std;

int main() {
    Topology t1("t1");

    cout << t1.readJSON("/home/ammar/CLionProjects/topologyAPI/topology.json") << endl;
    return 0;
}

// component.dump(2)