# Genetic Algorithm for Knapsack Problem

*Laboratory 1, Introduction to Artificial Intelligence*

This is the first **laboratory work** of the **Introduction to Artificial Intelligence** 2020 course of the Computer Science program of **Politechnika Wrocławska**

The objective is to understand the behaviour and test the performance of the use of Genetic Algorithms in the optimization of the backpack problem. The project has been entirely developed in C++ language.

## How to compile the code. 🚀

### Pre-requisites: 📋
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


## Testing our Genetic Algorithm 👨‍🔬️ ⚙️

_Explica como ejecutar las pruebas automatizadas para este sistema_

### Analysis of tests 🔩

_Explica que verifican estas pruebas y por qué_

```
Da un ejemplo
```

---


## Author ✒️

* **Nicolás Magro Cruzado** | [GitLab](https://gitlab.com/Nico_Chico)

También puedes mirar la lista de todos los [contribuyentes](https://github.com/your/project/contributors) quíenes han participado en este proyecto. 


## Conclusiones 🎁

* Comenta a otros sobre este proyecto 📢
* Invita una cerveza 🍺 o un café ☕ a alguien del equipo. 
* Da las gracias públicamente 🤓.
* etc.



---
⌨️ ✒️ Project by: **Nicolás Magro Cruzado** | [GitLab](https://gitlab.com/Nico_Chico)