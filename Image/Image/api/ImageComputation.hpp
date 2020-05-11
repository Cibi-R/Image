#ifndef __IMAGE_COMPUTATION_H__
#define __IMAGE_COMPUTATION_H__

#include "Image.hpp"

namespace ImageProcess
{
	typedef enum Image_Smoothing_EN
	{
		AVERAGE_SMOOTHING,
		MEDIAN_SMOOTHING
	}Image_Smoothing_E;

	class ImageComputation
	{
	private:
		ImageComputation(void);
	public:
		static bool MakeClone(ImageProcess::Image& Img);
		static bool SmoothImage(ImageProcess::Image& Img, std::string ImgName, Image_Smoothing_E type);
	};
}

#endif //__IMAGE_COMPUTATION_H__