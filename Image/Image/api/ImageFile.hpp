#ifndef __IMAGE_FILE_H__
#define __IMAGE_FILE_H__

#include <fstream>

namespace ImageProcess
{
	class ImageFile
	{
	private:
		std::ifstream File;
	public:
		ImageFile(void) = default;
		ImageFile(std::string image_name);
		~ImageFile(void);
		bool Is_ImageFile_Open(void);
		void ImageFile_Read(char* data, int size);
		void ImageFile_Open(std::string image_name);
		void ImageFile_Close(void);
	};
}

#endif //__IMAGE_FILE_H__
