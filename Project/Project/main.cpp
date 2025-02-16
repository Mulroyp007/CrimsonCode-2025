/*
Tasks: Open an img and get pixel data
       Figure out how to play sound
       Find an algorithm to convert pixels to sound
*/


#define _CRT_SECURE_NO_WARNINGS

#include "PNGImage.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

#define CUTE_SOUND_IMPLEMENTATION
//#include "cute_headers-master\cute_sound.h"







#pragma comment(lib,"winmm.lib")



int main(void) {
    
  
    
    Pixel* pixelArr = NULL;
    
    PNGImage image("art-artistic-background-1566909.jpg");

    

    pixelArr = image.getPixelData();

    ImageSoundData sound(pixelArr,64,64);

    sound.playImageSound(pixelArr, image.getWidth());

  
    //cs_init(NULL, 44100, 1024, NULL);
    //
    //
    //cs_audio_source_t* song = cs_load_wav("Flight_Hymn_by_Ross_Bugden.wav", NULL);
    //cs_sound_params_t params = cs_sound_params_default();
    //
    //cs_play_sound(song, params);

  
    
    return 0;
}