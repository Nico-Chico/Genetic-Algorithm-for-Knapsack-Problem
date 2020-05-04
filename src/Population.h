#ifndef POPULATION_H
#define POPULATION_H

#include <iostream>
#include <vector>
#include "Task.h"

class Task;                 // Predeclaration of the class Task required.

typedef bool* Individual;   // A booleans array. Position i indicates
                            // if object 'i' of the dataset is present.

/**
 * This class is responsible of store individuals population
 * and  contains the methods that deal with them. Like Genetic Operators.
 */
class Population {
    std::vector<Individual> pop;    // Our Population:  pop.size = nº of individuals
    std::vector<int> evs;           // Evaluation of each individual.
    int n_items;                    // Nº of different items in our dataset.
    
public:
    Population(int n_items);
    Population(int n_items, int size);
    ~Population();
    
    const std::vector<Individual>& getPopulation() const {return pop;}    ///Add const?
    const std::vector<int>& getEvaluations() const {return evs;}          ///Add const?
    int getNitems() const {return n_items;}
    int getSize() const {return pop.size();}
    
    // Add Individial 'ind' to the population
    void addIndividual(Individual ind);
    
    // Initialice the population randomly
    void initPopulation(int n_items, int size); // Nº of items, Size of population.
    
    // Show Individual on the position 'n';
    void showIndividual(int n);
    
    // Show Individual passed;
    void showIndividual(const Individual n);
    
    // Show current population;
    void showPopulation();
    
    // Evaluate all individuals of the population according N, W and S given in Task t
    void evaluate(Task* t);
    
    // Select a Individual from populaton using Tournament Selection method.
    Individual tournament(int size);    // Selection method;
    
    // Use crossover to create a Individual Offspring of two Parents passed as parameters.
    Individual crossover(const Individual parent1, const Individual parent2, float crossover_rate);
   
    // Mutate genes of the individual pass as parameter with mutation_rate given.
    void mutate(Individual individual, float mutation_rate);
    
    // Return index of best solution from populaton.
 	int getBestSol();
 	
 	// Return Individual evaluation. (Fitness)
 	int getEv(int i) {return evs[i];}
 	
 	// Copy content from other populaton.
 	void copy(const Population &other);
 	
 	// Clear the population
 	void clear();
 	
 	//
};

#endif
