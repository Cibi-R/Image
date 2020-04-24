#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <fstream>
#include <iostream>
#include <string>
#include "ImageFile.hpp"

namespace ImageProcess
{
	class Image : public ImageFile
	{
	private:
		std::string Image_Name;         
		int   Image_Width;
		int   Image_Height;
		int   Image_ColorDepth;
		char  Image_Header[54];
		char  Image_ColorTable[1024] = {0};
		char* Image_Data;

		void Image_Init(void);

	public:
		Image(std::string ImageName);
		~Image();
		unsigned char Image_MakeCopy(std::string imagename);
		friend std::ostream& operator << (std::ostream& out, ImageProcess::Image &MyImage);
	};
}

#endif //__IMAGE_H__