#include "Population.h"
#include "Task.h"
#include <chrono>
#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

int main() {
    srand(111);  // Set a seed for random(). | Set random(time(0)) for randomness
    Task t;

    // Default Data generation parameters:
    int N_ITEMS = 60;  // 1000 < N < 2000       //if N_items < 80; Individual lenght fit on console witdh. (More comfortable view.)
    int MAX_W = 200;   // 10000 < W < 20000
    int MAX_S = 200;   // 10000 < S < 20000
    
    // Default GA parameters:
    int POP_SIZE = 50;              // Size of the population that algorithm will use.
    int TOUR_SIZE = 20;              // nºindividuals of the population thats play one tournament. It used for Tournament Selection method. TOUR_SIZE must be <= POP_SIZE 
    float CROSSOVER_RATE = 0.7;      // Between [0, 1]; Probability of make a crossover takes effect.
    float MUTATION_RATE = 4/50;       // n_items * MUTATION_RATE = nº of genes that mutes from one individual.
    
    
    //// MENU ////
    bool stop = false;
    int selection = -1;
    std::string filename = "dataset/new_dataset.csv";
    while(!stop) {
        system("clear");
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "        🧪🧬  𝔾𝕖𝕟𝕖𝕥𝕚𝕔 𝔸𝕝𝕘𝕠𝕣𝕚𝕥𝕙𝕞  𝚏𝚘𝚛 𝙺𝚗𝚊𝚙𝚜𝚊𝚌𝚔 𝙿𝚛𝚘𝚋𝚕𝚎𝚖 "  << std::endl;
        std::cout << std::endl;
        std::cout << " --- PARAMETERS -----------------------------------------" << std::endl;
        std::cout << "    N.º items: " << N_ITEMS << "    " << "Max. Weight: " << MAX_W << "    " << "Max. Size: " << MAX_S << "\t" << std::endl;
        std::cout << "    Data loaded: ";
        t.getData() == NULL ? (std::cout  << "❌\n") : ((std::cout <<"✅ -> "<< filename << " \n"));
        std::cout << "    Population size: " << POP_SIZE << "        Tournament size: " << TOUR_SIZE << std::endl;
        std::cout << "    Crossover rate: " << CROSSOVER_RATE << "         Mutation rate: " << MUTATION_RATE << std::endl;
        // std::cout << std::endl;
        std::cout << " --------------------------------------------------------" << std::endl;
        std::cout << std::endl;
        std::cout << "  1. 💾\t| Generate new dataset" << std::endl;
        std::cout << "  2. 💿\t| Read dataset" << std::endl;
        std::cout << "  3. 👀\t| Show dataset in use" << std::endl;
        std::cout << "  4. ⚙️\t| Set Algorithm parameters" << std::endl;
        std::cout << "  5. 🧬\t| Use 'Genetic Algorithm'" << std::endl;
        std::cout << "  0. 🡄\t| Exit" << std::endl;
        
        std::cout << "\n\n > ";
        std::cin >> selection;
        switch(selection) {
            case 0:
                stop = true;
                break; 
            case 1: 
                system("clear"); // Set task parameters;
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "  === New Data Generation ===" << std::endl;
                std::cout << std::endl;
                std::cout << " --- PARAMETERS -----------------------------------------" << std::endl;
                std::cout << "    N.º items: " << N_ITEMS << "    " << "Max. Weight: " << MAX_W << "    " << "Max. Size: " << MAX_S << "\t" << std::endl;
                std::cout << "\n Do you want to change the parameters? [y, n] ";
                char c;
                cin >> c;
                std::cout << std::endl;
                if(c=='y') {
                    std::cout << " [ Setting new parameters for Task ]" << std::endl;
                    std::cout << " New N.º of items: ";
                    std::cin >> N_ITEMS;
                    std::cout << " New Max. Weight of knapsack: ";
                    std::cin >> MAX_W;
                    std::cout << " New Max. Weight of knapsack: ";
                    std::cin >> MAX_S;                    
                }
                std::cout << std::endl;
                std::cout << " Name for new dataset (write 0 for default): ";
                std::cin >> filename;
                if(filename == "0")
                    filename = "new_dataset.csv";   // Default name;
                std::cout << "\n Generating dataset..." << std::endl;
                t.generate(N_ITEMS, MAX_W, MAX_S, "datasets/"+filename);
                t.read("datasets/"+filename);
                std::cout <<"'" << filename << "' dataset was generated using currents parameters and loaded.\n  ⏎ To continue" << std::endl;
                std::cin.ignore().get(); //Pause Command for Linux Terminal
                break;
            case 2: // Read dataset
                system("clear");
                std::cout << "Name of the dataset file (write 0 for default): ";
                std::cin >> filename;
                if(filename == "0")
                    filename = "new_dataset.csv";   // Default name;
                std::cout << "Reading dataset..." << std::endl;
                t.read("datasets/"+filename);
                std::cout <<"'" << filename << "' dataset was readed and loaded." << std::endl;
                std::cout <<"  ⏎ To continue" << std::endl;
                std::cin.ignore().get(); //Pause Command for Linux Terminal
                break;
            case 3: // Show data
                system("clear");
                std::cout << "\n ==== Showing Data ====" << std::endl;
                t.showData();
                std::cout <<"  ⏎ To continue" << std::endl;
                std::cin.ignore().get(); //Pause Command for Linux Terminal
                break; 
            case 4: // Set Algorithm parameters
                system("clear");
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "        🧪🧬  𝔾𝕖𝕟𝕖𝕥𝕚𝕔 𝔸𝕝𝕘𝕠𝕣𝕚𝕥𝕙𝕞  𝚏𝚘𝚛 𝙺𝚗𝚊𝚙𝚜𝚊𝚌𝚔 𝙿𝚛𝚘𝚋𝚕𝚎𝚖 "  << std::endl;
                std::cout << std::endl;
                std::cout << " --- PARAMETERS -----------------------------------------" << std::endl;
                std::cout << "    N.º items: " << N_ITEMS << "    " << "Max. Weight: " << MAX_W << "    " << "Max. Size: " << MAX_S << "\t" << std::endl;
                std::cout << "    Data loaded: ";
                t.getData() == NULL ? (std::cout  << "❌\n") : ((std::cout <<"✅ -> "<< filename << " \n"));
                std::cout << "    Population size: " << POP_SIZE << "        Tournament size: " << TOUR_SIZE << std::endl;
                std::cout << "    Crossover rate: " << CROSSOVER_RATE << "         Mutation rate: " << MUTATION_RATE << std::endl;
                // std::cout << std::endl;
                std::cout << " --------------------------------------------------------" << std::endl;
                std::cout << "\n [ Setting new parameters for Genetic Algorithm ]" << std::endl;
                std::cout << "\n New Population size: ";
                std::cin >> POP_SIZE;
                std::cout << " New Tournament size: ";
                std::cin >> TOUR_SIZE;
                std::cout << " New Crossover rate [0.0, 1.0]: ";
                std::cin >> CROSSOVER_RATE;
                std::cout << " New Mutation rate [0.0, 1.0]: ";
                std::cin >> MUTATION_RATE;
                std::cout <<"  ⏎ To continue" << std::endl;
                std::cin.ignore().get(); //Pause Command for Linux Terminal
                break;
            case 5:
                system("clear");
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

                std::cout <<"  ⏎ To continue" << std::endl;
                std::cin.ignore().get(); //Pause Command for Linux Terminal
                break;
        }
        
    /* FOR TESTING */

    // // Data generation parameters:
    // int N_ITEMS = 60;  // 1000 < N < 2000
    // int MAX_W = 10000;   // 10000 < W < 20000
    // int MAX_S = 10000;   // 10000 < S < 20000
    // t.generate(N_ITEMS, MAX_W, MAX_S, "data.csv");
    // 
    // // Reading data
    // t.read("data.csv");
    // std::cout << "\n ==== Data ====" << std::endl;
    // t.showData();

    // // GA parameters:
    // int POP_SIZE = 100;              // Size of the population that algorithm will use.
    // int TOUR_SIZE = 30;              // nºindividuals of the population thats play one tournament. It used for Tournament Selection method. TOUR_SIZE must be <= POP_SIZE 
    // float CROSSOVER_RATE = 0.1;      // Between [0, 1]; Probability of make a crossover takes effect.
    // float MUTATION_RATE = 10/40;       // n_items * MUTATION_RATE = nº of genes that mutes from one individual.
    // 
    // // Genetic Algorithm
    // std::cout << "\n\n\n ==== Genetic Algorithm ====" << std::endl;
    // auto t1_g = std::chrono::high_resolution_clock::now();
    // t.geneticAlgorithm(POP_SIZE, TOUR_SIZE, CROSSOVER_RATE, MUTATION_RATE);
    // auto t2_g = std::chrono::high_resolution_clock::now();
    // auto duration_g = std::chrono::duration_cast<std::chrono::microseconds>( t2_g - t1_g ).count();

    // // Quality Estimation Algorithm
    // auto t1_q = std::chrono::high_resolution_clock::now();
    // std::cout << "\n\n\n ==== Quality estimation Algorithm ====" << std::endl;
    // t.qualityEstimationAlgorithm();
    // auto t2_q = std::chrono::high_resolution_clock::now();
    // auto duration_q = std::chrono::duration_cast<std::chrono::microseconds>( t2_q - t1_q ).count();

    // std::cout << std::endl << " ==== Times: ====" << std::endl;
    // std::cout << "  Genetic Algorithm runtime:\t\t" << duration_g << " μs"  << std::endl;
    // std::cout << "  Quality Estimation Algorithm runtime:\t"  << duration_q << " μs" << std::endl;
    }
}
