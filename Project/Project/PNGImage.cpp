#define STB_IMAGE_IMPLEMENTATION
#include "PNGImage.hpp"


PNGImage::PNGImage(const std::string& fileName, int width, int height, int channels) {
	imageData = nullptr;
	this->width = width;
	this->height = height;
	this->channels = channels;


	// image read
	imageData = stbi_load(fileName.c_str(), &width, &height, &channels, 3);

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


	Pixel* pixelArray = (Pixel*)malloc(sizeof(Pixel) * width * height);
	if (pixelArray == NULL) return NULL;


	//Assumes 3 channel imageData
	for (int i = 0; i < height * width * 3; i+=3)
	{
		pixelArray[i].r = imageData[i];
		pixelArray[i].g = imageData[i + 1];
		pixelArray[i].b = imageData[i + 2];

		std::cout << pixelArray[i] << std::endl;
	}

}
