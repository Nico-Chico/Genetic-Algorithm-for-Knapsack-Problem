#include "Population.h"
using namespace std;

const Population& Population::init_population(int n_items, int size) {
    if(pop.size() > 0) //If there is a existing population I clear it.
        pop.clear();
    srand(time(0));
    this->n_items=n_items;
    for(int i=0; i<size; i++)
        evs.push_back(0);
    for(int i=0; i<size; i++) {
        Individual p = new bool[n_items];
        for(int i=0; i<n_items; i++) {
            if(rand() % 2 == 0)
                p[i] = true;
            else p[i] = false;
        }
        pop.push_back(p);
    }
    return *this;
}

void Population::show_population() {
    for(unsigned int i=0; i<pop.size(); i++){    
        show_individual(i);
    }
}

void Population::show_individual(int n) {
    Individual p = pop[n];
    for(int i=0; i<n_items; i++)
        cout << p[i];
    cout << "\t" << evs[n] << endl;
}

// Evaluate all individuals of the population according N, W and S given in Task t
void Population::evaluate(Task* t) {
    Item* data = t->getData();
    int w_sum,s_sum,c_sum;
    for(unsigned int i=0; i<pop.size(); i++) {
        w_sum = 0; s_sum = 0; c_sum = 0;
        int j=0;
        bool valid = true;
        while(j<n_items && valid){
            bool* indiv = pop.at(i);
            if(indiv[i] == true){
                w_sum = w_sum + data[i].w;
                s_sum = s_sum + data[i].s;
                c_sum = c_sum + data[i].c;
            }
            if(w_sum > t->getW() || s_sum > t->getS()){
                evs[i] = 0;
                valid = false;
            }
            j++;
        }
    }
}

// 
Individual Population::tournament(int tour_size) {
    srand(time(0));
    Individual best_indiv = nullptr;
    int best_fit = 0;
    int rnd;
    for(int i = 0; i<tour_size; i++) {        //Select k of the individuals to player the tournament.
        rnd = random() % pop.size();
        if(evs.at(rnd) > best_fit) {
            best_fit = evs.at(rnd);
            best_indiv = pop.at(rnd);        
        }
    }
    return best_indiv;
}

//
Individual Population::crossover(const Individual& parent1, const Individual& parent2, float crossover_rate) {
    srand(time(0));
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);    // Random float [0.0, 1.0]
    if(r > 0.5){
        Individual child = new bool[n_items];
        int c = rand() % n_items;
        for(int i=0; i<c; i++)
            child[i] = parent1[i];
        for(int i=c; i<n_items; i++)
            child[i] = parent2[i];
        return child;
    } else return parent1;
}

// Mutate genes of the individual pass as parameter with mutation_rate given.
void Population::mutate(Individual individual, float mutation_rate) {
    int muts = mutation_rate * n_items;
    for(int i=0; i<muts; i++) {
        int g = rand() % n_items;
        if(individual[g])
            individual[g] = 0;
        else individual[g] = 1;
    }
}
