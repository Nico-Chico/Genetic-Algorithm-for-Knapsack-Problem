#include "Population.h"
#include "Task.h"
#include <chrono>
#include <typeinfo>

#include <unistd.h>
using namespace std;

int main() {
    srand(11111);                     // Set a seed for random().
    Task t;
    
    // Data generation parameters:
    int N_ITEMS = 60;  // 1000 < N < 2000
    int MAX_W = 10000;   // 10000 < W < 20000
    int MAX_S = 10000;   // 10000 < S < 20000
    t.generate(N_ITEMS, MAX_W, MAX_S, "data.csv");
    
    // Reading data
    t.read("data.csv");
    std::cout << "\n ==== Data ====" << std::endl;
    t.showData();

    // GA parameters:
    int POP_SIZE = 100;              // Size of the population that algorithm will use.
    int TOUR_SIZE = 30;              // nºindividuals of the population thats play one tournament. It used for Tournament Selection method. TOUR_SIZE must be <= POP_SIZE 
    float CROSSOVER_RATE = 0.1;      // Between [0, 1]; Probability of make a crossover takes effect.
    float MUTATION_RATE = 10/40;       // n_items * MUTATION_RATE = nº of genes that mutes from one individual.
    
    // Genetic Algorithm
    std::cout << "\n\n\n ==== Genetic Algorithm ====" << std::endl;
    auto t1_g = std::chrono::high_resolution_clock::now();
    t.geneticAlgorithm(POP_SIZE, TOUR_SIZE, CROSSOVER_RATE, MUTATION_RATE);
    auto t2_g = std::chrono::high_resolution_clock::now();
    auto duration_g = std::chrono::duration_cast<std::chrono::microseconds>( t2_g - t1_g ).count();

    // Quality Estimation Algorithm
    auto t1_q = std::chrono::high_resolution_clock::now();
    std::cout << "\n\n\n ==== Quality estimation Algorithm ====" << std::endl;
    t.qualityEstimationAlgorithm();
    auto t2_q = std::chrono::high_resolution_clock::now();
    auto duration_q = std::chrono::duration_cast<std::chrono::microseconds>( t2_q - t1_q ).count();

    std::cout << std::endl << " ==== Times: ====" << std::endl;
    std::cout << "  Genetic Algorithm runtime:\t\t" << duration_g << " μs"  << std::endl;
    std::cout << "  Quality Estimation Algorithm runtime:\t"  << duration_q << " μs" << std::endl;

}
