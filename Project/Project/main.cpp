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
    
      
    
    
    return 0;
}