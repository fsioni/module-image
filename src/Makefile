all: executable

executable : main.o Pixel.o Image.o 
	g++ -g main.o Pixel.o Image.o -o executable

main.o : main.cpp Pixel.h Image.h
	g++ -g -Wall -c main.cpp

Image.o : Image.h Image.cpp Pixel.h
	g++ -g -Wall -c Image.cpp

Pixel.o : Pixel.h Pixel.cpp
	g++ -g -Wall -c Pixel.cpp

clean :
	rm *.o

veryclean : 
	rm *.out

