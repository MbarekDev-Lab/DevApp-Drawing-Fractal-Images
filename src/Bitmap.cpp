#include "Bitmap.h"

#include <string>
#include <cstdint>
#include <memory>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace std;
using namespace caveofprogramming;

namespace caveofprogramming {
     Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height) , m_pPixels(new uint8_t[width*height*3]{}) {
        // Constructor implementation
    }

    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
        // setPixel implementation
    }

    bool Bitmap::write(string filename) {
		// write implementation
        BitmapFileHeader fileName;
		BitmapInfoHeader infoHeader;
        fileName.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3; // Total file size in bytes.
        fileName.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader); // Offset to the start of the pixel data.
        return true;
    }

    Bitmap::~Bitmap() {
        // Destructor implementation

    }

} // namespace caveofprogramming
