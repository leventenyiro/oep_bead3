#include "simulation.hpp"

using namespace std;

int main() {
    Simulation test = Simulation("input.txt");
    test.run(true);

    return 0;
}