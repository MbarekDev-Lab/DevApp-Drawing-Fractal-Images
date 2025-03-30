#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>  //The <cstdint> header provides fixed-width integer types like int32_t.
using namespace std;

#pragma pack(2)

namespace caveofprogramming { //namespace is used to avoid name conflicts
	struct BitmapFileHeader
	{
		char header[2]{ 'B', 'M' }; // BMP file signature ("BM" for Windows Bitmaps)
		int32_t fileSize;            // Size of the entire BMP file in bytes
		int32_t reserved{ 0 };      // Reserved field, typically set to 0
		int32_t dataOffset;          // Offset where pixel data starts

	};
}


#endif /* BITMAPFILEHEADER_H_ */