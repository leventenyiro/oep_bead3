#include "simulation.hpp"

using namespace std;

#ifdef NORMAL_MODE
//#define NORMAL_MODE

int main() {
    Simulation test = Simulation("input3.txt");
    test.run(true);

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("no colony", "input0.txt") {
    Simulation s = Simulation("input0.txt");
    
}

#endif