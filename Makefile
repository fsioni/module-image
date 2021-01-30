all: bin/exemple.out bin/test.out

bin/exemple.out : obj/mainExemple.o obj/Pixel.o obj/Image.o
	g++ -g -Wall obj/mainExemple.o obj/Pixel.o obj/Image.o -o bin/exemple.out

bin/test.out : obj/mainTest.o obj/Pixel.o obj/Image.o
	g++ -g -Wall obj/mainTest.o obj/Pixel.o obj/Image.o -o bin/test.out

obj/mainTest.o : src/mainTest.cpp src/Pixel.h src/Image.h
	g++ -g -Wall -c src/mainTest.cpp -o obj/mainTest.o

obj/mainExemple.o : src/mainExemple.cpp src/Pixel.h src/Image.h
	g++ -g -Wall -c src/mainExemple.cpp -o obj/mainExemple.o

obj/Image.o : src/Image.h src/Image.cpp src/Pixel.h
	g++ -g -Wall -c src/Image.cpp -o obj/Image.o

obj/Pixel.o : src/Pixel.h src/Pixel.cpp
	g++ -g -Wall -c src/Pixel.cpp -o obj/Pixel.o

clean :
	rm bin/*.o

veryclean : 
	rm bin/*.out