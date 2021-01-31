CC = g++
CFLAGS = -g -Wall
EXECS = bin/exemple.out bin/test.out bin/affichage.out

all: $(EXECS)

bin/exemple.out : obj/mainExemple.o obj/Pixel.o obj/Image.o
	$(CC) $(CFLAGS) $^ -o $@

bin/test.out : obj/mainTest.o obj/Pixel.o obj/Image.o
	$(CC) $(CFLAGS) $^ -o $@

bin/affichage.out : obj/mainAffichage.o obj/Pixel.o obj/Image.o
	$(CC) $(CFLAGS) $^ -o $@

obj/mainAffichage.o : src/mainAffichage.cpp src/Pixel.h src/Image.h
	$(CC) $(CFLAGS) -c $< -o $@

obj/mainTest.o : src/mainTest.cpp src/Pixel.h src/Image.h
	$(CC) $(CFLAGS) -c $< -o $@

obj/mainExemple.o : src/mainExemple.cpp src/Pixel.h src/Image.h
	$(CC) $(CFLAGS) -c $< -o $@

obj/Image.o : src/Image.cpp src/Image.h src/Pixel.h
	$(CC) $(CFLAGS) -c $< -o $@

obj/Pixel.o : src/Pixel.cpp src/Pixel.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm obj/*.o

veryclean : 
	rm $(EXECS)

docs :
	doxygen doc/image.doxy
