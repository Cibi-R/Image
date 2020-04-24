#include <iostream>
#include "Image/api/Image.hpp"
#include "Image/api/ImageFile.hpp"

int main(void)
{
	ImageProcess::Image MyImage("girlface.bmp");
	std::cout << MyImage << std::endl;
}