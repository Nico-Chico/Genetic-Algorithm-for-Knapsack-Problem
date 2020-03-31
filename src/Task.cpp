#include "Task.h"

Task::Task() { 
    N = 0;
    W = 0;
    S = 0;
    data = NULL;
}


void Task::showData() {
    if(data == NULL) {
        std::cout << "> No data loaded. Please load data and try again." << std::endl;
    } else {
        std::cout << "N.º items: " << N << "    " << "Max. Weight: " << W << "    " << "Max. Size: " << S << "\t" << std::endl;
        std::cout << "--------------------" << std::endl;
        for(int i=0; i<N; i++)
            std::cout << data[i].w  << '\t' << data[i].s  << '\t' << data[i].c  << std::endl;
    }
}


void Task::generate(int n, int w, int s, std::string output_file) {
    std::ofstream out_file;
    out_file.open(output_file);
    out_file << n  << ", " << w  << ", " << s  << std::endl; //Write the line in the file
    int w_i, s_i, c_i;
    for(int i=0; i<n; i++) {
        w_i = (rand() % (10*w/n - 1) + 1);   // 1 <= w_i < 10*w/n
        s_i = (rand() % (10*s/n - 1) + 1);   // 1 <= s_i < 10*s/n
        c_i = (rand() % (n - 1) + 1);        // 1 <= c_i < n
        out_file << w_i  << ", " << s_i  << ", " << c_i  << std::endl; //Write the line in the file
    }
    out_file.close();
}


void Task::read(std::string fileName) {
    std::string delimeter = ",";
    std::ifstream file(fileName);
    std::vector<std::vector<std::string>> dataList;
    std::string line = "";
    // Iterate through each line and split the content using delimeter
    while (getline(file, line)) {
    std::vector<std::string> vec;
    boost::algorithm::split(vec, line, boost::is_any_of(delimeter));    //split a line by a delimiter and save it in a vector of strings 
    dataList.push_back(vec);
    }
    file.close();   // Close the Fileº
    // Load the content as "data in use".
    N = stoi(dataList[0][0]);
    W = stoi(dataList[0][1]);
    S = stoi(dataList[0][2]);
    data = new Item[N];   // New data
    for(unsigned int i=1; i<dataList.size(); i++) {
        data[i-1].w = stoi(dataList[i][0]);
        data[i-1].s = stoi(dataList[i][1]);
        data[i-1].c = stoi(dataList[i][2]);
    }
}

Individual Task::geneticAlgorithm(int POP_SIZE, int TOUR_SIZE, float CROSSOVER_RATE, float MUTATION_RATE) {
    Individual solution = NULL;
    if(data == NULL) {
        std::cout << "> No data loaded. Please load data and try again." << std::endl;
    } else {   
        int ITERATIONS_NUMBER = 10;
        Population* P = new Population(N, POP_SIZE);
        std::cout << std::endl;
        Population* newP;
        int its = 0;
        while(its < ITERATIONS_NUMBER) {
            newP = new Population(N);           // Create a new (next generation) population 
            P->evaluate(this);                      // Evaluate current population.
            std::cout << std::endl << "> "<< its << " iteration: " << std::endl;
            // std::cout << std::endl << "Population: " << std::endl;
            P-> showPopulation();
            std::cout << std::endl;
            for(int i=0; i<POP_SIZE; i++) {     // Produce a new population of offsprings of previous population.
                Individual p1 = P->tournament(TOUR_SIZE); // Selecting parents
                Individual p2 = P->tournament(TOUR_SIZE);
                Individual offspring = P->crossover(p1, p2, CROSSOVER_RATE); // Making the child combining the parents.
                P->mutate(offspring, MUTATION_RATE);
                // std::cout << std::endl << ">> Element " << i <<" of new population:" << std::endl;
                // std::cout << "  > Parents: " << std::endl;
                // P->showIndividual(p1);
                // P->showIndividual(p2);
                // std::cout << "  > New Offspring: " << std::endl;
                // P->showIndividual(offspring);
                newP->addIndividual(offspring);     // Add individial to the new population
            }
            P = newP;
            // if(solution == true)         // I will changue iterator for a condition.
            //     continue = false;
            its++;
        }
        std::cout << std::endl << "> Final population:  " << std::endl;
        P->evaluate(this);
        P->showPopulation();
        
        // solution = P->selectBest();
        // std::cout << solution << std::endl;
    }
        return solution; 
}

Individual Task::qualityEstimationAlgorithm() {
    Individual solution;
    if(data == NULL) {
        std::cout << ">>> No data loaded. Please load data and try again." << std::endl;
    } else {
        //Init solution to all 0
        solution = new bool[N];
        for(int i=0; i<N; i++) 
            solution[i] = 0; 

        std::vector<float> quality;
        // Calc qualities of each item from dataset;
        for(int i=0; i<N; i++) {
            float q = (float)data[i].c / (float)(data[i].w + data[i].s);
            quality.push_back(q);
        }

        int w_sum = 0;
        int s_sum = 0;
        int c_sum = 0;
        bool cont = true;
        while(cont) {
            float best_quality = -1;
            int best_i = 0;
            // Search the best quality item.
            for(unsigned int i=0; i<quality.size(); i++) {
                if(quality[i] > best_quality) {
                    best_quality = quality[i];
                    best_i = i;                    
                }
            }
            // If its fit add the best item to the solution. Else stop the algorithm.
            if((w_sum + data[best_i].w) <= W && (s_sum + data[best_i].s) <= S) {
                w_sum += data[best_i].w;
                s_sum += data[best_i].s;
                c_sum += data[best_i].c;
                solution[best_i] = true;
                quality[best_i] = -1;
            } else {cont = false;}
        }
        
        std::cout << "Estimated solution: " << std::endl;
        for(int i=0; i<N; i++) {
            std::cout << solution[i]; 
        }
        std::cout << std::endl;
        std::cout << "Weight: " << w_sum << std::endl;
        std::cout << "Size: " << s_sum << std::endl;
        std::cout << "Value: " << c_sum << std::endl;
    }
    return solution;
}
