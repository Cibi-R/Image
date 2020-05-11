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

	ImageProcess::ImageComputation::MedianAvg(MyImage);
}