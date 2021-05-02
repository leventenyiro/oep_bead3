#pragma once

#include <string>

using namespace std;

class Colony {
protected:
    string _name;
    char _species;
    int _population;

    Colony(const string name, const char species, int population) : _name(name), _species(species), _population(population) {};
public:
    int getPopulation() const { return _population; }
    virtual void reproduction(int turn) = 0;
    virtual void leave() = 0;
};

// PREDATOR

class Predator : public Colony {
protected:
    Predator(const string name, const char species, int population) : Colony(name, species, population) {};
    void leave() override {
        _population -= _population / 4;
    }
};

class SnowOwl : public Predator {
public:
    SnowOwl(const string name, const char species, int population) : Predator(name, species, population) {};
    void reproduction(int k) override {
        if (k % 8 == 0)
            _population += _population / 4;
    }
};

class ArcticFox : public Predator {
public:
    ArcticFox(const string name, const char species, int population) : Predator(name, species, population) {};
    void reproduction(int k) override {
        if (k % 8 == 0)
            _population += (_population / 4) * 3;
    }
};

class Wolf : public Predator {
public:
    Wolf(const string name, const char species, int population) : Predator(name, species, population) {};
    void reproduction(int k) override {
        if (k % 8 == 0)
            _population += (_population / 4) * 2;
    }
};

// PREY

class Prey : public Colony {
protected:
    Prey(const string name, const char species, int population) : Colony(name, species, population) {};
    virtual int attackedValue() const = 0;
public:
    virtual void attacked(Predator& p) {
        _population -= attackedValue() * p.getPopulation();
    }
};

class Lemming : public Prey {
private:
    int attackedValue() const override { return 4; }
public:
    Lemming(const string name, const char species, int population) : Prey(name, species, population) {};
    void reproduction(int turn) override {
        if (turn % 2 == 0)
            _population *= 2;
    }
    void leave() override {
        if (_population > 200)
            _population = 30;
    }
};

class Rabbit : public Prey {
private:
    int attackedValue() const override { return 2; }
public:
    Rabbit(const string name, const char species, int population) : Prey(name, species, population) {};
    void reproduction(int turn) override {
        if (turn % 2 == 0)
            _population *= 1.5;
    }
    void leave() override {
        if (_population > 100)
            _population = 20;
    }
};

class GroundSquirrel : public Prey {
private:
    int attackedValue() const override { return 2; }
public:
    GroundSquirrel(const string name, const char species, int population) : Prey(name, species, population) {};
    void reproduction(int turn) override {
        if (turn % 4 == 0)
            _population *= 2;
    }
    void leave() override {
        if (_population > 200)
            _population = 40;
    }
};