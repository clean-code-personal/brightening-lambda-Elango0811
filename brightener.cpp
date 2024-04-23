#include "brightener.h"

ImageBrightener::ImageBrightener(std::shared_ptr<Image> inputImage) : m_inputImage(inputImage) {
}

int ImageBrightener::BrightenWholeImage() const
{
	int attenuatedPixelCount = 0;

	// Procedure to brighten the given individual pixel data
	auto brightingProc = [&attenuatedPixelCount](uint8_t pixelGrayscale) {
		uint8_t outputGrayscale = pixelGrayscale;
		if (outputGrayscale > (255 - 25)) {
			++attenuatedPixelCount;
			outputGrayscale = 255;
		}
		else {
			outputGrayscale += 25;
		}

		return outputGrayscale;
	};

	m_inputImage->pixelRunner(brightingProc);
	return attenuatedPixelCount;
}

