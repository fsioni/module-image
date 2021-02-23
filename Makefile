CC = g++
CFLAGS = -g -Wall
EXECS = bin/exemple bin/test bin/affichage
INCLUDE_DIR			= -Isrc -Isrc/core -Isrc/sdl2 -Itxt

ifeq ($(OS),Windows_NT)
	INCLUDE_DIR_SDL = 	-Iextern/SDL2_mingw-cb20/SDL2-2.0.12/x86_64-w64-mingw32/include/SDL2 \
						-Iextern/SDL2_mingw-cb20/SDL2_ttf-2.0.15/x86_64-w64-mingw32/include/SDL2 \
						-Iextern/SDL2_mingw-cb20/SDL2_image-2.0.5/x86_64-w64-mingw32/include/SDL2 \
						-Iextern/SDL2_mingw-cb20/SDL2_mixer-2.0.4/x86_64-w64-mingw32/include/SDL2

	LIBS_SDL = -Lextern \
			-Lextern/SDL2_mingw-cb20/SDL2-2.0.12/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_ttf-2.0.15/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_image-2.0.5/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_mixer-2.0.4/x86_64-w64-mingw32/lib \
			-lmingw32 -lSDL2main -lSDL2.dll -lSDL2_ttf.dll -lSDL2_image.dll -lSDL2_mixer.dll

else
	INCLUDE_DIR_SDL = -I/usr/include/SDL2
	LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
endif




all: $(EXECS)

bin/exemple : obj/mainExemple.o obj/Pixel.o obj/Image.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS_SDL)

bin/test : obj/mainTest.o obj/Pixel.o obj/Image.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS_SDL)

bin/affichage : obj/mainAffichage.o obj/Pixel.o obj/Image.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS_SDL)

obj/mainAffichage.o : src/mainAffichage.cpp src/Pixel.h src/Image.h
	$(CC) $(CFLAGS) -c $< -o $@  $(INCLUDE_DIR_SDL) $(INCLUDE_DIR)

obj/mainTest.o : src/mainTest.cpp src/Pixel.h src/Image.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_DIR_SDL) $(INCLUDE_DIR)

obj/mainExemple.o : src/mainExemple.cpp src/Pixel.h src/Image.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_DIR_SDL) $(INCLUDE_DIR)

obj/Image.o : src/Image.cpp src/Image.h src/Pixel.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_DIR_SDL) $(INCLUDE_DIR)

obj/Pixel.o : src/Pixel.cpp src/Pixel.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_DIR_SDL) $(INCLUDE_DIR)

clean :
	rm obj/*.o $(EXECS)

docs :
	doxygen doc/image.doxy