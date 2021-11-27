CC = g++
OPTIMS = -O3

./bin/main: ./src/main.cpp
	@echo "Compiling main.cpp..."
	$(CC) $(OPTIMS) -o ./bin/main ./src/main.cpp
	@echo "Done."

clean:
	@echo "Cleaning..."
	rm -f ./bin/main ./bin/*.o
	@echo "Done."