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

### 1. Criteria Clarification on Implementation of the task generator

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


## Analysis 🔬️

Below are the various conclusions showing the different experiments that support it.
Each experiment has been measured 4 times. The results is the average of them.

These experiments are realized over the dataset-EXP_Little where N = 100, W = 1000 and	S = 1000;
They can look like small numbers, s it said on "Lab1.pdf" it would be more appropriate to test with N = 1000;	W = 10000;	S = 10000; but there reason for use these number is the size of the experiments outputs files.  
Since this output shows the whole process of the algorithm, each iteration and each individual. If the dataset is too big these outputs will be too. So after checking that the results of the analysis are kept at a larger scale I have decided to explain the analysis on a simpler dataset.


```
exp00: 
	Dataset: dataset-EXP_Little		N = 100;	W = 1000;	S = 1000;
	POP_SIZE: 40	
	TOUR_SIZE: 10
	CROSSOVER_RATE: 0.7
	MUTATION_RATE:	0.001

 ==== Solutions: ====
	GA Average best solution:	1727.75	
	QEA best solution:		 2408
 ==== Times: ====
  Genetic Algorithm Average runtime:	57725.75 μs	(83 its)
  Quality Estimation Algorithm runtime:	41 μs

exp01: 
	Dataset: dataset-EXP_Little		N = 100;	W = 1000;	S = 1000;
	POP_SIZE: 60	
	TOUR_SIZE: 10
	CROSSOVER_RATE: 0.7
	MUTATION_RATE:	0.001

 ==== Solutions: ====
	GA Average best solution:	1820.75
	QEA best solution:		 2408
 ==== Times: ====
  Genetic Algorithm Average runtime:	94138.75 μs	(87.35 its)
  Quality Estimation Algorithm runtime:	41 μs


exp02: 
	Dataset: dataset-EXP_Little		N = 100;	W = 1000;	S = 1000;
	POP_SIZE: 100	
	TOUR_SIZE: 10
	CROSSOVER_RATE: 0.7
	MUTATION_RATE:	0.001

 ==== Solutions: ====
	GA Average best solution:	1977.75
	QEA best solution:		 2408
 ==== Times: ====
  Genetic Algorithm Average runtime:	198051.75 μs	(138 its)
  Quality Estimation Algorithm runtime:	41 μs
  
exp03: 
	Dataset: dataset-EXP_Little		N = 100;	W = 1000;	S = 1000;
	POP_SIZE: 300
	TOUR_SIZE: 10
	CROSSOVER_RATE: 0.7
	MUTATION_RATE:	0.001

 ==== Solutions: ====
	GA Average best solution:	2216
	QEA best solution:		 2408
 ==== Times: ====
  Genetic Algorithm Average runtime:	350051.25 μs	(91 its)
  Quality Estimation Algorithm runtime:	41 μs


exp04: 
	Dataset: dataset-EXP_Little		N = 100;	W = 1000;	S = 1000;
	POP_SIZE: 1000
	TOUR_SIZE: 10
	CROSSOVER_RATE: 0.7
	MUTATION_RATE:	0.001

 ==== Solutions: ====
	GA Average best solution:	2451
	QEA best solution:		 2408
 ==== Times: ====
  Genetic Algorithm Average runtime:	1515856.5 μs 	(115 its)
  Quality Estimation Algorithm runtime:	41 μs

exp05: 
	Dataset: dataset-EXP_Little		N = 100;	W = 1000;	S = 1000;
	POP_SIZE: 600
	TOUR_SIZE: 10
	CROSSOVER_RATE: 0.7
	MUTATION_RATE:	0.001

 ==== Solutions: ====
	GA Average best solution:	2360
	QEA best solution:		 2408
 ==== Times: ====
  Genetic Algorithm Average runtime:	1228033.5 μs 	(92 its)
  Quality Estimation Algorithm runtime:	41 μs

```
### Analysis of the impact of population size
Comparing the experiments from 0 to 5
where the population size takes the values of 40, 60, 100, 300, 1000 and 600, the rest of parameters are fixed, we can see that The larger the population, the better the result and the more time is required for counting.
It seems that the number of AG iterations is not affected by the size of the population.
The optimal point of population size will depend on the specific problem. In this case I think a good value would be between 600 and 1000.
As we see from 600 to 1000 is not very significant. Although it is true that with a population of 1000 elements, it is possible to have a better solution than even the estimation algorithm.
The larger the dimension of the problem, the larger the population must be in order to be optimal, as we will need to explore a larger space.

