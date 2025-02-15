/*
Tasks: Open an img and get pixel data
       Figure out how to play sound
       Find an algorithm to convert pixels to sound
*/
#include "pixel.hpp"

#pragma comment(lib, "winmm.lib")

int main(void) {
    
    //PlaySound((LPCSTR)"C:\\kenny g.WAV", NULL, SND_ASYNC);
    //PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS);
    PlaySound(L"C:\\Users\parne\Downloads\Note_block_iron_xylophone.ogg.wav", NULL, SND_FILENAME);
    

    
    
    return 0;
}