#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include "colony.hpp"

using namespace std;

class Simulation {
private:
    vector<Prey*> preys;
    vector<Predator*> predators;
    int sumPreys();
    void printRound(unsigned round);
public:
    Simulation(string filename);
    void run(bool printToConsole);
    ~Simulation();
};

Simulation::Simulation(string filename) {
    ifstream file(filename);
    if (file.fail()) {
        cout << "Wrong file name!" << endl;
        exit(1);
    }

    unsigned int countPrey, countPredator;
    file >> countPrey >> countPredator;
    for (unsigned int i = 0; i < countPrey; i++) {
        string name;
        char species;
        int population;
        file >> name >> species >> population;
        Prey* p;
        switch (species) {
            case 'l':
                p = new Lemming(name, species, population);
                break;
            case 'n':
                p = new Rabbit(name, species, population);
                break;
            case 'u':
                p = new GroundSquirrel(name, species, population);
                break;
        }
        preys.push_back(p);
    }
    for (unsigned int i = 0; i < countPredator; i++) {
        string name;
        char species;
        int population;
        file >> name >> species >> population;
        Predator* p;
        switch (species) {
            case 'h':
                p = new SnowOwl(name, species, population);
                break;
            case 's':
                p = new ArcticFox(name, species, population);
                break;
            case 'f':
                p = new Wolf(name, species, population);
                break;
        }
        predators.push_back(p);
    }
}

int Simulation::sumPreys() {
    int sum = 0;
    for (Prey *p : preys) {
        sum += p->getPopulation();
    }
    return sum;
}

void Simulation::run(bool printToConsole) {
    if (preys.empty())
        cout << "There are not any prey colonies.";
    else if (predators.empty())
        cout << "There are not any predator colonies.";
    else {
        srand((unsigned int)time(NULL));
        int countStartPreys = sumPreys();
        unsigned int round = 0;
        while (!preys.empty() && sumPreys() < countStartPreys * 4) {
            round++;
            int randomPrey;
            for (unsigned int i = 0; i < predators.size() && !preys.empty(); i++) {
                randomPrey = rand() % preys.size();
                preys[randomPrey]->attacked(*predators[i]);
                if (preys[randomPrey]->getPopulation() < 0) {
                    predators[i]->leave();
                    preys.erase(preys.begin() + randomPrey);
                    if (predators[i]->getPopulation() <= 0)
                        predators.erase(predators.begin() + i);
                }
            }

            for (Prey *p : preys) {
                p->reproduction(round);
                p->leave();
            }
            for (Predator *p : predators) {
                p->reproduction(round);
            }

            if (printToConsole)
                printRound(round);
        }

        if (predators.empty())
            cout << "Predators are dead." << endl;
        if (preys.empty())
            cout << "Preys are dead." << endl;
    }
}

void Simulation::printRound(unsigned int round) {
    cout << round << ". ROUND" << endl;
    for (Prey* p : preys) {
        cout << "\t" << p->getName() << " " << p->getSpecies() << " " << p->getPopulation() << endl;
    }
    for (Predator* p : predators) {
        cout << "\t" << p->getName() << " " << p->getSpecies() << " " << p->getPopulation() << endl;
    }
}

Simulation::~Simulation() {
    for (Prey* p : preys) {
        delete p;
    }
    for (Predator* p : predators) {
        delete p;
    }
}