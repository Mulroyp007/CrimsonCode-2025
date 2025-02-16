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
	return 0;
}

int ImageSoundData::getGreenPixels(void)
{
	return 0;
}

int ImageSoundData::getbluePixles(void)
{
	return 0;
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
