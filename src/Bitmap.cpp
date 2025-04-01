#include "Bitmap.h"
#include <fstream>
#include <string>
#include <cstdint>
#include <memory>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace std;
using namespace caveofprogramming;

namespace caveofprogramming {
	Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height), m_pPixels(new uint8_t[width * height * 3]{}) {
		// Constructor implementation
	}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
		// setPixel implementation

		uint8_t* pPixels = m_pPixels.get();
		//pPixels += (y * 3) * m_width + (x * 3);
		 pPixels += (y * m_width + x) * 3; 

		pPixels[0] = blue;
		pPixels[1] = green;
		pPixels[2] = red;

	}

	bool Bitmap::write(string filename) {
		// write implementation
		BitmapFileHeader fileName;
		BitmapInfoHeader infoHeader;
		fileName.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3; // Total file size in bytes.
		fileName.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader); // Offset to the start of the pixel data.
		infoHeader.width = m_width; // Width of the bitmap in pixels.
		infoHeader.height = m_height; // Height of the bitmap in pixels.
		ofstream file;
		file.open(filename, ios::out | ios::binary);// Open the file in binary mode.

		if (!file) {
			return false;
		}
		file.write((char*)&fileName, sizeof(fileName));
		file.write((char*)&infoHeader, sizeof(infoHeader));
		file.write((char*)m_pPixels.get(), m_width * m_height * 3);

		file.close();
		if (!file) {
			return false;
		}

		return true;
	}

	Bitmap::~Bitmap() {
		// Destructor implementation

	}

} // namespace caveofprogramming
