#include <iostream>
#include "../api/ImageFile.hpp"


ImageProcess::ImageFile::ImageFile(std::string image_name) : File(image_name, std::ios::binary)
{

}

ImageProcess::ImageFile::~ImageFile(void)
{
	File.close();
}

bool ImageProcess::ImageFile::Is_ImageFile_Open(void)
{
	return File.is_open();
}

void ImageProcess::ImageFile::ImageFile_Read(char* data, int size)
{
	File.read(data, size);
}
