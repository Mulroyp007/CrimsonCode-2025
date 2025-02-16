/*
Tasks: Open an img and get pixel data
       Figure out how to play sound
       Find an algorithm to convert pixels to sound
*/
#include "pixel.hpp"
#include "PNGImage.hpp"

#pragma comment(lib,"winmm.lib")


int main(void) {
    
    
    
   
    PNGImage image("thrawn6.png");
    






    PlaySound(TEXT("Note_block_banjo.wav"), NULL, SND_FILENAME );
    PlaySound(TEXT("Note_block_guitar.ogg.wav"), NULL, SND_FILENAME);
    PlaySound(TEXT("Note_block_guitar.ogg.wav"), NULL, SND_FILENAME);
    
    return 0;
}