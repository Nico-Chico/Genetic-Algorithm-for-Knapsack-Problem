#include "Task.h"

Task::Task() { 
    N = 0;
    W = 0;
    S = 0;
    data = NULL;
}

void Task::showData() {
    std::cout << N << "\t" << W << "\t" << S << "\t" << std::endl;
    std::cout << "--------------------" << std::endl;
    for(int i=0; i<N; i++)
        std::cout << data[i].w  << '\t' << data[i].s  << '\t' << data[i].c  << std::endl;

    // // Checking  w_i & s_i SUMMATORY propierties. 
    // int w_sum = 0;
    // int s_sum = 0;
    // for(int i=0; i<pop.size(); i++) {
    //     w_sum = w_sum + data[i].w;
    //     s_sum = s_sum + data[i].s;
    // }
    // cout << w_sum << s_sum <<endl;
}

// Generate random data. For now dont load it as "data in use" (data atributte). For it use read();
void Task::generate(int n, int w, int s, std::string output_file) {
    srand(time(0));                              // Set rand seed.
    std::ofstream out_file;
    out_file.open(output_file);
    out_file << n  << ", " << w  << ", " << s  << std::endl; //Write the line in the file
    int w_i, s_i, c_i;
    for(int i=0; i<n; i++) {
        w_i = (rand() % (10*w/n - 1) + 1);   // w_i  |  0 < w_i < 10*w/n
        s_i = (rand() % (10*s/n - 1) + 1);   // s_i  |  0 < s_i < 10*s/n
        c_i = (rand() % (n - 1) + 1);        // c_i  |  0 < c_i < n
        out_file << w_i  << ", " << s_i  << ", " << c_i  << std::endl; //Write the line in the file
    }
    out_file.close();

    /*Another version that load the data generated as "data in use".*/
    // srand(time(0));
    // data = new int[n][3];
    // ofstream out_file;
    // out_file.open(output_file);
    // out_file << n  << ", " << w  << ", " << s  << endl; //Write the line in the file
    // for(int i=0; i<n; i++) {
    //     data[i][0] = (rand() % (10*w/n - 1) + 1);   // w_i  |  0 < w_i < 10*w/n
    //     data[i][1] = (rand() % (10*s/n - 1) + 1);   // s_i  |  0 < s_i < 10*s/n
    //     data[i][2] = (rand() % (n - 1) + 1);        // c_i  |  0 < c_i < n
    //     out_file << data[i][0]  << ", " << data[i][1]  << ", " << data[i][2]  << endl; //Write the line in the file
    // }
    // out_file.close();
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
    file.close();// Close the Fileº
    // Save the content as "data in use".
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

Individual Task::geneticAlgorithm() {
    Individual solution = NULL;
    if(data == NULL) {
        std::cout << "No data loaded. Please load data and try again." << std::endl;
    } else {
        int POP_SIZE = 20;
        int TOUR_SIZE = 20;
        float CROSSOVER_RATE = 0.5;
        float MUTATION_RATE = 0.5;
        Population P(N, POP_SIZE);
        Population newP(N);
        // bool cont = true;
        int iterations = 0;
        // while(iterations < 10) {
        //     newP = new Population(N);           // Create a new population
        //     P.evaluate();                       // Evaluate population.
        //     for(int i=0; i<POP_SIZE; i++) {     // Produce a new population of childs of previous population.
        //         Individual p1 = P.tournament(TOUR_SIZE);        // Selecting parents
        //         Individual p2 = P.tournament(TOUR_SIZE);
        //         Individal child = P.crossover(p1, p2, CROSSOVER_RATE); // Making the child combining the parents.
        //         P.mutate(child, MUTATION_RATE);
        //         newP.add_individual(child);     // Add individial to the new population
        //     }
        //     P = newP;
        //     // if(solution == true)
        //     //     continue = false;
        // }
        std::cout << solution << std::endl;
    }
        return solution;
}
