#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
//#include <irrKlang.h>
//using namespace irrklang;

//#pragma comment(lib, "irrKlang.lib")


typedef struct pixel
{
	int r, g, b;
}Pixel;

class ImageSoundData
{

public:

	ImageSoundData(Pixel img[]);

#pragma region Setters
	int setRedPixels(Pixel img[]);
	int setGreenPixels(Pixel img[]);
	int setBluePixels(Pixel img[]);

	int setRedScatter(Pixel img[]);
	int setGreenScatter(Pixel img[]);
	int setBlueScatter(Pixel img[]);

#pragma endregion

#pragma region Getters
	int getRedPixels(void);
	int getGreenPixels(void);
	int getbluePixles(void);

	double getRedScatter(void);
	double getGreenScatter(void);
	double getBlueScatter(void);
#pragma endregion

	void playImageSound(void);


private:
	int redPixels = 0, greenPixels = 0, bluePixels = 0;
	double redScatter = 0.0, greenScatter = 0.0, blueScatter = 0.0;
};

void playSound(int pixelCode);