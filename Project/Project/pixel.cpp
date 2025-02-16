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

int ImageSoundData::setRedScatter(Pixel img[], int size)
{

	if (redPixels == 0) return 0;

	int distanceSum = 0;
	int distance = 0;
	int first = 1;

	for (int i = 0; i < size; i++)
	{
		if (img[i].r > img[i].b && img[i].r > img[i].g) {
			if(first) first = 0;
			distanceSum += distance;
		}
		else if (!first)
		{
			distance++;
		}
	}

	redScatter = distanceSum / redPixels;

	return 1;
}

int ImageSoundData::setGreenScatter(Pixel img[], int size)
{
	if (greenPixels == 0) return 0;

	int distanceSum = 0;
	int distance = 0;
	int first = 1;

	for (int i = 0; i < size; i++)
	{
		if (img[i].g > img[i].r && img[i].g > img[i].b) {
			if (first) first = 0;
			distanceSum += distance;
		}
		else if (!first)
		{
			distance++;
		}
	}

	greenScatter = distanceSum / greenPixels;

	return 1;
}

int ImageSoundData::setBlueScatter(Pixel img[], int size)
{
	if (bluePixels == 0) return 0;

	int distanceSum = 0;
	int distance = 0;
	int first = 1;

	for (int i = 0; i < size; i++)
	{
		if (img[i].b > img[i].g && img[i].b > img[i].r) {
			if (first) first = 0;
			distanceSum += distance;
		}
		else if (!first)
		{
			distance++;
		}
	}

	blueScatter = distanceSum / bluePixels;

	return 1;
}

void ImageSoundData::setAvgBrightness(Pixel img[], int size)
{
	double sum = 0.0;

	for (int i = 0; i < size; i++)
	{
		sum += img[i].brightness;
	}

	avgBrightness = sum / size;
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
	return redScatter;
}

double ImageSoundData::getGreenScatter(void)
{
	return greenScatter;
}

double ImageSoundData::getBlueScatter(void)
{
	return blueScatter;
}

double ImageSoundData::getAvgBrightness(void)
{
	return avgBrightness;
}

void ImageSoundData::playImageSound(Pixel img[], int size)
{
	int length = 0;

	//Set the length based off image size

	if (size < 32 * 32) length = 20;
	else if (size < 64 * 64) length = 50;
	else if (size < 128 * 128) length = 100;
	else if (size < 512 * 512) length = 200;
	else length = 300;

	//Play a sound based off high red/green/blue scatter, high brightness, and highest individual pixel color
	for (int i = 0; i < length; i++)
	{
		if (redScatter > greenScatter && redScatter > blueScatter)
		{
			if (avgBrightness > 0.5)
			{
				if (img[i * length].r > img[i * length].g && img[i * length].r > img[i * length].b)
				{
					playSound(3);
				}
				else if (img[i * length].g > img[i * length].r && img[i * length].g > img[i * length].b)
				{
					playSound(4);
				}
				else
				{
					playSound(5);
				}
			}
			else
			{
				if (img[i * length].r > img[i * length].g && img[i * length].r > img[i * length].b)
				{
					playSound(7);
				}
				else if (img[i * length].g > img[i * length].r && img[i * length].g > img[i * length].b)
				{
					playSound(8);
				}
				else
				{
					playSound(1);
				}
			}
		}
		else if (greenScatter > redScatter && greenScatter > blueScatter)
		{
			if (avgBrightness > 0.5)
			{
				if (img[i * length].r > img[i * length].g && img[i * length].r > img[i * length].b)
				{
					playSound(2);
				}
				else if (img[i * length].g > img[i * length].r && img[i * length].g > img[i * length].b)
				{
					playSound(1);
				}
				else
				{
					playSound(5);
				}
			}
			else
			{
				if (img[i * length].r > img[i * length].g && img[i * length].r > img[i * length].b)
				{
					playSound(6);
				}
				else if (img[i * length].g > img[i * length].r && img[i * length].g > img[i * length].b)
				{
					playSound(3);
				}
				else
				{
					playSound(4);
				}
			}
		}
		else
		{
			if (avgBrightness > 0.5)
			{
				if (img[i * length].r > img[i * length].g && img[i * length].r > img[i * length].b)
				{
					playSound(5);
				}
				else if (img[i * length].g > img[i * length].r && img[i * length].g > img[i * length].b)
				{
					playSound(6);
				}
				else
				{
					playSound(7);
				}
			}
			else
			{
				if (img[i * length].r > img[i * length].g && img[i * length].r > img[i * length].b)
				{
					playSound(1);
				}
				else if (img[i * length].g > img[i * length].r && img[i * length].g > img[i * length].b)
				{
					playSound(4);
				}
				else
				{
					playSound(3);
				}
			}
		}
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
void playSound(int sound)
{
	switch (sound) {
	case 1:
		PlaySound(TEXT("Note_block_guitar.wav"), NULL, SND_FILENAME);
		break;
	case 2:
		PlaySound(TEXT("Note_block_iron_xylophone.wav"), NULL, SND_FILENAME);
		break;
	case 3:
		PlaySound(TEXT("Note_block_banjo.wav"), NULL, SND_FILENAME);
		break;
	case 4:
		PlaySound(TEXT("Note_block_bassattack.wav"), NULL, SND_FILENAME);
		break;
	case 5:
		PlaySound(TEXT("Note_block_cow_bell.wav"), NULL, SND_FILENAME);
		break;
	case 6:
		PlaySound(TEXT("Note_block_didgeridoo.wav"), NULL, SND_FILENAME);
		break;
	case 7:
		PlaySound(TEXT("Note_block_flute.wav"), NULL, SND_FILENAME);
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