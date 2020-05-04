<!-- THIS FILE IS ON MARKDOWN FORMAT. PLEASE READ IT ON GITLAB REPO: "https://gitlab.com/Nico_Chico/Genetic-Algorithm-for-Knapsack-Problem"
YOU CAN ALSO USE A PROPER .MD VISOR TO READ IT OR CONVERT TO PDF -->

# Genetic Algorithm for Knapsack Problem

*Laboratory 1, Introduction to Artificial Intelligence*

This is the first **laboratory work** of the **Introduction to Artificial Intelligence** 2020 course in the Computer Science program from **Politechnika Wrocławska** University.

The objective is getting familiar with Genetic Algorithms (GA) meta-heuristics in practice through individual implementation. And test its performance solving the classical *Knapsack Problem*. 

The project has been entirely developed in C++ language.

## How to compile the code

### Pre-requisites:
I use `boost::algorithm:split()` to parser lines of *CSV files* easier. So you may need to **install boost library**:

*On Debian GNU/Linux based systems:*

```bash
sudo apt-get install libboost-all-dev
```

### To compile it simply run:

*Make sure you have created the 'bin/' and 'obj/' directories*

```bash
make
```

*Or do the same manually:*

```bash
mkdir -p bin/ obj/
g++ -Wall -fexceptions -g -Iinclude -c "src/Lab1.cpp" -o "obj/Lab1.o"
g++ -Wall -fexceptions -g -Iinclude -c "src/Population.cpp" -o "obj/Population.o"
g++ -Wall -fexceptions -g -Iinclude -c "src/Task.cpp" -o "obj/Task.o"
g++  -o "bin/Lab1" "obj/Lab1.o" "obj/Population.o" "obj/Task.o"
g++  -o "bin/Lab1exp" "obj/Lab1exp.o" "obj/Population.o" "obj/Task.o"
```

## Project Structure
Basically, the code consists of two classes and main function:

### Class Population:   `Population.h` & `Population.cpp`
This class is responsible of store individuals population and contains the methods that deal with them. Like Genetic Operators.

### Class Task:         `Task.h` & `Task.cpp`
This class is responsible of save and manage the data and parameters from our currently problem.  

### Main Menu :       `Lab1.cpp`
Shows a Main Menu that controls the program from the top.

![menu img](https://gitlab.com/Nico_Chico/Genetic-Algorithm-for-Knapsack-Problem/-/raw/master/others/menu_screenshot_cut.png)

Menu is totally working on Linux Terminals.
On Windows Terminal unicode characters wont be shown properly. (CMD does not support yet.) And to compile it on Windows you will need to change `system("clear")` for `system("cls")` function.  Everything else should work exactly the same.
Using that menu you can change every parameters that the data generation or the genetic algorithm will use.

## Experiment Mode
The 'Lab1exp' binary contains only what is necessary for the experimental mode to work, eliminating the whole menu for easier compilation and testing.
You can use that binary to indicate an already programmed experiment by passing its name by parameter.

To make an experiment:
1. First create a file with the desired name in the 'experiments/' directory.
2. That file must contain 7 lines, where each line corresponds to one of the parameters in this order:
        
        01 N_ITEMS
        02 MAX_W		
        03 MAX_S
        04 POP_SIZE	
        05 TOUR_SIZE
        06 CROSSOVER_RATE
        07 MUTATION_RATE
        08 DATASET_NAME			 
        (If dataset don't exit in datasets/, it will be generated)
        (If it exist we read (N_Items, MAX_W, MAX_S) parameters of the dataset file instead of use the defined on the first three lines of this file.)
       *See 'experiments/exp01.in' to understand it better.*
3. Run the experiment:

    Running experiment 'exp01' the output will be shown by the terminal:
    ```bash
    bin/Lab1exp experiments/exp01.in
    ```
    
    Executing experiment 'exp01' and saving the output as a file:
    ```bash
    bin/Lab1exp experiments/exp01.in > experiments/exp01.out
    ```

*Much more information on how the code works is given in comments.*

## Some Documentation notes:

*Please read first `Lab1.pdf' to understand the project*

### 1. Criteria Aclaration on Implementation of the task generator

On Knapsack problem `function generate(n, w, s, output_file)`.
**Lab1.pdf sentence** that the set of generated items **meets the following criteria:**
![criteria img](https://gitlab.com/Nico_Chico/Genetic-Algorithm-for-Knapsack-Problem/-/raw/master/others/generation_criteria.png)

I was confused here:
**What is second criteria for? It's saying I have to program it? Or it's saying it's a property that's fulfilled?**

Let's see. Knowing that it is a random distribution, these sums should be approximately "the mean × nº elements"
· e.g for 'w'.

Average (mean) hoped: μ.            μ ≈ (1 + (10×w/n) )/2 ≈ 5w/n    ➔    ∑wi ≈ (5w/n) × n = 5w ≫ 2w

Seeing this we realize that the second criteria is a property that will be met in the vast majority of cases. So we don't have to program anything to force the criteria to be met. 

Also, in case there is any doubt, I made tests, checking the value of these sums. The result was what we expected. About 5w.

<!--
## Testing our Genetic Algorithm 👨‍🔬️ ⚙️


### Analysis of tests 🔩


## Conclusiones 

Si resulta que en una iteración se selecciona el mismo padre demasiado para la nueva publación. (Ya sea por un tamaño de población escaso o por un tamaño de torneo muy grande) la descendencia(next population) se estanca y sus individuos son demasiado parecidos.

<

-->
---
 Project by: **Nicolás Magro Cruzado** | [GitLab](https://gitlab.com/Nico_Chico) ⌨️