#include <iostream>
#include "Image/api/Image.hpp"
#include "Image/api/ImageFile.hpp"
#include "Image/api/ImageComputation.hpp"

int main(void)
{
	ImageProcess::Image MyImage("girlface.bmp");
	std::cout << MyImage << std::endl;
	//ImageProcess::ImageComputation::MakeClone(MyImage);

	/*MyImage.Image_OpenImage("girlface.bmp");
	ImageProcess::ImageComputation::MakeClone(MyImage);
	std::cout << MyImage << std::endl;*/

	ImageProcess::ImageComputation::SmoothImage(MyImage,"1.bmp",ImageProcess::AVERAGE_SMOOTHING);

	ImageProcess::ImageComputation::SmoothImage(MyImage,"2.bmp", ImageProcess::MEDIAN_SMOOTHING);
}