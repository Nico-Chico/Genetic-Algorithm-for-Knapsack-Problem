#include <iostream> 
#include <fstream>
#include <vector>
#include <string>
using namespace std; 
   
    

  
int main(int argc, char** argv) 
{ 
    // Default Data generation parameters:
    int N_ITEMS = 60;  // 1000 < N < 2000       //if N_items < 80; Individual lenght fit on console witdh. (More comfortable view.)
    int MAX_W = 200;   // 10000 < W < 20000
    int MAX_S = 200;   // 10000 < S < 20000
    

    // Default GA parameters:
    int POP_SIZE = 50;              // Size of the population that algorithm will use.
    int TOUR_SIZE = 20;              // nºindividuals of the population thats play one tournament. It used for Tournament Selection method. TOUR_SIZE must be <= POP_SIZE 
    float CROSSOVER_RATE = 0.7;      // Between [0, 1]; Probability of make a crossover takes effect.
    float MUTATION_RATE = 4/50;       // n_items * MUTATION_RATE = nº of genes that mutes from one individual.
    
    
    if(argc == 1) { //MENU MODE
        cout << "Menu Mode" << endl;
        
    } else if(argc > 1) {// exp mode
        cout << "Exp mode. Loading experiment from file" << argv[1]  << endl;
        
        std::ifstream file(argv[1]);
        std::vector<std::vector<std::string>> dataList;
        std::string line = "";
        // Iterate through each line and split the content using delimeter
       
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
    
        
        cout << "Parameters" << endl;
        cout << N_ITEMS << endl;
        cout << MAX_W << endl;
        cout << MAX_S << endl;
        cout << POP_SIZE << endl;
        cout << TOUR_SIZE << endl;
        cout << CROSSOVER_RATE << endl;
        cout << MUTATION_RATE << endl;
    } else
    
    
    // cout << "You have entered " << argc 
    //      << " arguments:" << "\n"; 
 
  ////    
    // for (int i = 0; i < argc; ++i) 
    //     cout << argv[i] << "\n"; 
  
    return 0; 
} 
