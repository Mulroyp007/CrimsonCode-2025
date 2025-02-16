#pragma once

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "stb_image.h"
#include "pixel.hpp"

//typedef struct pixel {
//	int r, g, b;
//}Pixel;


class PNGImage {

private:
	unsigned char* imageData;
	int width;
	int height;
	int channels;

public:

#pragma region Constructors

	PNGImage(const std::string& fileName, int width = 0, int height = 0, int channels = 0);

#pragma endregion 

	// deconstructor
	~PNGImage();

#pragma region Getters
	int getWidth() const;
	int getHeight() const;
	int getChannels() const;
	unsigned char* getImageData() const;

#pragma endregion
	
	// test
	Pixel* getPixelData(void);

};

