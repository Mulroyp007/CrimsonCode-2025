/*
Tasks: Open an img and get pixel data
       Figure out how to play sound
       Find an algorithm to convert pixels to sound
*/

#include "PNGImage.hpp"
#include <xaudio2.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

#pragma comment(lib, "xaudio2.lib")

#pragma comment(lib,"winmm.lib")



int main(void) {
    
  
    
    Pixel* pixelArr = NULL;
    
    PNGImage image("art-artistic-background-1566909.jpg");

    

    pixelArr = image.getPixelData();

    ImageSoundData sound(pixelArr,64,64);

    sound.playImageSound(pixelArr, 1000);

     
    return 0;
}