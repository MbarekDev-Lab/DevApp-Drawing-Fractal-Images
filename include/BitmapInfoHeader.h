#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint> //The <cstdint> header provides fixed-width integer types like int32_t.

using namespace std;

#pragma pack(2)

namespace caveofprogramming {
	struct BitmapInfoHeader
	{
		int32_t headerSize{ 40 }; // Size of this header in bytes
		int32_t width;            // Image width in pixels
		int32_t height;           // Image height in pixels
		int16_t planes{ 1 };      // Number of color planes
		int16_t bitsPerPixel{ 24 }; // Number of bits per pixel
		int32_t compression{ 0 };  // Compression methods used
		int32_t dataSize{ 0 };     // Size of the raw bitmap data
		int32_t horizontalResolution{ 2400 }; // Horizontal resolution of the image
		int32_t verticalResolution{ 2400 };   // Vertical resolution of the image
		int32_t colors{ 0 };       // Number of colors in the palette
		int32_t importantColors{ 0 }; // Number of important colors used
	};
}

#endif /* BITMAPINFOHEADER_H_ */