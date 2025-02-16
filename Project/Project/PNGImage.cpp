#define STB_IMAGE_IMPLEMENTATION
#include "PNGImage.hpp"


PNGImage::PNGImage(const std::string& fileName, int width, int height, int channels) {
	imageData = nullptr;
	this->width = width;
	this->height = height;
	this->channels = channels;


	// image read
	imageData = stbi_load(fileName.c_str(), &width, &height, &channels, 3);

	this->width = width;
	this->height = height;
	this->channels = channels;

	// check if image read
	if (!imageData) {
		std::cout << "Failed To Read Image" << std::endl;
	}
	else {
		std::cout << "Width:" << width << " " << "Height:" << height << " " << "Channels:" << channels << " " << std::endl;

	}
}

PNGImage::~PNGImage() {
	if (imageData) {
		stbi_image_free(imageData);
		std::cout << "Image memory freed." << std::endl;
	}
}

int PNGImage::getWidth() const
{
	return width;
}

int PNGImage::getHeight() const
{
	return height;
}

int PNGImage::getChannels() const
{
	return channels;
}

unsigned char* PNGImage::getImageData() const
{
	return imageData;
}

Pixel* PNGImage::getPixelData(void)
{
	if (imageData == NULL) return NULL;


	Pixel* pixelArray = new Pixel[this->width * height];
	if (pixelArray == NULL) return NULL;

	int pixelIndex = 0;
	//Assumes 3 channel imageData
	for (int i = 0; i < height * width * 3; i+=3)
	{
		pixelArray[pixelIndex].r = imageData[i];
		pixelArray[pixelIndex].g = imageData[i + 1];
		pixelArray[pixelIndex].b = imageData[i + 2];
		
		//std::cout << pixelArray[pixelIndex] << std::endl;

		pixelIndex++;
	}
	return pixelArray;
}
