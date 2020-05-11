#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <fstream>
#include <iostream>
#include <string>
#include "ImageFile.hpp"

namespace ImageProcess
{
	class Image : private ImageFile
	{
	private:
		friend class ImageComputation;   /*< Made as friend to access the private members while computing the photo */

		std::string Image_Name;         
		int   Image_Width;
		int   Image_Height;
		int   Image_ColorDepth;
		char  Image_Header[54];
		char  Image_ColorTable[1024] = {0};
		char* Image_Data;

		void Image_Init(void);
		void Image_ClearData(void);
	public:
		Image(void) = default;
		Image(std::string image_name);
		~Image();
		void Image_OpenImage(std::string image_name);
		friend std::ostream& operator << (std::ostream& out, ImageProcess::Image &my_image);
	};
}

#endif //__IMAGE_H__