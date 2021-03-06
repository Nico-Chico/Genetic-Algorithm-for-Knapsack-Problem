#include "Population.h"

Population::Population(int n_items) {
    this->n_items = n_items;
}

Population::Population(int n_items, int size) {
    initPopulation(n_items, size);
}

void Population::addIndividual(Individual ind) {
	Individual ind_copy = new bool[n_items];
	for(int i=0; i<n_items; i++) {		//Copying individual.
		ind_copy[i] = ind[i];
	}
    pop.push_back(ind_copy);
    evs.push_back(-1);
}

void Population::initPopulation(int n_items, int size) {
    if(pop.size() > 0) { // If there's an existing population, I clear it.
    	clear();
    }         
    this->n_items=n_items;
    for(int i=0; i<size; i++) {
        Individual p = new bool[n_items];
        for(int i=0; i<n_items; i++) {
            if(rand() % 10 < 2)     // probability to set '1' = 0.2
                p[i] = true;        // "Lab1.pdf" document suggest 0.5 but its produce a 'initial population' individuals overloaded 
            else p[i] = false;      // of weight and size and therefore there is too many 'Individuals' with fitness 0;
        }
        pop.push_back(p);
        evs.push_back(-1);
    }
}

void Population::showIndividual(int n) {
    Individual p = pop[n];
    for(int i=0; i<n_items; i++)
        std::cout << p[i];
    std::cout << "\t" << evs[n] << std::endl;
}

void Population::showIndividual(const Individual ind) {
    for(int i=0; i<n_items; i++)
        std::cout << ind[i];
    std::cout << std::endl;
}

void Population::showPopulation() {
    for(unsigned int i=0; i<pop.size(); i++){    
        showIndividual(i);
    }
}

void Population::evaluate(Task* t) {
    Item* data = t->getData();
    int w_sum,s_sum,c_sum;
    for(unsigned int i=0; i<pop.size(); i++) {
        w_sum = 0; s_sum = 0; c_sum = 0;
        int j=0;
        bool valid = true;
        Individual indiv = pop[i];
        while(j<n_items && valid){
            if(indiv[j] == true){
                w_sum += data[j].w;
                s_sum += data[j].s;
                c_sum += data[j].c;
            }
            if(w_sum > t->getW() || s_sum > t->getS()){
                evs[i] = 0;
                valid = false;
            }
            j++;
        }
        if(valid)
            evs[i] = c_sum; 
    }
}

Individual Population::tournament(int tour_size) {
    int rnd;
    std::vector<Individual> tour_parts;
    std::vector<int> tour_evs;
    Individual best_ind = NULL;
    int best_fit = 0;

    for(int i=0; i<tour_size; i++){     // Select k individuals to play the tournament.
        rnd = random() % pop.size();
        tour_parts.push_back(pop.at(rnd));
        tour_evs.push_back(evs.at(rnd));
        if(tour_evs[i] > best_fit) {
            best_fit = tour_evs[i];
            best_ind = tour_parts[i];
        }
        
    }
    if(best_ind == NULL)
   		best_ind = tour_parts.at(0);  // If there is no any better Individual, "tournament" will return the first participant.
    // std::cout << "- Tournament winner fitness: " << best_fit << std::endl;  // For testing        // For testing only
    return best_ind;
}


Individual Population::crossover(const Individual parent1, const Individual parent2, float crossover_rate) {
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);    // Random float [0.0, 1.0]
    if(r < crossover_rate){
        Individual child = new bool[n_items];
        int c = rand() % n_items;
        for(int i=0; i<c; i++)
            child[i] = parent1[i];
        for(int i=c; i<n_items; i++)
            child[i] = parent2[i];
        return child;
    } else return parent1;
}

void Population::mutate(Individual individual, float mutation_rate) {
    // int muts = mutation_rate * n_items;
    // for(int i=0; i<muts; i++) {
    //     int g = rand() % n_items;
    //     // std::cout << i << " of" << muts << "mutations | gene: " << g << std::endl;
    //     if(individual[g])
    //         individual[g] = 0;
    //     else individual[g] = 1;
    // }
    float r;
    for(int i=0; i<n_items; i++) {
        r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);    // Random float [0.0, 1.0]
        if(r < mutation_rate) {
            // std::cout << "Gen Mutated" << std::endl;
           if(individual[i]) {
             individual[i] = 0;
           } else individual[i] = 1;            
        }
    }
}

int Population::getBestSol() {
    int best_indx = 0;
    for(unsigned int i=0; i<evs.size(); i++){
        if(evs[i] > evs[best_indx])
            best_indx = i;
    }    
    return best_indx;
}

void Population::copy(const Population &other) {
		this->clear();
		this->n_items = other.n_items;
		for(Individual ind : other.pop) {
			Individual new_ind = new bool[n_items];
			for(int i=0; i<n_items; i++)
				new_ind[i] = ind[i];
			pop.push_back(new_ind);
		}
		this->evs = other.evs;
}

void Population::clear() {
	for(Individual ind : pop)
		delete [] ind;
	pop.clear();		// Clear vectors
	evs.clear();
}

Population::~Population() {
	clear();
}

