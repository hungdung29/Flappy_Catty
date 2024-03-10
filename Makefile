all: main run

main: code/main.cpp
	g++ -I src/include/SDL2 -L src/lib -L lib code/*.cpp -o main.exe -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

run: main
	./main.exe

.PHONY: all run