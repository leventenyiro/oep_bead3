#include "simulation.hpp"
#include "colony.hpp"

using namespace std;

#define NORMAL_MODE

#ifdef NORMAL_MODE

int main() {
    //Simulation test = Simulation("input4.txt");
    //test.run(true);
    
    

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("no colony", "input0.txt") {
    Simulation s = Simulation("input0.txt");
    CHECK(s.getPreys().empty());
    CHECK(s.getPredators().empty());
}

TEST_CASE("no predators", "input1.txt") {
    Simulation s = Simulation("input1.txt");
    CHECK_FALSE(s.getPreys().empty());
    CHECK(s.getPredators().empty());
}

TEST_CASE("no preys", "input2.txt") {
    Simulation s = Simulation("input2.txt");
    CHECK(s.getPreys().empty());
    CHECK_FALSE(s.getPredators().empty());
}

TEST_CASE("preys and predators", "input3.txt") {
    Simulation s = Simulation("input3.txt");
    CHECK_FALSE(s.getPreys().empty());
    CHECK_FALSE(s.getPredators().empty());
}

TEST_CASE("predators win", "input3.txt") {
    Simulation s = Simulation("input3.txt");
    s.run(false);
    CHECK(s.getPreys().empty());
    CHECK_FALSE(s.getPredators().empty());
}



#endif