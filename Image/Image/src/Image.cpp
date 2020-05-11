#include <iostream>
#include <string>
#include "../api/Image.hpp"


ImageProcess::Image::Image(std::string imagename) : Image_Name(imagename), ImageFile(imagename)
{
	Image_Init();
}

ImageProcess::Image::~Image(void)
{
	delete Image_Data;
}

void ImageProcess::Image::Image_Init(void)
{
	ImageFile_Read(Image_Header,54);

	Image_Width      = *((int*)(&Image_Header[18]));
	Image_Height     = *((int*)(&Image_Header[22]));
	Image_ColorDepth = *((int*)(&Image_Header[28]));

	if (8 <= Image_ColorDepth)
	{
		ImageFile_Read(Image_ColorTable,1024);
	}
	else
	{
		/* m_ColorTable Initial Value is 0 */
	}

	Image_Data = new char[Image_Width * Image_Height * (Image_ColorDepth / 8)];

	ImageFile_Read(Image_Data, (Image_Width * Image_Height * (Image_ColorDepth / 8)));
}

void ImageProcess::Image::Image_ClearData(void)
{
	Image_Width = 0;
	Image_Height = 0;
	Image_ColorDepth = 0;

	memset(Image_ColorTable, 0, 1024);

	delete Image_Data;
}


void ImageProcess::Image::Image_OpenImage(std::string image_name)
{
	Image_Name = image_name;
	ImageFile_Open(image_name);
	Image_ClearData();
	Image_Init();
}

std::ostream& ImageProcess::operator<<(std::ostream& out, ImageProcess::Image &my_image)
{
	out << "Image Name : " << my_image.Image_Name << " -- Image Width : " << my_image.Image_Width <<
		" -- Image Height : " << my_image.Image_Height << " -- Image Color Depth : " << my_image.Image_ColorDepth;

	return out;
}
