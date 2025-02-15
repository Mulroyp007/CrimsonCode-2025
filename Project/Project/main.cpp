/*
Tasks: Open an img and get pixel data
       Figure out how to play sound
       Find an algorithm to convert pixels to sound
*/
#include "pixel.hpp"

#pragma comment(lib, "winmm.lib")

int main(void) {
    
    //PlaySound((LPCSTR)"C:\\kenny g.WAV", NULL, SND_ASYNC);
    PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS);
    std::cout << "Breakfast time ding" << std::endl;
    
    
    return 0;
}