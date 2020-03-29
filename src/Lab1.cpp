#include "Population.h"
#include "Task.h"

using namespace std;


int main() {
    Task t;
    // t.generate(1000, 10000, 10000, "data.csv");   // 1000 < N < 2000 | 10000 < W < 20000 | 10000 < S < 20000
    t.read("data.csv");
    t.showData();
    // t.geneticAlgorithm();

    // Population p;
    // p.init_population(N, 5);
    // p.show_population();
    // vector<Individual>& pop = p.getPopulation();
    // std::cout << pop.size() <<" "<< p.getSize() <<std::endl;
    // pop.erase(pop.begin());
    // std::cout << pop.size() <<" "<< p.getSize() <<std::endl;
    // p.show_population();
    // 
    // p.mutate(pop.at(0), 0.1);
    // cout << endl;
    // p.show_population();
    // cout << endl;
    // pop.push_back(p.crossover(pop.at(0), pop.at(1), 0.7));
    // p.show_population();
}
