/*
Tasks: Open an img and get pixel data
       Figure out how to play sound
       Find an algorithm to convert pixels to sound
*/
#include "pixel.hpp"
#include "PNGImage.hpp"

#pragma comment(lib,"winmm.lib")


int main(void) {
    
    
    Pixel* pixelArr = NULL;
    
    PNGImage image("thrawn6.png");

    pixelArr = image.getPixelData();
    
    /*std::srand(std::time(0));
    int random = 0;
    random = std::rand() % 10 + 1;
    int guess = 0;

    std::cout << "Guess a number 1-10: ";
    std::cin >> guess;
    if (guess == random) std::cout << "Correct Guess!!!!!" << std::endl;
    else std::cout << "You stoopid" << std::endl;*/
    
    return 0;
}