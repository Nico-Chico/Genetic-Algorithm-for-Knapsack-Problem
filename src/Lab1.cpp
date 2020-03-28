#include "Population.h"
#include "Task.h"

using namespace std;

int main() {
    int N = 10;
    int W = 100; 
    int S = 100;

    Task t;
    t.generate(N,W,S,"data.csv");   // 1000 < n < 2000 | 10000 < w < 20000 | 10000 < s < 20000
    t.read("data.csv");
    t.show_data();
 
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
