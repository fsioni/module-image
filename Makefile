all: bin/executable.out

bin/executable.out : bin/main.o bin/Pixel.o bin/Image.o 
	g++ -g bin/main.o bin/Pixel.o bin/Image.o -o bin/executable.out

bin/main.o : src/main.cpp src/Pixel.h src/Image.h
	g++ -g -Wall -c src/main.cpp -o bin/main.o

bin/Image.o : src/Image.h src/Image.cpp src/Pixel.h
	g++ -g -Wall -c src/Image.cpp -o bin/Image.o

bin/Pixel.o : src/Pixel.h src/Pixel.cpp
	g++ -g -Wall -c src/Pixel.cpp -o bin/Pixel.o

clean :
	rm bin/*.o

veryclean : 
	rm bin/*.out

