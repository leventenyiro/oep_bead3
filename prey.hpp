// lemming, nyúl, ürge
// lemming, rabbit, groundSquirrel
#pragma once

#include "colony.hpp"
#include "predator.hpp"

class Prey : public Colony {
protected:
    Prey(const string name, const char species, int population) : Colony(name, species, population) {};
    /*virtual void attacked(Predator p) {
        if ()
    }*/
};

class Lemming : public Prey {
private:
    const int attackedValue = 4;
public:
    Lemming(const string name, const char species, int population) : Prey(name, species, population) {};
    /*void attacked() override {

    }*/
};

class Rabbit : public Prey {

};

class GroundSquirrel : public Prey {

};