#pragma once

#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <ctime>
#include <cstdlib>
#include <fstream>

typedef struct pixel {
	int r, g, b;
}Pixel;


class ImageSoundData
{

public:

	ImageSoundData(Pixel img[], int width =0, int height = 0);

#pragma region Setters
	void setRedPixels(Pixel img[], int width, int height);
	void setGreenPixels(Pixel img[], int width, int height);
	void setBluePixels(Pixel img[], int width, int height);

	int setRedScatter(Pixel img[]);
	int setGreenScatter(Pixel img[]);
	int setBlueScatter(Pixel img[]);

#pragma endregion

#pragma region Getters
	int getRedPixels(void) const;
	int getGreenPixels(void) const;
	int getBluePixels(void) const;

	double getRedScatter(void);
	double getGreenScatter(void);
	double getBlueScatter(void);
#pragma endregion

	void playImageSound(Pixel img[], int width);


private:
	int redPixels, bluePixels, greenPixels, width, height;
	double redScatter, blueScatter, greenScatter;

};

void playSound(int pixelCode);

std::ostream& operator<<(std::ostream& lhs, const Pixel& rhs);