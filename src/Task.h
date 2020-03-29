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
struct Item {
        int w, s, c;
    };

class Task {
    int N, W, S;
    Item* data;

public:
    Task();
    int getN() const { return N; }
    int getW() const { return W; }
    int getS() const { return S; }
    Item* getData() const { return data;}
    void showData();
    void generate(int n, int w, int s, std::string output_file);
    void read(std::string fileName);
    Individual geneticAlgorithm(int POP_SIZE, int TOUR_SIZE, int CROSSOVER_RATE, int MUTATION_RATE);
    Individual bruteForceAlgorithm();
};

#endif


