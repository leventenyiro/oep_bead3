#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "colony.hpp"

using namespace std;

void create(const string& filename, vector<Prey*>& preys, vector<Predator*>& predators) {
    ifstream file(filename);
    if (file.fail()) {
        cout << "Wrong file name!" << endl;
        exit(1);
    }

    unsigned int countPrey, countPredator;
    file >> countPrey >> countPredator;
    //preys.resize(countPrey);
    //predators.resize(countPredator);
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

int sumPreys(vector<Prey*>& preys) {
    int sum = 0;
    for (Prey *p : preys) {
        sum += p->getPopulation();
    }
    return sum;
}

void printRound(unsigned int round, vector<Prey*>& preys, vector<Predator*>& predators) {
    cout << round << ". ROUND" << endl;
    for (Prey* p : preys) {
        cout << "\t" << p->getName() << " " << p->getSpecies() << " " << p->getPopulation() << endl;
    }
    for (Predator* p : predators) {
        cout << "\t" << p->getName() << " " << p->getSpecies() << " " << p->getPopulation() << endl;
    }
}

// run
void run(bool printToConsole, vector<Prey*>& preys, vector<Predator*>& predators) {
    if (preys.empty())
        cout << "There are not any prey colonies.";
    else if (predators.empty())
        cout << "There are not any predator colonies.";
    else {
        int countStartPreys = sumPreys(preys);
        unsigned int round = 1;
        while (!preys.empty() && sumPreys(preys) < countStartPreys * 4) {
            int randomPrey;
            /*for (Predator* p : predators) {
                randomPrey = rand() % preys.size();
                preys[randomPrey]->attacked(*p);
                // ha nincs annyi egyed, amennyivel fogyna a zsákmányok száma
                // akkor fogy a ragadozók száma
                if (preys[randomPrey]->getPopulation() < 0) {
                    p->leave();
                    delete preys[randomPrey];
                    preys.erase(preys.begin() + randomPrey); // töröljük a zsákmányállatot
                    if (p->getPopulation() <= 0) {
                        delete p;
                    }
                }
            }*/
            for (unsigned int i = 0; i < predators.size(); i++) {
                randomPrey = rand() % preys.size();
                preys[randomPrey]->attacked(*predators[i]);
                // ha nincs annyi egyed, amennyivel fogyna a zsákmányok száma
                // akkor fogy a ragadozók száma
                if (preys[randomPrey]->getPopulation() < 0) {
                    predators[i]->leave();
                    preys.erase(preys.begin() + randomPrey); // töröljük a zsákmányállatot
                    if (predators[i]->getPopulation() <= 0)
                        predators.erase(predators.begin() + i);
                }
            }

            // reproduction
            for (Prey *p : preys) {
                p->reproduction(round);
            }
            for (Predator *p : predators) {
                p->reproduction(round);
            }

            // print
            if (printToConsole)
                printRound(round, preys, predators);

            round++;
        }

        // end
        if (predators.empty())
            cout << "Predators are dead." << endl;
        if (preys.empty())
            cout << "Preys are dead." << endl;
    }
}

void destroy(vector<Prey*>& preys, vector<Predator*>& predators) {
    for (Prey* p : preys) {
        delete p;
    }
    for (Predator* p : predators) {
        delete p;
    }
}

int main() {
    vector<Predator*> predators;
    vector<Prey*> preys;

    create("input.txt", preys, predators);

    run(true, preys, predators);

    destroy(preys, predators);

    return 0;
}