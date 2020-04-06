all:	bin/Lab1 bin/Lab1exp

bin/Lab1: obj/Population.o obj/Task.o obj/Lab1.o
	g++ -o bin/Lab1 obj/Lab1.o obj/Population.o obj/Task.o

bin/Lab1exp: obj/Population.o obj/Task.o obj/Lab1exp.o
	g++ -o bin/Lab1exp obj/Lab1exp.o obj/Population.o obj/Task.o
	
obj/Population.o: src/Population.cpp src/Population.h
	g++ -Wall -fexceptions -g -Iinclude -c src/Population.cpp -o obj/Population.o

obj/Task.o: src/Task.cpp src/Task.h
	g++ -Wall -fexceptions -g -Iinclude -c "src/Task.cpp" -o "obj/Task.o"

obj/Lab1.o: src/Lab1.cpp
	g++ -Wall -fexceptions -g -Iinclude -c "src/Lab1.cpp" -o "obj/Lab1.o"
	
obj/Lab1exp.o: src/Lab1exp.cpp
	g++ -Wall -fexceptions -g -Iinclude -c "src/Lab1exp.cpp" -o "obj/Lab1exp.o"


clean: 
	rm bin/* obj/*


