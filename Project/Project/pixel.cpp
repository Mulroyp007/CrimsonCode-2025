#include "pixel.hpp"

ImageSoundData::ImageSoundData(Pixel img[])
{

}

int ImageSoundData::setRedPixels(Pixel img[])
{

	return 0;
}

int ImageSoundData::setGreenPixels(Pixel img[])
{
	return 0;
}

int ImageSoundData::setBluePixels(Pixel img[])
{
	return 0;
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

int ImageSoundData::getRedPixels(void)
{
	
	return this->redPixels;
}

int ImageSoundData::getGreenPixels(void)
{
	return this->greenPixels;
}

int ImageSoundData::getbluePixles(void)
{
	return this->bluePixels;
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

void ImageSoundData::playImageSound(void)
{

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
		PlaySound(TEXT("Note_block_guitar.ogg.wav"), NULL, SND_FILENAME);
	case 2:
		PlaySound(TEXT("Note_block_iron_xylophone.ogg.wav"), NULL, SND_FILENAME);
	case 3:
		PlaySound(TEXT("Note_block_banjo.ogg.wav"), NULL, SND_FILENAME);
	case 4:
		PlaySound(TEXT("Note_block_bassattack.ogg.wav"), NULL, SND_FILENAME);
	case 5:
		PlaySound(TEXT("Note_block_cow_bell.ogg.wav"), NULL, SND_FILENAME);
	case 6:
		PlaySound(TEXT("Note_block_didgeridoo.ogg.wav"), NULL, SND_FILENAME);
	case 7:
		PlaySound(TEXT("Note_block_flute.ogg.wav"), NULL, SND_FILENAME);
	case 8:
		PlaySound(TEXT("Note_block_snare.ogg.wav"), NULL, SND_FILENAME);
	}
}

std::ostream& operator<<(std::ostream& lhs, Pixel& rhs)
{
	lhs << "R: " << rhs.r << ", G: " << rhs.g << ", B: " << rhs.b;

	return lhs;
}
