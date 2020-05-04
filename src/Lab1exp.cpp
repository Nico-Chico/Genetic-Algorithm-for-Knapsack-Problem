#include "Population.h"
#include "Task.h"
#include <chrono>
#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

int main(int argc, char** argv) {

    srand(time(0));  // Set a seed for random(). | Set random(time(0)) for randomness
    Task t;

    // Default Data generation parameters:
    int N_ITEMS = 60;  // 1000 < N < 2000       //if N_items < 80; Individual lenght fit on console witdh. (More comfortable view.)
    int MAX_W = 600;   // 10000 < W < 20000
    int MAX_S = 600;   // 10000 < S < 20000
    
    // Default GA parameters:
    int POP_SIZE = 50;              // Size of the population that algorithm will use.
    int TOUR_SIZE = 20;              // nºindividuals of the population thats play one tournament. It used for Tournament Selection method. TOUR_SIZE must be <= POP_SIZE 
    float CROSSOVER_RATE = 0.7;      // Between [0, 1]; Probability of make a crossover takes effect.
    float MUTATION_RATE = 4/50;       // n_items * MUTATION_RATE = nº of genes that mutes from one individual.
       
    if(argc == 2 ) {							// EXPERIMENT MODE read parameters from a input file
        std::cout << "Exp mode. Loading experiment: '" << argv[1]  <<"'"<< endl;
        
        string expID= argv[1];
        if(!(ifstream(expID))) {
            std::cout << "Experiment does not exist" << endl;
        } else {
            // Reading parameters from input
            std::ifstream file(expID);
            std::string line = "";
            
            getline(file, line);
            N_ITEMS = stoi(line);
            
            getline(file, line);
            MAX_W = stoi(line);
            
            getline(file, line);
            MAX_S = stoi(line);
            
            getline(file, line);
            POP_SIZE = stoi(line);
            
            getline(file, line);
            TOUR_SIZE = stoi(line);
            
            getline(file, line);
            CROSSOVER_RATE = stof(line);
            
            getline(file, line);
            MUTATION_RATE = stof(line);
            
            getline(file, line);
            string filename = "datasets"+line;
            if(!ifstream(filename)) // If dataset file don't exist, I generate it.
                t.generate(N_ITEMS, MAX_W, MAX_S, filename);                
            // Reading data from datafile specified from input 8º line
            t.read(filename);
            
            //  Show loaded parameters   
            std::cout << std::endl;            
            std::cout << "             Genetic Algorithm for Knapsack Problem"  << std::endl;
            std::cout << std::endl;
            std::cout << " --- PARAMETERS -----------------------------------------" << std::endl;
            std::cout << "    N.º items: " << N_ITEMS << "    " << "Max. Weight: " << MAX_W << "    " << "Max. Size: " << MAX_S << "\t" << std::endl;
            std::cout << "    Data loaded: ";
            t.getData() == NULL ? (std::cout  << "x\n") : ((std::cout <<"ok -> "<< filename << " \n"));
            std::cout << "    Population size: " << POP_SIZE << "        Tournament size: " << TOUR_SIZE << std::endl;
            std::cout << "    Crossover rate: " << CROSSOVER_RATE << "         Mutation rate: " << MUTATION_RATE << std::endl;
            // std::cout << std::endl;
            std::cout << " --------------------------------------------------------" << std::endl;
        
            std::cout << "\n ==== Data ====" << std::endl;
            t.showData();
            
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
    } else {
	        std::cout << "Please denote input experiment as argument." << endl;
    }
}
