CFLAGS = -O3 -Wall -std=c++11
CFLAGS = -g -Wall -std=c++11

hw2: hw2.o Simulator.o
	@echo "Compiling..."
	g++ -o $@ hw2.o Simulator.o $(CFLAGS)
	@echo "Done."

Simulator.o: Simulator.h Simulator.cpp
	g++ -c Simulator.h Simulator.cpp $(CFLAGS)

clean:
	rm -f hw2 test asmSim *.o *.h.gch output/result*
	@echo "Done." 