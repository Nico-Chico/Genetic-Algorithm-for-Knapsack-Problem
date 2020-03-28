#ifndef POPULATION_H
#define POPULATION_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include "Task.h"

class Task; //Predeclaration of the class.

typedef bool* Individual;   // A bools array. Position i indicates if object 'i' of the dataset is present.

class Population {
    std::vector<Individual> pop;    // Our Population:    pop.size(nº of individuals)
    std::vector<int> evs;           // Evaluations.
    int n_items;               // total number of different objects in our data. 
    
public:
    Population();
    Population(int n_items, int size);
    std::vector<Individual>& getPopulation() {return pop;}        ///Add const?
    int getSize() const {return pop.size();}
    int getN_items() const {return n_items;}
    const Population& init_population(int n_items, int size);
    void show_population();
    void show_individual(int n);
    void evaluate(Task* t);
    Individual tournament(int size);
    Individual crossover(const Individual& parent1, const Individual& parent2, float crossover_rate);
    void mutate(Individual individual, float mutation_rate);
};

#endif
