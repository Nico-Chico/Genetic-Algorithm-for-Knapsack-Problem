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

![menu img](https://gitlab.com/Nico_Chico/Genetic-Algorithm-for-Knapsack-Problem/-/raw/master/others/menu_screenshot_cut.png)

Menu is totally working on most Linux Terminal.
On Windows Terminal unicode characters wont be shown properly. (CMD does not support yet.) And to compile it on Windows you will need to change `system("clear")` for `system("cls")` function.  Everything else should work exactly the same.
From here you can change the parameters that the data generation or the genetic algorithm will use. can also change this parameters manualy on the main.cpp

*More information is detailed in the source code comments.*

## Some Documentation notes:

*Please read first `Lab1.pdf'*

### 1. Implementation of the task generator

Knapsack problem `function generate(n, w, s, output_file)`
Lab1.pdf sentence that the set of generated items meets the following criteria:
![criteria img](https://gitlab.com/Nico_Chico/Genetic-Algorithm-for-Knapsack-Problem/-/raw/master/others/generation_criteria.png)

I was confused here.
**What is second criteria for? It's saying I have to program it? Or it's saying it's a property that's fulfilled?**

I tried to make myself clear:
Knowing that it is a random distribution, these sums are aproxmitly the  "mean × nº elements"
· e.g for 'w'.
Average (mean) hoped :   
 (1 + (10×w/n) )/2 ≈ 5w/n
∑wi ≈ (5w/n) × n = 5w ≫ 2w
It will be satisfied in most of the cases. Because the range our random variables. 






<!--
## Testing our Genetic Algorithm 👨‍🔬️ ⚙️


### Analysis of tests 🔩


## Conclusiones 

Si resulta que en una iteración se selecciona el mismo padre demasiado para la nueva publación. (Ya sea por un tamaño de población escaso o por un tamaño de torneo muy grande) la descendencia(next population) se estanca y sus individuos son demasiado parecidos.



-->
---
 Project by: **Nicolás Magro Cruzado** | [GitLab](https://gitlab.com/Nico_Chico) ⌨️