---

```
exp06: 
	Dataset: dataset-EXP_Little		N = 100;	W = 1000;	S = 1000;
	POP_SIZE: 800
	TOUR_SIZE: 40
	CROSSOVER_RATE: 0.7
	MUTATION_RATE:	0.001

 ==== Solutions: ====
	GA Average best solution:	2399
	QEA best solution:		 2408
 ==== Times: ====
  Genetic Algorithm Average runtime:	1339431 μs 	(101 its)
  Quality Estimation Algorithm runtime:	41 μs

exp07: 
	Dataset: dataset-EXP_Little		N = 100;	W = 1000;	S = 1000;
	POP_SIZE: 800
	TOUR_SIZE: 400
	CROSSOVER_RATE: 0.7
	MUTATION_RATE:	0.001

 ==== Solutions: ====
	GA Average best solution:	2385
	QEA best solution:		 2408
 ==== Times: ====
  Genetic Algorithm Average runtime:	6035886.25 μs 	(120 its)
  Quality Estimation Algorithm runtime:	41 μs
  
```

### Analysis of the impact of tournament size.
We have to be careful with this parameter as a very small value will not often select one of the best values in the population. And a value that is too high will always select the same element, so the individuals in the population will be very similar to each other. This causes the algorithm to stagnate and must do more iterations than necessary. In addition to greatly increasing the computation time.
Based on the experiments performed. I think a good value for the size of the tournament would be 10% of the total population.

---
```
exp08: 
	Dataset: dataset-EXP_Little		N = 100;	W = 1000;	S = 1000;
	POP_SIZE: 800
	TOUR_SIZE: 80
	CROSSOVER_RATE: 0
	MUTATION_RATE:	0.001

 ==== Solutions: ====
	GA Average best solution:	2415
	QEA best solution:		 2408
 ==== Times: ====
  Genetic Algorithm Average runtime:	3993516.25 μs 	(180 its)
  Quality Estimation Algorithm runtime:	41 μs
  

exp09: 
	Dataset: dataset-EXP_Little		N = 100;	W = 1000;	S = 1000;
	POP_SIZE: 800
	TOUR_SIZE: 80
	CROSSOVER_RATE: 0.5
	MUTATION_RATE:	0.001

 ==== Solutions: ====
	GA Average best solution:	2385
	QEA best solution:		 2408
 ==== Times: ====
  Genetic Algorithm Average runtime:	10095108.25 μs 	(180 its)
  Quality Estimation Algorithm runtime:	41 μs
  
 exp10: 
	Dataset: dataset-EXP_Little		N = 100;	W = 1000;	S = 1000;
	POP_SIZE: 800
	TOUR_SIZE: 80
	CROSSOVER_RATE: 0
	MUTATION_RATE:	0

 ==== Solutions: ====
	GA Average best solution:	1436
	QEA best solution:		 2408
 ==== Times: ====
  Genetic Algorithm Average runtime:	883555 μs 	( 50 its)
  Quality Estimation Algorithm runtime:	41 μs
  
```
### Analysis of the impact of the crossover probability:
As a result we see that if the population is large enough, and there is a small mutation ratio the crossover operator is not totally necessary, but it helps to improve the solution without doing so many iterations. Let's say it speeds up the algorithm in the right way. 
On the other hand, if both ratios are close to 0, the algorithm will quickly stagnate doing only 50 iterations, and the given solution will be far from being good.
It's good for us sometimes to keep an individual in the population without mixing it up. That's why we'll choose a crossover ratio close to 1 but not reaching it.
Therefore a good ratio for the crossover would be 0.7 or 0.8

