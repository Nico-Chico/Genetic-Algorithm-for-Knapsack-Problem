#include "Population.h"
#include "Task.h"

using namespace std;


int main() {
    srand(time(0));                       // Set a seed for random().
    int POP_SIZE = 60;              // Size of the population that algorithm will use.
    int TOUR_SIZE = POP_SIZE/16;     // nºindividuals of the population thats play one tournament. It used for Tournament Selection method. TOUR_SIZE must be <= POP_SIZE 
    float CROSSOVER_RATE = 0.9;       // 
    float MUTATION_RATE = 0.4;      //
    
    Task t;
    t.generate(POP_SIZE, 1000, 1000, "data.csv");   // 1000 < N < 2000 | 10000 < W < 20000 | 10000 < S < 20000
    t.read("data.csv");
    std::cout << "\n ==== Data ====" << std::endl;
    t.showData();
    
    std::cout << "\n\n\n ==== Genetic Algorithm ====" << std::endl;
    t.geneticAlgorithm(POP_SIZE, TOUR_SIZE, CROSSOVER_RATE, MUTATION_RATE);

    std::cout << "\n\n\n ==== Brute Force Algorithm ====" << std::endl;
    t.bruteForceAlgorithm();
}
