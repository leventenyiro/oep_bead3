#pragma once

#include <string>

using namespace std;

class Colony {
protected:
    string _name;
    char _species;
    int _population;

    Colony(const string name, const char species, int population) : _name(name), _species(species), _population(population) {};
    ~Colony() {};
public:
    string getName() const { return _name; }
    char getSpecies() const { return _species; }
    int getPopulation() const { return _population; }
    virtual void reproduction(int round) = 0;
    virtual void leave() = 0;
};

// PREDATOR

class Predator : public Colony {
protected:
    Predator(const string name, const char species, int population) : Colony(name, species, population) {};
public:
    void leave() override {
        for (int i = 0; i < _population; i++) {
            if (i % 4 == 0)
                _population--;
        }
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
    void attacked(Predator& p) {
        _population -= attackedValue() * p.getPopulation();
    }
};

class Lemming : public Prey {
private:
    int attackedValue() const override { return 4; }
public:
    Lemming(const string name, const char species, int population) : Prey(name, species, population) {};
    void reproduction(int round) override {
        if (round % 2 == 0)
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
    void reproduction(int round) override {
        if (round % 2 == 0)
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
    void reproduction(int round) override {
        if (round % 4 == 0)
            _population *= 2;
    }
    void leave() override {
        if (_population > 200)
            _population = 40;
    }
};