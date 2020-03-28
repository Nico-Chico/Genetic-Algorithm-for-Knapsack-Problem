#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <string>
#include "Population.h"

class Population;

typedef bool* Individual;   // A bools array. Position i indicates if object 'i' of the dataset is present.

struct Item {
        int w, s, c;
    };

class Task {
    int N, W, S;
    Item* data;
    Population* P;

public:
    Task() { N = 0;}
    int getN() const { return N; }
    int getW() const { return W; }
    int getS() const { return S; }
    Item* getData() const { return data;}
    void show_data();
    void generate(int n, int w, int s, std::string output_file);
    void read(std::string fileName);
    Individual geneticAlgorithm();
};

#endif