---

```
 exp11: 
	Dataset: dataset-EXP_Little		N = 100;	W = 1000;	S = 1000;
	POP_SIZE: 800
	TOUR_SIZE: 80
	CROSSOVER_RATE: 0.7
	MUTATION_RATE:	0

 ==== Solutions: ====
	GA Average best solution:	1436
	QEA best solution:		 2408
 ==== Times: ====
  Genetic Algorithm Average runtime:	1274321 μs 	( 54 its)
  Quality Estimation Algorithm runtime:	41 μs
  
exp12: 
	Dataset: dataset-EXP_Little		N = 100;	W = 1000;	S = 1000;
	POP_SIZE: 800
	TOUR_SIZE: 80
	CROSSOVER_RATE: 0.7
	MUTATION_RATE:	0.8

 ==== Solutions: ====
	GA Average best solution:	0
	QEA best solution:		 2408
 ==== Times: ====
  Genetic Algorithm Average runtime:	1134608 μs 	( 54 its)
  Quality Estimation Algorithm runtime:	41 μs


exp13: 
	Dataset: dataset-EXP_Little		N = 100;	W = 1000;	S = 1000;
	POP_SIZE: 800
	TOUR_SIZE: 80
	CROSSOVER_RATE: 0.7
	MUTATION_RATE:	0.2

 ==== Solutions: ====
	GA Average best solution:	0
	QEA best solution:		 2408
 ==== Times: ====
  Genetic Algorithm Average runtime:	1134608 μs 	( 54 its)
  Quality Estimation Algorithm runtime:	41 μs

exp14:
	Dataset: dataset-EXP_Little		N = 100;	W = 1000;	S = 1000;
	POP_SIZE: 800
	TOUR_SIZE: 80
	CROSSOVER_RATE: 0.7
	MUTATION_RATE:	0.01

 ==== Solutions: ====
	GA Average best solution:	2481
	QEA best solution:		 1942
 ==== Times: ====
  Genetic Algorithm Average runtime:	3700583 μs 	( 209 its)
  Quality Estimation Algorithm runtime:	41 μs
  
exp15:
	Dataset: dataset-EXP_Little		N = 100;	W = 1000;	S = 1000;
	POP_SIZE: 800
	TOUR_SIZE: 80
	CROSSOVER_RATE: 0.7
	MUTATION_RATE:	0.001

 ==== Solutions: ====
	GA Average best solution: 2502
	QEA best solution:		 1942
 ==== Times: ====
  Genetic Algorithm Average runtime:	1691294 μs 	( 54 its)
  Quality Estimation Algorithm runtime:	41 μs

```

### Analysis of the impact of the mutation probability
A mutation rate that is too high will cause many individuals with a 0 value to fill the population and in the end we will not get a solution.
A 0 mutation rate will cause our population to be filled with very similar individuals
so do not evolve. Our solution will not be good.
So we have to select very low mutations rate, between 0.01 and 0.001 can be a good rate.
Between this values, higher the mutation rate, higher the computation time and iterations and higher the posibility to get very good solutions.

---

### Comparison of the best solution with any of the non-evolutionary methods.
I made an algorithm that characterized each item by a quality calculated by value/(weight+size). That algorithm will takes the items in order of quality.
We can easily compare the efficiency of this algorithm with the GA.
We can see that in the scale we are working this quality algorithm have good results faster than GA. But we can imagine that on a much larger scale this algorithm would cease to be computable, since it uses the brute force to calculate the qualities and look for the best in each selection. That is, from one point on, the GA should be a better option.
The result of this algortihm solution in our experiments dataset is showned in each the experiment to easy comparation.

---
 Project by: **Nicolás Magro Cruzado** | [GitLab](https://gitlab.com/Nico_Chico) ⌨️
