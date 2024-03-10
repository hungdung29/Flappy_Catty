#include "pipe.h"

const int pipeWidth = 50;
const int screenWidth = 800;

Pipe::Pipe(SDL_Renderer* renderer, float x) : renderer(renderer), xPos(x), yPos(0), xVelocity(-2.0f) {
    // Load pipe texture
}

Pipe::~Pipe() {
    // Release resources
}

void Pipe::Update(float deltaTime) {
    // Update position based on velocity
    xPos += xVelocity * deltaTime;

    // Check if the pipe is off-screen, then reset its position
    if (xPos + pipeWidth < 0) {
        xPos = screenWidth;
        // Randomize the height of the pipe or implement a fixed pattern
    }
}

void Pipe::Draw() {
    // Render the pipe at its current position
}
