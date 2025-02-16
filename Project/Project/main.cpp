/*
Tasks: Open an img and get pixel data
       Figure out how to play sound
       Find an algorithm to convert pixels to sound
*/

#include "PNGImage.hpp"

#pragma comment(lib,"winmm.lib")


int main(void) {
    
    
    Pixel* pixelArr = NULL;
    
    PNGImage image("song.jpg");

   

    pixelArr = image.getPixelData();

    ImageSoundData sound(pixelArr);

    sound.playImageSound(pixelArr, 1000);
    











   /* PlaySound(TEXT("Note_block_banjo.wav"), NULL, SND_FILENAME );

    PlaySound(TEXT("Note_block_guitar.wav"), NULL, SND_FILENAME);

    PlaySound(TEXT("Note_block_flute.wav"), NULL, SND_FILENAME);

    PlaySound(TEXT("Note_block_cow_bell.wav"), NULL, SND_FILENAME);

    PlaySound(TEXT("Note_block_didgeridoo.wav"), NULL, SND_FILENAME);

    PlaySound(TEXT("Note_block_snare.wav"), NULL, SND_FILENAME);*/
    
    return 0;
}