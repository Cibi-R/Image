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
		ImageFile(std::string image_name);
		~ImageFile(void);
		bool Is_ImageFile_Open(void);
		void ImageFile_Read(char* data, int size);
	};
}

#endif //__IMAGE_FILE_H__
