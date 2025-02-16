#pragma once

#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <ctime>
#include <cstdlib>
#include <fstream>

typedef struct pixel {
	int r, g, b;
	double brightness;
}Pixel;


class ImageSoundData
{

public:

	ImageSoundData(Pixel img[], int width =0, int height = 0);

#pragma region Setters
	void setRedPixels(Pixel img[], int width, int height);
	void setGreenPixels(Pixel img[], int width, int height);
	void setBluePixels(Pixel img[], int width, int height);

	int setRedScatter(Pixel img[], int size);
	int setGreenScatter(Pixel img[], int size);
	int setBlueScatter(Pixel img[], int size);
	void setAvgBrightness(Pixel img[], int size);

#pragma endregion

#pragma region Getters
	int getRedPixels(void) const;
	int getGreenPixels(void) const;
	int getBluePixels(void) const;

	double getRedScatter(void);
	double getGreenScatter(void);
	double getBlueScatter(void);
	double getAvgBrightness(void);
#pragma endregion

	void playImageSound(Pixel img[], int width);


private:
	int redPixels, bluePixels, greenPixels, width, height;
	double redScatter, blueScatter, greenScatter; //avg distance between each pixel of the color
	double avgBrightness;

};

void playSound(int pixelCode);

uint32_t ReadUInt32(std::ifstream& file);

uint16_t ReadUInt16(std::ifstream& file);

std::ostream& operator<<(std::ostream& lhs, const Pixel& rhs);