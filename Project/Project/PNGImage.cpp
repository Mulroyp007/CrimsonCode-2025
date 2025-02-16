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


Pixel* PNGImage::getPixelData()
{
	if (imageData == NULL) return NULL;


	Pixel* pixelArray = new Pixel[this->width * height];
	if (pixelArray == NULL) return NULL;

	int pixelIndex = 0;
	//Assumes 3 channel imageData
	for (int i = 0; i < height * width * 3; i += 3)
	{
		pixelArray[pixelIndex].r = imageData[i];
		pixelArray[pixelIndex].g = imageData[i + 1];
		pixelArray[pixelIndex].b = imageData[i + 2];

		pixelArray[pixelIndex].brightness = (pixelArray[pixelIndex].r + pixelArray[pixelIndex].g + pixelArray[pixelIndex].b) / (255 * 3);

		/*std::cout << pixelArray[pixelIndex] << std::endl;*/
		pixelIndex++;
	}
	ImageSoundData imgSoundData(pixelArray, this->width, this->height);
	imgSoundData.setRedPixels(pixelArray, this->width, this->height);
	imgSoundData.setGreenPixels(pixelArray, this->width, this->height);
	imgSoundData.setBluePixels(pixelArray, this->width, this->height);

	std::cout << "Red pixels: " << imgSoundData.getRedPixels() << std::endl;
	std::cout << "Green pixels: " << imgSoundData.getGreenPixels() << std::endl;
	std::cout << "Blue pixels: " << imgSoundData.getBluePixels() << std::endl;

	return pixelArray;
}

