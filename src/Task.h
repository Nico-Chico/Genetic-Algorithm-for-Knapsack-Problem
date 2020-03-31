#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include "Population.h"

typedef bool* Individual;   // A booleans array. Position i indicates
                            // if object 'i' of the dataset is present.

struct Item {           // Each item of our dataset is characterised by
        int w, s, c;    // 3 attributes:
    };                  // 'w', 's', and 'c' means "weight", "size" and "prize" respectively.

/**
 *  This class is responsible of save and manage 
 *  the data and parameters from our currently problem.  
*/
class Task {
    int N;      // N = nº of objects in our dataset;
    int W;      // W = Max. weight that our knapsack can carry.
    int S;      // S = Max. volume that fits in the knapsack.
    Item* data; // Our dataset is an array of "Items" identified by their index.

public:
    Task();
    int getN() const { return N; }
    int getW() const { return W; }
    int getS() const { return S; }
    Item* getData() const { return data;}
    
    // Show the currently dataset.
    void showData();
    
    // Generate random data and export export to "output_file.csv";
    void generate(int n, int w, int s, std::string output_file);
    
    // Read dataset from an ".csv" file and load it as currently for use;
    void read(std::string fileName);
    
    // Use Genetic Algorihm to solve the task.
    Individual geneticAlgorithm(int POP_SIZE, int TOUR_SIZE, float CROSSOVER_RATE, float MUTATION_RATE);
    
    // Use a qualityEstimationAlgorithm to solve the task.
    Individual qualityEstimationAlgorithm();
};

#endif


