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

	Image_Data = new char[Image_Width * Image_Height];

	ImageFile_Read(Image_Data, (Image_Width * Image_Height));
}

unsigned char ImageProcess::Image::Image_MakeCopy(std::string imagename)
{
	std::ofstream ImageOut(imagename,std::ios::binary);

	ImageOut.write(Image_Header, 54);
	
	if (8 <= Image_ColorDepth)
	{
		ImageOut.write(Image_ColorTable, 1024);
	}

	ImageOut.write(Image_Data, (Image_Width * Image_Height));
	ImageOut.close();

	std::cout << Image_Height << "-" << Image_Width << "-" << Image_ColorDepth << "-" << Is_ImageFile_Open() << std::endl;

	return 1;
}

std::ostream& ImageProcess::operator<<(std::ostream& out, ImageProcess::Image &MyImage)
{
	out << "Image Name : " << MyImage.Image_Name << " Image Width : " << MyImage.Image_Width <<
		" Image Height : " << MyImage.Image_Height << " Image Color Depth : " << MyImage.Image_ColorDepth;

	return out;
}
