#ifndef __IMAGE_COMPUTATION_H__
#define __IMAGE_COMPUTATION_H__

#include "Image.hpp"

namespace ImageProcess
{
	class ImageComputation
	{
	private:
		ImageComputation(void);
	public:
		static bool MakeClone(ImageProcess::Image& Img);
		static bool SmoothAvg(ImageProcess::Image& Img);
		static bool MedianAvg(ImageProcess::Image& Img);
	};
}

#endif //__IMAGE_COMPUTATION_H__