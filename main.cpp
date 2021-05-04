#include "simulation.hpp"
#include "colony.hpp"

using namespace std;

//#define NORMAL_MODE
#ifdef NORMAL_MODE

int main() {
    Simulation test = Simulation("input4.txt");
    test.run(true);
    /*Rabbit r = Rabbit("picik", 'n', 100);
    Wolf w = Wolf("ehesek", 'f', 5);
    r.attacked(w);
    cout << r.getName();*/
    
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

TEST_CASE("getData", "rabbit colony") {
    Lemming l = Lemming("kicsik", 'l', 86);
    CHECK(l.getName() == "kicsik");
    CHECK(l.getSpecies() == 'l');
    CHECK(l.getPopulation() == 86);
}

TEST_CASE("reproduction", "every colony") {
    Lemming l = Lemming("kicsik", 'l', 86);
    l.reproduction(1);
    CHECK(l.getPopulation() == 86);
    l.reproduction(2);
    CHECK(l.getPopulation() == 2 * 86);

    Rabbit r = Rabbit("szaporak", 'n', 26);
    r.reproduction(1);
    CHECK(r.getPopulation() == 26);
    r.reproduction(2);
    CHECK(r.getPopulation() == 26 * 1.5);

    GroundSquirrel g = GroundSquirrel("szorgosak", 'u', 12);
    g.reproduction(1);
    CHECK(g.getPopulation() == 12);
    g.reproduction(4);
    CHECK(g.getPopulation() == 12 * 2);

    SnowOwl s = SnowOwl("tollasak", 'h', 6);
    s.reproduction(1);
    CHECK(s.getPopulation() == 6);
    s.reproduction(8);
    CHECK(s.getPopulation() == 6 + 6 / 4);

    ArcticFox a = ArcticFox("gyorsak", 'a', 8);
    a.reproduction(1);
    CHECK(a.getPopulation() == 8);
    a.reproduction(8);
    CHECK(a.getPopulation() == 8 + 8 / 4 * 3);

    Wolf w = Wolf("ehesek", 'f', 12);
    w.reproduction(1);
    CHECK(w.getPopulation() == 12);
    w.reproduction(8);
    CHECK(w.getPopulation() == 12 + 12 / 4 * 2);
}

TEST_CASE("leave", "1 predator, 3 preys") {
    SnowOwl s = SnowOwl("tollasak", 'h', 6);
    s.leave();
    CHECK(s.getPopulation() == 4);

    Lemming l = Lemming("kicsik", 'l', 200);
    l.leave();
    CHECK(l.getPopulation() == 200);
    l = Lemming("kicsik", 'l', 201);
    l.leave();
    CHECK(l.getPopulation() == 30);

    Rabbit r = Rabbit("szaporak", 'n', 100);
    r.leave();
    CHECK(r.getPopulation() == 100);
    r = Rabbit("szaporak", 'n', 101);
    r.leave();
    CHECK(r.getPopulation() == 20);

    GroundSquirrel g = GroundSquirrel("szorgosak", 'u', 200);
    g.leave();
    CHECK(g.getPopulation() == 200);
    g = GroundSquirrel("szorgosak", 'u', 201);
    g.leave();
    CHECK(g.getPopulation() == 40);
}

TEST_CASE("prey attacked", "by a predator") {
    SnowOwl s = SnowOwl("tollasak", 'h', 6);
    
    Lemming l = Lemming("kicsik", 'l', 200);
    l.attacked(s);
    CHECK(l.getPopulation() == 200 - 4 * 6);
    
    Rabbit r = Rabbit("szaporak", 'n', 100);
    r.attacked(s);
    CHECK(r.getPopulation() == 100 - 2 * 6);

    GroundSquirrel g = GroundSquirrel("szorgosak", 'u', 200);
    g.attacked(s);
    CHECK(g.getPopulation() == 200 - 2 * 6);
}

#endif