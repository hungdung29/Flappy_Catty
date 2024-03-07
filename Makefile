all: main run

main: main.cpp
	g++ -I src/include/SDL2 -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

run: main
	./main.exe

.PHONY: all run