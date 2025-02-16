#include "pixel.hpp"

ImageSoundData::ImageSoundData(Pixel img[], int width, int height)
{
	this->bluePixels = 0;
	this->redPixels = 0;
	this->greenPixels = 0;
	this->greenScatter = 0.0;
	this->redScatter = 0.0;
	this->blueScatter = 0.0;
	this->width = width;
	this->height = height;
}

void ImageSoundData::setRedPixels(Pixel img[], int width, int height)
{

	for (int i = 0; i < width * height; i++) {
		if (img[i].r > img[i].b && img[i].r > img[i].g) {
			redPixels++;
		}
	}
}

void ImageSoundData::setGreenPixels(Pixel img[], int width, int height)
{

	for (int i = 0; i < width * height; i++) {
		if (img[i].g > img[i].r && img[i].g > img[i].b) {
			greenPixels++;
		}
	}
}

void ImageSoundData::setBluePixels(Pixel img[], int width, int height)
{
	for (int i = 0; i < width * height; i++) {
		if (img[i].b > img[i].r && img[i].b > img[i].g) {
			bluePixels++;
		}
	}
}

int ImageSoundData::setRedScatter(Pixel img[])
{
	return 0;
}

int ImageSoundData::setGreenScatter(Pixel img[])
{
	return 0;
}

int ImageSoundData::setBlueScatter(Pixel img[])
{
	return 0;
}

int ImageSoundData::getRedPixels(void) const
{
	return redPixels;
}

int ImageSoundData::getGreenPixels(void) const
{
	return greenPixels;
}

int ImageSoundData::getBluePixels(void) const
{
	return bluePixels;
}

double ImageSoundData::getRedScatter(void)
{
	return 0.0;
}

double ImageSoundData::getGreenScatter(void)
{
	return 0.0;
}

double ImageSoundData::getBlueScatter(void)
{
	return 0.0;
}

void ImageSoundData::playImageSound(Pixel img[], int width)
{
	//convert from r,g,b to 1,2,3,4,5,6,7,or 8
	std::srand(std::time(0));
	int length = 0;
	length = std::rand() % 10 + 1;
	int row = 0;
	int i = 0;
	while (row < 3) {
		while (i < length) {
		int sum = 0;
		sum = img[i].r + img[i].g + img[i].b;
		//0-765
		if (sum > 670) {
			playSound(1);
		}
		else if (sum > 575) {
			playSound(2);
		}
		else if (sum > 480) {
			playSound(3);
		}
		else if (sum > 385) {
			playSound(4);
		}
		else if (sum > 290) {
			playSound(5);
		}
		else if (sum > 195) {
			playSound(6);
		}
		else if (sum > 100) {
			playSound(7);
		}
		else {
			playSound(8);
		}
			i++;
		}
		i = 0;
		i += (2 * width - length);
		length += (2 * width);
		row++;
	}
}

/****************************************************************************
* Function: playSound()
* Date Created: 2/15/25
* Date Last Modified: 2/15/25
* Description: Based on code passed in, plays one of the included sounds
* Input parameters: int pixelCode
* Returns: none
* Preconditions: start of program
* Postconditions: sound is played
*/
void playSound(int pixelCode)
{
	switch (pixelCode) {
	case 1:
		sndPlaySound(TEXT("Note_block_guitar.wav"), NULL);
		break;
	case 2:
		sndPlaySound(TEXT("Note_block_iron_xylophone.wav"), NULL);
		break;
	case 3:
		sndPlaySound(TEXT("Note_block_banjo.wav"), NULL);
	case 4:
		sndPlaySound(TEXT("Note_block_bassattack.wav"), NULL);
		break;
	case 5:
		sndPlaySound(TEXT("Note_block_cow_bell.wav"), NULL);
		break;
	case 6:
		sndPlaySound(TEXT("Note_block_didgeridoo.wav"), NULL);
		break;
	case 7:
		sndPlaySound(TEXT("Note_block_flute.wav"), NULL);
		break;
	case 8:
		PlaySound(TEXT("Note_block_snare.wav"), NULL, SND_FILENAME);
		break;
	}
}

std::ostream& operator<<(std::ostream& lhs, const Pixel& rhs)
{
	lhs << "R: " << rhs.r << ", G: " << rhs.g << ", B: " << rhs.b;

	return lhs;
}
