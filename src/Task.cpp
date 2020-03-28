#include "Task.h"

using namespace std;

void Task::show_data() {
    for(int i=0; i<N; i++)
        cout << data[i].w  << '\t' << data[i].s  << '\t' << data[i].c  << endl;

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
void Task::generate(int n, int w, int s, string output_file) {
    srand(time(0));                              // Set rand seed.
    ofstream out_file;
    out_file.open(output_file);
    out_file << n  << ", " << w  << ", " << s  << endl; //Write the line in the file
    int w_i, s_i, c_i;
    for(int i=0; i<n; i++) {
        w_i = (rand() % (10*w/n - 1) + 1);   // w_i  |  0 < w_i < 10*w/n
        s_i = (rand() % (10*s/n - 1) + 1);   // s_i  |  0 < s_i < 10*s/n
        c_i = (rand() % (n - 1) + 1);        // c_i  |  0 < c_i < n
        out_file << w_i  << ", " << s_i  << ", " << c_i  << endl; //Write the line in the file
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

void Task::read(string fileName) {
    string delimeter = ",";
    ifstream file(fileName);
    vector<vector<string>> dataList;
    string line = "";
    // Iterate through each line and split the content using delimeter
    while (getline(file, line)) {
    vector<string> vec;
    boost::algorithm::split(vec, line, boost::is_any_of(delimeter));    //split a line by a delimiter and save it in a vector of strings 
    dataList.push_back(vec);
    }
    file.close();// Close the Fileº
    // Save the content as "data in use".
    N = stoi(dataList[0][0]);
    data = new Item[N];   // New data
    for(unsigned int i=1; i<dataList.size(); i++) {
        data[i-1].w = stoi(dataList[i][0]);
        data[i-1].s = stoi(dataList[i][1]);
        data[i-1].c = stoi(dataList[i][2]);
    }
}

Individual Task::geneticAlgorithm {
    //PSEUDOCODE
    // task = read(input_file)
    // pop = init_population(task.n_items, POP_SIZE)
    // i = 0
    // while i < ITERATIONS:
    // j = 0
    // new_pop = Population()
    // 8while j < POP_SIZE:
    // parent1 = tournament(pop)
    // parent2 = tournament(pop)
    // child = crossover(parent1, parent2, CROSSOVER_RATE)
    // mutate(child, MUTATION_RATE)
    // new_pop.add(child)
    // j += 1
    // pop = new_pop
    // i += 1
    // return pop.best()
    Individual solution = nullptr;
    return solution;
}
