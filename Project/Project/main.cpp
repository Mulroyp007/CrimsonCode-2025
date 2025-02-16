/*
Tasks: Open an img and get pixel data
       Figure out how to play sound
       Find an algorithm to convert pixels to sound
*/


#define _CRT_SECURE_NO_WARNINGS

#include "PNGImage.hpp"
#include <iostream>
#include <fstream>






#pragma comment(lib,"winmm.lib")



int main(void) {
    
  
    
    Pixel* pixelArr = NULL;
    
    PNGImage image("art-artistic-background-1566909.jpg");

    

    pixelArr = image.getPixelData();

    ImageSoundData sound(pixelArr,64,64);

    sound.playImageSound(pixelArr, image.getWidth() * image.getHeight());
    



    free(pixelArr);

    //cs_init(NULL, 44100, 1024, NULL);
    // cs_audio_source_t* = cs_load_wav("Flight_Hymn_by_Ross_Bugden.wav", NULL);
    // cs_music_play(cs_audio_source_t, 10);
    //   



    
    return 0;
}