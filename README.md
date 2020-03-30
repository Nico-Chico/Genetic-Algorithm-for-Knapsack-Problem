# Genetic Algorithm for Knapsack Problem

*Laboratory 1, Introduction to Artificial Intelligence*

This is the first **laboratory work** of the **Introduction to Artificial Intelligence** 2020 course in the Computer Science program from **Politechnika Wrocławska**

**Objective:**
Getting familiar with Genetic Algorithms (GA) metaheuristics in practice through individual implementation.

Understand the behaviour and test the performance of the use of Genetic Algorithms in the **optimization** of the *Knapsack Problem*. 
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

---

## Project Structure
Basically, the code consists of two classes and main function:

### Class Population:   `Population.h` & `Population.cpp`
This class is responsible of store individuals population and contains the methods that deal with them. Like Genetic Operators.

### Class Task:         `Task.h` & `Task.cpp`
This class is responsible of save and manage the data and parameters from our currently problem.  

###Main function:       `main.cpp`
Controls the program from the top.
From here you can change the parameters that the data generation or the genetic algorithm will use.

*More information is detailed in the source code comments.*



<!--
## Testing our Genetic Algorithm 👨‍🔬️ ⚙️


### Analysis of tests 🔩


## Conclusiones 

Si resulta que en una iteración se selecciona el mismo padre demasiado para la nueva publación. (Ya sea por un tamaño de población escaso o por un tamaño de torneo muy grande) la descendencia(next population) se estanca y sus individuos son demasiado parecidos.



-->
---
 Project by: **Nicolás Magro Cruzado** | [GitLab](https://gitlab.com/Nico_Chico) ⌨️