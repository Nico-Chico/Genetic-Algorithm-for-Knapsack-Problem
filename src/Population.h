#ifndef POPULATION_H
#define POPULATION_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include "Task.h"

class Task;                 // Predeclaration of the class Task required.

typedef bool* Individual;   // A booleans array. Position i indicates
                            // if object 'i' of the dataset is present.

/**
 *  This class is la encargada de
 *
 *
 *   
 */
class Population {
    std::vector<Individual> pop;    // Our Population:  pop.size = nº of individuals
    std::vector<int> evs;           // Evaluation of each individual.
    int n_items;                    // Nº of different items in our dataset.
    
public:
    Population(int n_items);
    Population(int n_items, int size);
    const std::vector<Individual>& getPopulation() const {return pop;}    ///Add const?
    const std::vector<int>& getEvaluations() const {return evs;}          ///Add const?
    int getNitems() const {return n_items;}
    int getSize() const {return pop.size();}
    void addIndividual(Individual ind);
    const Population& initPopulation(int n_items, int size);
    void showIndividual(int n);
    void showPopulation();
    
    // Evaluate all individuals of the population according N, W and S given in Task t
    void evaluate(Task* t);
    Individual tournament(int size);    // Selection method;
    Individual crossover(const Individual& parent1, const Individual& parent2, float crossover_rate);
    void mutate(Individual individual, float mutation_rate);
};

#endif
