# Genetic Algorithm for Knapsack Problem

*Laboratory 1, Introduction to Artificial Intelligence*

This is the first **laboratory work** of the **Introduction to Artificial Intelligence** 2020 course in the Computer Science program from **Politechnika Wrocławska**

The objetive is getting familiar with Genetic Algorithms (GA) metaheuristics in practice through individual implementation. And test its performance solving the classical *Knapsack Problem*. 

The project has been entirely developed in C++ language.

## How to compile the code. 🚀

### Pre-requisites:
I use `boost::algorithm:split()` to parser lines of *CSV files* easier. So you may need to **install boost library**:

*On Debian GNU/Linux based systems:*

```bash
sudo apt-get install libboost-all-dev
```

### To compile it simply run:

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
```

## Project Structure
Basically, the code consists of two classes and main function:

### Class Population:   `Population.h` & `Population.cpp`
This class is responsible of store individuals population and contains the methods that deal with them. Like Genetic Operators.

### Class Task:         `Task.h` & `Task.cpp`
This class is responsible of save and manage the data and parameters from our currently problem.  

### Main function:       `main.cpp`
Shows a Main Menu that controls the program from the top.
```plain
  
        🧪🧬  𝔾𝕖𝕟𝕖𝕥𝕚𝕔 𝔸𝕝𝕘𝕠𝕣𝕚𝕥𝕙𝕞  𝚏𝚘𝚛 𝙺𝚗𝚊𝚙𝚜𝚊𝚌𝚔 𝙿𝚛𝚘𝚋𝚕𝚎𝚖 
  
 --- PARAMETERS -----------------------------------------
    N.º items: 1000    Max. Weight: 10000    Max. Size: 10000	
    Data loaded: ❌
    Population size: 50        Tournament size: 20
    Crossover rate: 0.7         Mutation rate: 0
 --------------------------------------------------------
  
  1. 🔧	| Set Task parameters
  2. 📊	| Generate dataset
  3. 💾	| Read dataset
  4. 👀	| Show dataset in use
  5. ⚙️	| Set Algorithm parameters
  6. 🧬	| Use 'Genetic Algorithm'
  0. 🡄	| Exit
  
 >   
  
```

From here you can change the parameters that the data generation or the genetic algorithm will use. can also change this parameters manualy on the main.cpp

*More information is detailed in the source code comments.*

*More information is detailed in the source code comments.*



<!--
## Testing our Genetic Algorithm 👨‍🔬️ ⚙️


### Analysis of tests 🔩


## Conclusiones 

Si resulta que en una iteración se selecciona el mismo padre demasiado para la nueva publación. (Ya sea por un tamaño de población escaso o por un tamaño de torneo muy grande) la descendencia(next population) se estanca y sus individuos son demasiado parecidos.



-->
---
 Project by: **Nicolás Magro Cruzado** | [GitLab](https://gitlab.com/Nico_Chico) ⌨️