CC = g++
OPTIMS = -O3

./bin/mps: ./src/main.cpp
	@echo "Compiling main.cpp..."
	$(CC) $(OPTIMS) -o ./bin/mps ./src/main.cpp
	@echo "Done."

clean:
	@echo "Cleaning..."
	rm -f ./bin/main ./bin/*.o
	@echo "Done."